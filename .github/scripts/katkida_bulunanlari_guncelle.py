#!/usr/bin/env python3
"""Merge edilmiş PR'lardan katkıda bulunanları toplayıp
json_dosyalari/katkida_bulunanlar.json ve README.md'yi günceller.

- Merge edilmiş PR'ı olan her GitHub kullanıcısı listeye eklenir.
- Seviye (h1/h2/h3), kişinin merge edilmiş PR'larındaki toplam commit sayısına göre belirlenir.
- GitHub linki her zaman, LinkedIn linki kişinin GitHub profilinde ekliyse eklenir.
- Elle yazılmış ad ve iletişim bilgileri ezilmez; PR'ı olmayan kişilere dokunulmaz.

README çıktısı, Readme Oluşturucu'daki (Java) KatkidaBulunanlarWriter ile aynıdır;
tek fark isimlerin üstündeki GitHub profil fotoğraflarıdır.
Sadece Python standart kütüphanesi kullanılır.
"""
import json
import os
import re
import sys
import urllib.parse
import urllib.request

# --- Ayarlar --------------------------------------------------------------

# Toplam commit sayısı -> seviye (büyükten küçüğe kontrol edilir).
SEVIYE_ESIKLERI = [
    (10, "Çok"),       # h1
    (5, "Orta Üst"),   # h2
    (1, "Orta"),       # h3
]

# Seviyesi otomatik değiştirilmeyecek kişiler (repo sahibi vb.), küçük harfle.
SABIT_SEVIYELI = {"yldzemin"}

# Java tarafındaki Sabitler.KATKIDA_BULUNMA_ORANI_DIZI / KATKIDA_EMOJILER ile aynı olmalı.
ORAN_DIZI = ["Çok", "Orta Üst", "Orta", "Orta Alt", "Az", "Çok Az"]
EMOJILER = ["⭐", "🌟", "💫", "✨", "🔹", ""]

# Profil fotoğrafı genişliği (px), seviyeye göre: h1, h2, h3, ...
# Not: Java README aracının KatkidaBulunanlarWriter'ı fotoğraf basmıyor; o araç devreye girince ona da eklenmeli.
AVATAR_BOYUTLARI = [100, 80, 64, 56, 48, 40]

JSON_YOLU = "json_dosyalari/katkida_bulunanlar.json"
README_YOLU = "README.md"

# --------------------------------------------------------------------------

API = "https://api.github.com"
REPO = os.environ.get("GITHUB_REPOSITORY", "MarmaraArsiv/Marmara_Bilgisayar_Muhendisligi_Arsiv")
TOKEN = os.environ.get("GITHUB_TOKEN", "")


def api_get(yol):
    istek = urllib.request.Request(API + yol, headers={
        "Accept": "application/vnd.github+json",
        "X-GitHub-Api-Version": "2022-11-28",
        **({"Authorization": f"Bearer {TOKEN}"} if TOKEN else {}),
    })
    with urllib.request.urlopen(istek, timeout=30) as yanit:
        return json.load(yanit)


def merge_edilmis_prlar():
    sayfa = 1
    while True:
        prlar = api_get(f"/repos/{REPO}/pulls?state=closed&per_page=100&page={sayfa}")
        if not prlar:
            return
        for pr in prlar:
            if pr.get("merged_at") and pr["user"]["type"] != "Bot":
                yield pr
        sayfa += 1


def katki_istatistikleri():
    """{login_kucuk: {"login", "commit", "git_adi"}} döndürür."""
    sonuc = {}
    for pr in merge_edilmis_prlar():
        login = pr["user"]["login"]
        kayit = sonuc.setdefault(login.lower(), {"login": login, "commit": 0, "git_adi": ""})
        kayit["commit"] += api_get(f"/repos/{REPO}/pulls/{pr['number']}")["commits"]
        if not kayit["git_adi"]:
            for c in api_get(f"/repos/{REPO}/pulls/{pr['number']}/commits?per_page=100"):
                if (c.get("author") or {}).get("login", "").lower() == login.lower():
                    kayit["git_adi"] = c["commit"]["author"]["name"].strip()
                    break
    return sonuc


def seviye(commit_sayisi):
    for esik, oran in SEVIYE_ESIKLERI:
        if commit_sayisi >= esik:
            return oran
    return SEVIYE_ESIKLERI[-1][1]


def github_login(kisi):
    m = re.match(r"https?://github\.com/([^/?#]+)", kisi.get("github_link", ""))
    return m.group(1).lower() if m else None


def linkedin_linki(login):
    try:
        for hesap in api_get(f"/users/{login}/social_accounts"):
            if hesap.get("provider") == "linkedin":
                return hesap["url"]
    except Exception as e:  # LinkedIn opsiyonel, alınamazsa atla
        print(f"uyarı: {login} sosyal hesapları alınamadı: {e}", file=sys.stderr)
    return None


def gorunen_ad(login, git_adi):
    """Git commit adı > GitHub profil adı > kullanıcı adı."""
    if git_adi and git_adi.lower() != login.lower():
        return git_adi
    profil_adi = (api_get(f"/users/{login}").get("name") or "").strip()
    if profil_adi and profil_adi.lower() != login.lower():
        return profil_adi
    return login


def json_guncelle(veri, istatistik):
    kisiler = veri.setdefault("katkida_bulunanlar", [])
    mevcut = {github_login(k): k for k in kisiler if github_login(k)}

    for anahtar, ist in istatistik.items():
        kisi = mevcut.get(anahtar)
        if kisi is None:
            link = f"https://github.com/{ist['login']}"
            kisi = {
                "ad": gorunen_ad(ist["login"], ist["git_adi"]),
                "github_link": link,
                "katkida_bulunma_orani": "",
                "iletisim_bilgileri": [{"baslik": "GitHub", "link": link}],
            }
            kisiler.append(kisi)
            print(f"yeni katkıda bulunan: {kisi['ad']} ({ist['login']})")
        if anahtar not in SABIT_SEVIYELI:
            kisi["katkida_bulunma_orani"] = seviye(ist["commit"])

    # LinkedIn'i olmayanlara, GitHub profilinde varsa ekle.
    for kisi in kisiler:
        login = github_login(kisi)
        iletisim = kisi.setdefault("iletisim_bilgileri", [])
        if login and not any("linkedin.com" in b.get("link", "") for b in iletisim):
            link = linkedin_linki(login)
            if link:
                iletisim.append({"baslik": "LinkedIn", "link": link})


def oran_index(oran):
    return ORAN_DIZI.index(oran) if oran in ORAN_DIZI else len(ORAN_DIZI) - 1


def readme_bolumu(veri):
    bolum_adi = veri.get("bolum_adi", "Katkıda Bulunanlar")
    satirlar = [
        "<details>",
        f"<summary><b>🤝 {bolum_adi}</b></summary>\n",
        f"<h2 align='center'>🤝 {bolum_adi}</h2>\n",
    ]
    if veri.get("bolum_aciklamasi"):
        satirlar.append(veri["bolum_aciklamasi"] + "\n")
    sirali = sorted(veri["katkida_bulunanlar"],
                    key=lambda k: (oran_index(k.get("katkida_bulunma_orani")), k.get("ad", "")))
    for k in sirali:
        idx = oran_index(k.get("katkida_bulunma_orani"))
        emoji = EMOJILER[min(idx, len(EMOJILER) - 1)]
        tag = f"h{min(idx + 1, 6)}"
        login = github_login(k)
        if login:
            boyut = AVATAR_BOYUTLARI[min(idx, len(AVATAR_BOYUTLARI) - 1)]
            satirlar.append(f"<p align='center'><a href='{k['github_link']}'>"
                            f"<img src='https://github.com/{login}.png?size={boyut * 2}' "
                            f"width='{boyut}' alt='{k.get('ad', '')}'></a></p>")
        # Linkler başlığın içinde: GitHub h1/h2 altına çizgi çeker, çizgi linklerin altında kalsın.
        linkler = ""
        if k.get("iletisim_bilgileri"):
            linkler = "<br><sub>" + " &nbsp;·&nbsp; ".join(
                f"<a href='{b['link']}'>{b['baslik']}</a>" for b in k["iletisim_bilgileri"]) + "</sub>"
        satirlar.append(f"<{tag} align='center'>{emoji} <b><i>{k.get('ad', '')}</i></b> {emoji}{linkler}</{tag}>")
        satirlar.append("")
    satirlar.append("</details>\n")
    return "\n".join(satirlar)


def readme_guncelle(veri):
    with open(README_YOLU, encoding="utf-8") as f:
        metin = f.read()
    bolum_adi = re.escape(veri.get("bolum_adi", "Katkıda Bulunanlar"))
    desen = re.compile(
        r"<details>\n<summary><b>🤝 " + bolum_adi + r"</b></summary>.*?</details>\n", re.S)
    if not desen.search(metin):
        sys.exit("README'de Katkıda Bulunanlar bölümü bulunamadı")
    yeni = desen.sub(lambda _: readme_bolumu(veri), metin, count=1)
    with open(README_YOLU, "w", encoding="utf-8") as f:
        f.write(yeni)


def main():
    with open(JSON_YOLU, encoding="utf-8") as f:
        veri = json.load(f)
    json_guncelle(veri, katki_istatistikleri())
    with open(JSON_YOLU, "w", encoding="utf-8") as f:
        json.dump(veri, f, ensure_ascii=False, indent=4)
        f.write("\n")
    readme_guncelle(veri)


if __name__ == "__main__":
    main()
