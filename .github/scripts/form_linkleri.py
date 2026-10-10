#!/usr/bin/env python3
"""README'lerdeki Google Form bölümlerini üretir (tekrar çalıştırılabilir).

- Ders kartları/sayfaları:
  "⭐ Yıldız Sayıları"   -> Ders Özellikleri Oylama sonuçları + oylama linki (ders önceden seçili)
  "💬 Öğrenci Görüşleri" -> onaylanmış ders yorumları + yorum linki (ders önceden seçili)
- Hoca kartları: "💬 Öğrenci Görüşleri" -> onaylanmış hoca yorumları + yorum linki.
  Hoca oylama formu olmadığı için hoca kartlarındaki yıldız satırı kaldırılır.
- Ana README'nin başındaki "Geri Bildirimde Bulunun" linkleri.

Yorumlar SADECE cevap tablosundaki "Onay" sütunu işaretliyse yayınlanır.
Form adresleri, soru kimlikleri ve CSV linkleri: json_dosyalari/konfigurasyon.json.
Test için FORM_CSV_DIZIN ortam değişkeniyle yerel CSV klasörü verilebilir
(hoca_yorumlama.csv, ders_yorumlama.csv, ders_oylama.csv).
Sadece Python standart kütüphanesi kullanılır.
"""
import csv
import io
import json
import os
import re
import subprocess
import sys
import urllib.parse
import urllib.request

KONF = "json_dosyalari/konfigurasyon.json"
DONEMLER = ["1-1", "1-2", "2-1", "2-2", "3-1", "3-2", "4-1", "4-2"]
HAVUZLAR = ["Mesleki Seçmeli", "Fakülte Teknik Seçmeli", "Üniversite Seçmeli"]
OZETTE_YORUM = 2          # ana sayfa ve dönem sayfasında gösterilen yorum sayısı
YORUM_UZUNLUK = 1500
ONAY_DEGERLERI = {"true", "doğru", "dogru", "evet", "x", "✓", "✔", "1", "onay", "onaylandı"}

YILDIZ = re.compile(r"^( *)- ⭐ \*\*Yıldız Sayıları:\*\*$", re.M)
GORUS = re.compile(r"^( *)- 💬 \*\*Öğrenci Görüşleri:\*\*$", re.M)


# ---------------------------------------------------------------- veri

def csv_oku(f, anahtar):
    dizin = os.environ.get("FORM_CSV_DIZIN")
    if dizin:
        with open(os.path.join(dizin, anahtar + ".csv"), encoding="utf-8") as d:
            return list(csv.DictReader(d))
    adres = f.get(anahtar + "_csv")
    if not adres:
        return []
    with urllib.request.urlopen(adres, timeout=60) as y:
        return list(csv.DictReader(io.StringIO(y.read().decode("utf-8"))))


def onayli(satir):
    for k, v in satir.items():
        if k and k.strip().lower() == "onay":
            return (v or "").strip().lower() in ONAY_DEGERLERI
    return False


def ay_yil(zaman):
    m = re.match(r"(\d{1,2})([/.])(\d{1,2})\2(\d{4})", (zaman or "").strip())
    if not m:
        return ""
    a, ayrac, b, yil = m.groups()
    ay = a if ayrac == "/" else b  # "/" -> ABD biçimi (A/G/Y), "." -> G.A.Y
    return f"{int(ay):02d}.{yil}"


def temiz(metin, uzunluk):
    metin = re.sub(r"\s+", " ", metin or "").strip()[:uzunluk]
    metin = metin.replace("<", "&lt;").replace(">", "&gt;")
    return re.sub(r"([\[\]`*_|\\])", r"\\\1", metin)


def veri_topla(f):
    oylar, ders_yorum, hoca_yorum = {}, {}, {}
    for s in csv_oku(f, "ders_oylama"):
        try:
            oylar.setdefault(s["Ders Seç"].strip(), []).append(
                (int(s["Dersi geçmek ne kadar kolay?"]), int(s["Ders mesleki açıdan gerekli mi?"])))
        except (KeyError, ValueError):
            continue
    for anahtar, hedef, alan, yorum_alani in [
            ("ders_yorumlama", ders_yorum, "Ders Seç", "Ders hakkındaki yorumun"),
            ("hoca_yorumlama", hoca_yorum, "Hoca seç", "Hoca hakkındaki yorumun")]:
        for s in csv_oku(f, anahtar):
            if not onayli(s) or not (s.get(yorum_alani) or "").strip():
                continue
            hedef.setdefault(s[alan].strip(), []).append(
                (temiz(s.get("İsmin nasıl gözüksün") or "Anonim", 40),
                 temiz(s[yorum_alani], YORUM_UZUNLUK), ay_yil(s.get("Timestamp") or s.get("Zaman damgası"))))
    for d in (ders_yorum, hoca_yorum):  # en yeni yorum üstte
        for k in d:
            d[k].reverse()
    return oylar, ders_yorum, hoca_yorum


# ---------------------------------------------------------------- çizim

def url(form, alan=None, deger=None):
    u = form["link"]
    if alan and deger:
        u += "?usp=pp_url&entry." + form[alan] + "=" + urllib.parse.quote(deger)
    return u


def yildiz(ort):
    n = max(0, min(10, round(ort)))
    return "★" * n + "☆" * (10 - n)


def blok_sonu(metin, m):
    """Başlık eşleşmesinden sonra, başlıktan daha içeride olan satırların bittiği konum."""
    girinti = len(m.group(1))
    son = m.end() + 1
    while son < len(metin):
        satir_sonu = metin.find("\n", son)
        satir = metin[son:satir_sonu if satir_sonu >= 0 else len(metin)]
        if satir.strip() == "" or len(satir) - len(satir.lstrip(" ")) <= girinti:
            break
        son = (satir_sonu + 1) if satir_sonu >= 0 else len(metin)
    return son


def blok_degistir(metin, desen, yeni_satirlar):
    """Başlık satırını ve ondan daha içeride olan alt satırlarını yenileriyle değiştirir."""
    m = desen.search(metin)
    if not m:
        return metin, False
    girinti = len(m.group(1))
    son = blok_sonu(metin, m)
    alt = metin[m.end() + 1:son]
    ic = " " * girinti + "    "
    ilk_alt = re.match(r"( +)- ", alt)
    if ilk_alt:
        ic = ilk_alt.group(1)
    govde = "".join(f"{ic}{s}\n" for s in yeni_satirlar)
    return metin[:m.start()] + m.group(0) + "\n" + govde + metin[son:], True


def yildiz_satirlari(ders, oylar, f):
    link = url(f["ders_oylama"], "ders_alani", ders)
    o = oylar.get(ders)
    if not o:
        return [f"- ℹ️ Henüz yıldız veren yok. Siz de [linkten]({link}) anonim şekilde oylamaya katılabilirsiniz."]
    kolay = sum(a for a, _ in o) / len(o)
    gerekli = sum(b for _, b in o) / len(o)
    return [f"- ✅ Dersi Kolay Geçer Miyim: {yildiz(kolay)}",
            f"- 🎯 Ders Mesleki Açıdan Gerekli Mi: {yildiz(gerekli)}",
            f"  - ℹ️ Yıldızlar {len(o)} oy üzerinden hesaplanmıştır. Siz de [linkten]({link}) "
            "anonim şekilde oylamaya katılabilirsiniz."]


def gorus_satirlari(yorumlar, link, sinir=None, devam_notu=""):
    if not yorumlar:
        return [f"- ℹ️ Henüz yorum yok. Siz de [linkten]({link}) anonim şekilde görüşlerinizi belirtebilirsiniz."]
    gosterilen = yorumlar if sinir is None else yorumlar[:sinir]
    satirlar = [f"- 👤 **_{isim}_**: {yorum}" + (f" ℹ️ Yorum **{tarih}** tarihinde yapılmıştır." if tarih else "")
                for isim, yorum, tarih in gosterilen]
    if len(yorumlar) > len(gosterilen):
        satirlar.append(f"- ℹ️ Diğer {len(yorumlar) - len(gosterilen)} yoruma {devam_notu} erişebilirsiniz.")
    satirlar.append(f"  - ℹ️ Siz de [linkten]({link}) anonim şekilde görüşlerinizi belirtebilirsiniz.")
    return satirlar


def ders_blogu(metin, ders, veri, f, ozet):
    oylar, ders_yorum, _ = veri
    metin, _ = blok_degistir(metin, YILDIZ, yildiz_satirlari(ders, oylar, f))
    m = YILDIZ.search(metin)
    if m and not GORUS.search(metin):  # görüş bölümü yoksa yıldız bloğunun hemen altına aç
        i = blok_sonu(metin, m)
        metin = metin[:i] + f"{m.group(1)}- 💬 **Öğrenci Görüşleri:**\n{m.group(1)}    - .\n" + metin[i:]
    link = url(f["ders_yorumlama"], "ders_alani", ders)
    satirlar = gorus_satirlari(ders_yorum.get(ders, []), link,
                               OZETTE_YORUM if ozet else None, "dersin kendi klasöründen")
    metin, _ = blok_degistir(metin, GORUS, satirlar)
    return metin


def hoca_blogu(metin, hoca, aktif, veri, f):
    metin = re.sub(r"^( *)- ⭐ \*\*Yıldız Sayıları:\*\*\n(?:\1 +.*\n)*", "", metin, flags=re.M)
    if aktif:
        link = url(f["hoca_yorumlama"], "hoca_alani", hoca)
        satirlar = gorus_satirlari(veri[2].get(hoca, []), link)
    else:
        satirlar = ["- ℹ️ Son iki akademik yılda bölümde dersi görünmediği için yorum formunda yer almıyor."]
    metin, _ = blok_degistir(metin, GORUS, satirlar)
    return metin


def bloklara_bol(t, desen):
    """Metni [(None, baştaki metin), (başlık eşleşmesi, başlıktan sonrakine kadar metin), ...] olarak böler."""
    bas = list(re.finditer(desen, t, flags=re.M))
    if not bas:
        return [(None, t)]
    sonuc = [(None, t[:bas[0].start()])]
    for j, m in enumerate(bas):
        bitis = bas[j + 1].start() if j + 1 < len(bas) else len(t)
        sonuc.append((m, t[m.start():bitis]))
    return sonuc


def ust_linkler(t, f):
    t = re.sub(r"- \[✍️ \*\*Hocalar için yorum linki\*\*\]\([^)]*\)",
               f"- [✍️ **Hocalar için yorum linki**]({url(f['hoca_yorumlama'])})", t)
    t = re.sub(r"- \[⭐ \*\*Hocalar için yıldız linki\*\*\]\([^)]*\)\n", "", t)
    t = re.sub(r"- \[✍️ \*\*Dersler için yorum linki\*\*\]\([^)]*\)",
               f"- [✍️ **Dersler için yorum linki**]({url(f['ders_yorumlama'])})", t)
    t = re.sub(r"- \[⭐ \*\*Dersler için (?:yıldız|oylama) linki\*\*\]\([^)]*\)",
               f"- [⭐ **Dersler için oylama linki**]({url(f['ders_oylama'])})", t)
    return t


def main():
    konf = json.load(open(KONF, encoding="utf-8"))
    f = konf["formlar"]
    try:
        veri = veri_topla(f)
    except Exception as e:  # CSV'ler okunamazsa mevcut README'lere dokunma
        print("⚠️ Form cevapları okunamadı, README'ler değiştirilmedi:", e)
        sys.exit(0)
    hocalar = {h["ad"]: h.get("hoca_aktif_gorevde_mi", True) is not False
               for h in json.load(open("json_dosyalari/hocalar.json", encoding="utf-8"))["hocalar"]}
    dosyalar = subprocess.run(["git", "-c", "core.quotepath=off", "ls-files", "*README.md"],
                              capture_output=True, text=True, check=True).stdout.split("\n")
    degisen = 0
    for yol in filter(None, dosyalar):
        t = open(yol, encoding="utf-8").read()
        parca = yol.split("/")
        if len(parca) == 3 and parca[0] in DONEMLER + HAVUZLAR:  # ders sayfası: tüm yorumlar
            yeni = ders_blogu(t, parca[1], veri, f, ozet=False)
        elif len(parca) == 2 and parca[0] in DONEMLER:  # dönem sayfası: "### 📘 Ders" blokları
            yeni = "".join(ders_blogu(b, m.group(1).strip(), veri, f, ozet=True) if m else b
                           for m, b in bloklara_bol(t, r"^### 📘 (.+?)\s*$"))
        elif yol == "README.md":
            parcalar = []
            for m, b in bloklara_bol(t, r"^#### (\S+) (.+?) $"):
                if m and m.group(1) == "📘":
                    km = re.search(r"📂 \[Ders Klasörü\]\(\./([^)]*)\)", b)
                    ders = urllib.parse.unquote(km.group(1)).split("/", 1)[1] if km else m.group(2)
                    b = ders_blogu(b, ders, veri, f, ozet=True)
                elif m and m.group(2) in hocalar:
                    b = hoca_blogu(b, m.group(2), hocalar[m.group(2)], veri, f)
                parcalar.append(b)
            yeni = ust_linkler("".join(parcalar), f)
        else:
            continue
        if yeni != t:
            open(yol, "w", encoding="utf-8").write(yeni)
            degisen += 1
    oy, dy, hy = veri
    print(f"güncellenen README: {degisen} | oylanan ders: {len(oy)} | onaylı ders yorumu: "
          f"{sum(map(len, dy.values()))} | onaylı hoca yorumu: {sum(map(len, hy.values()))}")


if __name__ == "__main__":
    main()
