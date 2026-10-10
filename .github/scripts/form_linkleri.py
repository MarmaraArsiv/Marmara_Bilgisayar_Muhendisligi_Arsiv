#!/usr/bin/env python3
"""README'lerdeki Google Form linklerini doldurur (tekrar çalıştırılabilir).

- Ders kartları/sayfaları: "Yıldız Sayıları" altındaki link -> Ders Özellikleri Oylama formu,
  "Öğrenci Görüşleri" -> Ders Yorumlama formu. İkisi de ders önceden seçili açılır.
- Hoca kartları: "Öğrenci Görüşleri" -> Hoca Yorumlama formu (hoca önceden seçili).
  Hoca oylama formu olmadığı için hoca kartlarındaki yıldız satırı kaldırılır.
- Ana README'nin başındaki "Geri Bildirimde Bulunun" linkleri.
Form adresleri ve soru kimlikleri: json_dosyalari/konfigurasyon.json -> "formlar".
Sadece Python standart kütüphanesi kullanılır.
"""
import json
import os
import re
import subprocess
import urllib.parse

KONF = "json_dosyalari/konfigurasyon.json"
DONEMLER = ["1-1", "1-2", "2-1", "2-2", "3-1", "3-2", "4-1", "4-2"]
HAVUZLAR = ["Mesleki Seçmeli", "Fakülte Teknik Seçmeli", "Üniversite Seçmeli"]

OYLA = re.compile(r"(- ℹ️ Henüz yıldız veren yok\. Siz de )\[linkten\]\([^)]*\)( anonim şekilde oylamaya katılabilirsiniz\.)")
GORUS = re.compile(r"(- ℹ️ (?:Henüz yorum yok\. )?Siz de )\[linkten\]\([^)]*\)( anonim şekilde görüşlerinizi belirtebilirsiniz\.)")
YILDIZ_BASLIK = re.compile(r"^(\s*)- ⭐ \*\*Yıldız Sayıları:\*\*\n(\s*)- ℹ️ Henüz yıldız veren yok\..*\n", re.M)


def url(form, alan=None, deger=None):
    u = form["link"]
    if alan and deger:
        u += "?usp=pp_url&entry." + form[alan] + "=" + urllib.parse.quote(deger)
    return u


def ders_blogu(metin, ders, f):
    """Bir ders bloğundaki oylama linkini doldurur ve altına görüş satırını ekler."""
    oy = url(f["ders_oylama"], "ders_alani", ders)
    yorum = url(f["ders_yorumlama"], "ders_alani", ders)
    metin = OYLA.sub(lambda m: f"{m.group(1)}[linkten]({oy}){m.group(2)}", metin)
    if "Öğrenci Görüşleri" in metin:
        return GORUS.sub(lambda m: f"{m.group(1)}[linkten]({yorum}){m.group(2)}", metin)

    def ekle(m):
        girinti, alt = m.group(1), m.group(2)
        return (m.group(0) + f"{girinti}- 💬 **Öğrenci Görüşleri:**\n"
                f"{alt}- ℹ️ Henüz yorum yok. Siz de [linkten]({yorum}) anonim şekilde görüşlerinizi belirtebilirsiniz.\n")
    return YILDIZ_BASLIK.sub(ekle, metin, count=1)


def hoca_blogu(metin, hoca, aktif, f):
    metin = YILDIZ_BASLIK.sub("", metin)  # hoca oylaması yok
    if aktif:
        yorum = url(f["hoca_yorumlama"], "hoca_alani", hoca)
        return GORUS.sub(lambda m: f"{m.group(1)}[linkten]({yorum}){m.group(2)}", metin)
    return GORUS.sub("- ℹ️ Son iki akademik yılda bölümde dersi görünmediği için yorum formunda yer almıyor.", metin)


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


def main():
    f = json.load(open(KONF, encoding="utf-8"))["formlar"]
    hocalar = {h["ad"]: h.get("hoca_aktif_gorevde_mi", True) is not False
               for h in json.load(open("json_dosyalari/hocalar.json", encoding="utf-8"))["hocalar"]}
    dosyalar = subprocess.run(["git", "-c", "core.quotepath=off", "ls-files", "*README.md"],
                              capture_output=True, text=True, check=True).stdout.split("\n")
    degisen = 0
    for yol in filter(None, dosyalar):
        t = open(yol, encoding="utf-8").read()
        parca = yol.split("/")
        if len(parca) == 3 and parca[0] in DONEMLER + HAVUZLAR:  # ders sayfası
            yeni = ders_blogu(t, parca[1], f)
        elif len(parca) == 2 and parca[0] in DONEMLER:  # dönem sayfası: "### 📘 Ders" blokları
            yeni = "".join(ders_blogu(b, m.group(1).strip(), f) if m else b
                           for m, b in bloklara_bol(t, r"^### 📘 (.+?)\s*$"))
        elif yol == "README.md":
            parcalar = []
            for m, b in bloklara_bol(t, r"^#### (\S+) (.+?) $"):
                if m and m.group(1) == "📘":
                    km = re.search(r"📂 \[Ders Klasörü\]\(\./([^)]*)\)", b)
                    ders = urllib.parse.unquote(km.group(1)).split("/", 1)[1] if km else m.group(2)
                    b = ders_blogu(b, ders, f)
                elif m and m.group(2) in hocalar:
                    b = hoca_blogu(b, m.group(2), hocalar[m.group(2)], f)
                parcalar.append(b)
            yeni = "".join(parcalar)
            yeni = re.sub(r"- \[✍️ \*\*Hocalar için yorum linki\*\*\]\([^)]*\)",
                          f"- [✍️ **Hocalar için yorum linki**]({url(f['hoca_yorumlama'])})", yeni)
            yeni = re.sub(r"- \[⭐ \*\*Hocalar için yıldız linki\*\*\]\([^)]*\)\n", "", yeni)
            yeni = re.sub(r"- \[✍️ \*\*Dersler için yorum linki\*\*\]\([^)]*\)",
                          f"- [✍️ **Dersler için yorum linki**]({url(f['ders_yorumlama'])})", yeni)
            yeni = re.sub(r"- \[⭐ \*\*Dersler için yıldız linki\*\*\]\([^)]*\)",
                          f"- [⭐ **Dersler için oylama linki**]({url(f['ders_oylama'])})", yeni)
            yeni = re.sub(r"- \[⭐ \*\*Dersler için oylama linki\*\*\]\([^)]*\)",
                          f"- [⭐ **Dersler için oylama linki**]({url(f['ders_oylama'])})", yeni)
        else:
            continue
        if yeni != t:
            open(yol, "w", encoding="utf-8").write(yeni)
            degisen += 1
    print("güncellenen README:", degisen)


if __name__ == "__main__":
    main()
