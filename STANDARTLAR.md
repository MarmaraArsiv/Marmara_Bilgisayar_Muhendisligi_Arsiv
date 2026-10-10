# Dizin ve Dosya Adlandırma Standardı

Bu belge, repo içindeki dizin ve dosya isimlendirme kurallarını tanımlar. Yıldız Teknik Üniversitesi'nin [YTU Bilgisayar Mühendisliği Arşivi](https://github.com/baselkelziye/YTU_Bilgisayar_Muhendisligi_Arsiv) reposundaki standarttan uyarlanmıştır.

**Not:** Mevcut klasörler Ekim 2026'da bu standarda göre yeniden adlandırıldı (bkz. bölüm 6). Dosya adlarına dokunulmadı; yeni eklenen dosyalar için bölüm 4 geçerlidir.

---

## 1. Genel Kurallar

### 1.1 Türkçe Karakterler
- Tüm Türkçe karakterler kullanılmalıdır: **ç, ğ, ı, ö, ş, ü, Ç, Ğ, İ, Ö, Ş, Ü**
- İngilizce karşılıkları kullanılmaz (örn: `odevler` yerine `ödevler`, `cikmis` yerine `çıkmış`)

### 1.2 İsimlendirme İki Seviyelidir

| Seviye | Kural | Örnek |
|--------|-------|-------|
| **Ders dizinleri** | PascalCase + boşluk, bağlaçlar küçük | `Bilgisayar Mühendisliğine Giriş` |
| **Alt dizinler** | küçük harf + `_` ayracı | `ödevler`, `slaytlar_notlar`, `çalışma_soruları` |
| **Dosya adları** | küçük harf + `_` ayracı | `ödev_1.pdf`, `ders_notu.pdf` |

### 1.3 Kısaltmalar
- Kısaltma yapılmaz, tam yazılır
  - ✅ `Bilgisayar Mühendisliğine Giriş`
  - ❌ `BMG` / `algo` (kısaltma)

---

## 2. Ders Dizini Adlandırma (PascalCase + Boşluk)

Ders dizinleri dönem klasörünün **2. seviyesinde** bulunur:

```
1-1/Bilgisayar Mühendisliğine Giriş/
2-1/Nesne Yönelimli Programlama/
```

- Her kelimenin ilk harfi **büyük** yazılır
- Bağlaçlar **küçük** yazılır: `ve`, `için`, `ile`, `veya`, `ya da`
- Kelimeler arasında **tek boşluk**, Türkçe karakterler korunur
- `_` veya `-` kullanılmaz

---

## 3. Alt Dizin Adlandırma (küçük harf + `_`)

Ders dizini **içindeki** tüm alt klasörler bu kurala uyar: tümü küçük harf, boşluk/tire yasak, kelimeler arası `_`.

### 3.1 Standart Alt Dizin Kelime Haznesi

| Dizin Türü | Standart Ad | Örnek |
|-----------|------------|-------|
| Slayt/ders notu | `slaytlar_notlar` | `slaytlar_notlar/2024/` |
| Ödevler | `ödevler` | `ödevler/2024/` |
| Ödev alt dizini | `ödev_X` | `ödev_1/`, `ödev_2/` |
| Proje | `proje` | `proje/2024/` |
| Çıkmış sorular | `çıkmış_sorular` | `çıkmış_sorular/2024/` |
| Çalışma soruları | `çalışma_soruları` | `çalışma_soruları/` |
| Harf notları | `harf_notları` | `harf_notları/2024/` |
| Lablar | `lablar` | `lablar/` |
| Lab + kod (birleşik) | `lablar_kodlar` | `lablar_kodlar/` |
| Kodlar | `kodlar` | `kodlar/` |
| Quizler | `quizler` | `quizler/` |
| Sınavlar | `sınavlar` | `sınavlar/` |
| Atölye ders notları | `atölye_notları` | `atölye_notları/` |
| Atölye ödevleri | `atölye_ödevleri` | `atölye_ödevleri/` |

### 3.2 Birleşik Dizin Kuralları
- `lablar_kodlar`: Hem lab hem kod içeren derslerde tek dizin, ayrı `lablar/`+`kodlar/` yerine tercih edilir.
- Sıralama her zaman "lab önce": `lablar_kodlar`, `kodlar_lablar` değil.

### 3.3 Yıl Dizinleri
- Dört haneli yıl: `2024`, `2025`
- Dönem bazlı ise: `2024-2025`

---

## 4. Dosya Adlandırma
- Tümü **küçük harf**, boşluk yerine `_`, Türkçe karakterler korunur
  - ✅ `ödev_1.pdf`
  - ❌ `Ödev 1.pdf`, `odev-1.pdf`

---

## 5. Yasak İsimlendirmeler

| Yasak | Doğru | Sebep |
|-------|-------|-------|
| `odev1` | `ödev_1` | Türkçe karakter + ayraç eksik |
| `ödev 1` | `ödev_1` | boşluk yasak (alt dizinde) |
| `Ödev_1` | `ödev_1` | büyük harf |
| `algo` | `kodlar` / `lablar_kodlar` | kısaltma |
| `Lab` | `lablar` | İngilizce + büyük harf |
| `çıkmış` / `çıkmışlar` | `çıkmış_sorular` | tek kanonik ad kullanılmalı |

---

## 6. Yapılan Taşıma (Ekim 2026)

Mevcut klasörler bu standarda göre yeniden adlandırıldı:

| Önce | Sonra |
|-------|----------------|
| `Algoritma`, `Mat1`, `Fizik` | `Algoritma ve Programlamaya Giriş`, `Matematik 1`, `Fizik 1` |
| Roma rakamlı ders adları (`… II`, `Staj I`) | Arap rakamı (`… 2`, `Staj 1`) |
| `çalışma soruları` (boşluklu) | `çalışma_soruları` |
| `çıkmış` / `çıkmışlar` | `çıkmış_sorular` |
| `slaytlar`, `notlar`, `ders notları`, `ders slaytları`, `algo` | `slaytlar_notlar` |
| `Lab`, `Lab 1`, `lab ödevleri` | `lablar`, `lab_1` |
| `atölye dersi` / `atolye ödev` | `atölye_notları` / `atölye_ödevleri` |
| `not dağılımları` | `harf_notları` |

**Ders numaralandırma:** Ders adlarında Arap rakamı kullanılır: `Fizik 1`, `Bilgisayar Programlama 2`, `Staj 1`.

---

## 7. Kontrol Listesi

Yeni ders dizini eklerken:
- [ ] PascalCase + boşluk formatında mı?
- [ ] Bağlaçlar küçük harf mi?
- [ ] Türkçe karakterler doğru mu?
- [ ] Kısaltma yapılmamış mı?
- [ ] README.md var mı?

Yeni alt dizin/dosya eklerken:
- [ ] Tümü küçük harf mi?
- [ ] Ayraç `_` mi (boşluk/tire yok)?
- [ ] Standart kelime haznesinden mi (bölüm 3.1)?
- [ ] Türkçe karakterler doğru mu?
