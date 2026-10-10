# 🤝 Arşive Nasıl Katkıda Bulunurum?

Elinde bir ders notu, slayt, çıkmış soru, ödev çözümü ya da faydalı bir kaynak varsa arşive eklemek çok kolay. Senin için uygun olan yolu seç:

| Yol | Kimler için | Ne kadar sürer |
|---|---|---|
| [📁 Yol 1: Google Drive'a yükle](#-yol-1-google-drivea-yükle) | GitHub kullanmayan herkes | ~2 dakika |
| [🌐 Yol 2: GitHub sitesinden yükle](#-yol-2-github-sitesinden-yükle-kurulum-gerektirmez) | GitHub hesabı olan, kod bilmeyen | ~5 dakika |
| [💻 Yol 3: Git ile pull request](#-yol-3-git-ile-pull-request) | Git kullanmayı bilen | ~5 dakika |

> 📺 **Video anlatım:** *Repoya nasıl katkı yapılır?* videosu yakında burada olacak.

---

## 📁 Yol 1: Google Drive'a yükle

1. [**Marmara Arşiv Drive klasörünü**](https://drive.google.com/drive/folders/1KRobMRVHpJxUKcCZdCEippSZ5SmgpkZq?usp=sharing) aç ve önce **BENİOKU** dosyasını oku.
2. **Bilgisayar-Teknoloji** klasörüne gir ve içinde kendi adınla yeni bir klasör oluştur.
3. Dosyalarını bu klasöre yükle. Yanına kısa bir not ekle:
   - **Ders ve dönem:** Hangi ders, hangi yıl, hangi dönem?
   - **Kapsam:** Vize notları mı, lab ödevleri mi, çıkmış sorular mı?
   - **Önemli notlar:** Ders, hoca ya da lab hakkında bilinmesi gereken bir şey var mı?
   - **E-posta:** Bir şey eksik olursa sana ulaşabilmemiz için.
4. Dosyalar kontrol edilir, uygun olanlar repoya eklenir.

---

## 🌐 Yol 2: GitHub sitesinden yükle (kurulum gerektirmez)

1. Sağ üstteki **Fork** butonuna bas. Reponun bir kopyası senin hesabında oluşur.
2. Kendi kopyanda dosyayı koyacağın dersin klasörüne gir. Örnek: `2-1/Nesne Yönelimli Programlama/`
3. **Add file → Upload files** ile dosyalarını sürükle-bırak yap.
   - Yeni bir alt klasör gerekiyorsa adını dosya adının başına yaz: `çıkmış_sorular/2025_vize.pdf`
4. En alta kısa bir açıklama yazıp **Commit changes** de.
5. Üstte çıkan **Contribute → Open pull request** butonuna bas ve isteği gönder.
6. İsteğin onaylanınca adın **Katkıda Bulunanlar** listesine otomatik olarak eklenir.

---

## 💻 Yol 3: Git ile pull request

```bash
# 1. Repoyu fork'la, sonra kendi kopyanı klonla
git clone git@github.com:<kullanıcı-adın>/Marmara_Bilgisayar_Muhendisligi_Arsiv.git
cd Marmara_Bilgisayar_Muhendisligi_Arsiv

# 2. Yeni bir dal aç
git checkout -b nesne-yonelimli-cikmislar

# 3. Dosyalarını ilgili ders klasörüne koy, sonra:
git add .
git commit -m "Nesne Yönelimli Programlama: 2025 vize soruları eklendi"
git push origin nesne-yonelimli-cikmislar
```

Ardından GitHub'da **Compare & pull request** butonuna bas.

---

## 📏 Dikkat Edilecekler

- **Doğru klasör:** Dosyayı dersin bulunduğu dönem klasörüne koy (`1-1` = 1. sınıf güz, `1-2` = 1. sınıf bahar …). Seçmeli dersler `Mesleki Seçmeli/`, `Üniversite Seçmeli/` ve `Fakülte Teknik Seçmeli/` altında.
- **Adlandırma:** Alt klasör ve dosya adları küçük harfle ve `_` ile yazılır: `çıkmış_sorular/`, `slaytlar_notlar/`, `ödev_1.pdf`. Ayrıntılar [STANDARTLAR.md](STANDARTLAR.md) dosyasında.
- **Kişisel bilgi yükleme:** Öğrenci numarası, ad-soyad listesi, telefon gibi başkalarına ait bilgileri yükleme; varsa karart.
- **README'leri elle düzeltme:** README'ler otomatik üretiliyor. Bir hata görürsen [issue açman](https://github.com/MarmaraArsiv/Marmara_Bilgisayar_Muhendisligi_Arsiv/issues) yeterli.
- **Nazik ol:** Hoca ve ders yorumlarında hakaret içeren içerik kabul edilmez.

Katkın için şimdiden teşekkürler! 💙
