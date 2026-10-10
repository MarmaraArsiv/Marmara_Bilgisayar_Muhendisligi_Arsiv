# 🎓 Müfredat Notu

Bu klasörde iki müfredat dosyası var:

- [`bilgisayar_mühendisliği_müfredatı_2026_öncesi.pdf`](./bilgisayar_mühendisliği_müfredatı_2026_öncesi.pdf) — şu an aktif olan, 2026-2027'den önce kayıt olmuş öğrencilerin tabi olduğu müfredat.
- [`bilgisayar_mühendisliği_müfredatı_2026_sonrası.pdf`](./bilgisayar_mühendisliği_müfredatı_2026_sonrası.pdf) — 2026-2027 akademik yılından itibaren kayıt olan öğrenciler için geçerli, revize müfredat.

## 🗂 Tek Yapı, Etiketli Dersler

Bu repo **iki ayrı klasör ağacı tutmaz.** Her iki müfredatın dersleri aynı dönem klasörlerinde (`1-1` … `4-2`) ve aynı seçmeli havuzlarında (`Mesleki Seçmeli`, `Üniversite Seçmeli`, `Fakülte Teknik Seçmeli`) birlikte yer alır. Bir dersin README'sinde `🏷️ Müfredat:` satırı varsa, o ders her iki müfredatta ortak değildir:

- `🏷️ Müfredat: 2026 Öncesi` — sadece 2026 öncesi müfredatta var.
- `🏷️ Müfredat: 2026 Sonrası` — sadece 2026 sonrası müfredatta var.
- `🏷️ Müfredat: Her İki Müfredat` — ikisinde de var, ama isim/dönem gibi küçük bir farkı var (not kısmında açıklanır).
- **Etiketi olmayan** dersler her iki müfredatta da aynen ortaktır — ekstra not gerekmez.

## 🔍 Bilinen Farklar (2026 öncesi → 2026 sonrası)

- **1. Yıl:** `Kimya` → `Modern Biyolojiye Giriş`. İş Sağlığı ve Güvenliği iki parçaya bölünmüş (1. ve 2. yarıyıl).
- **1-2. Yıl:** `Bilimsel Araştırma ve Sunum Teknikleri` 3. yıla taşınmış (`...Teknikleri 2` adıyla), yerine `Mühendislik Ekonomisi` eklenmiş.
- **2-3. Yıl:** `Mühendisler için İstatistik` → `Olasılık ve İstatistik` + `Teknik İngilizce 1/II`.
- **2-3. Yıl:** `İnsan-Bilgisayar Etkileşimi ve Görsellik` ve `Mikrodenetleyiciler` zorunluluktan seçmeliye düşmüş (Mesleki Seçmeli'ye taşınmış); `Algoritma Analizi` ve `Biçimsel Diller ve Otomata Teorisi` ise seçmeliden zorunluya çıkmış (sırasıyla `Algoritma Analizi ve Tasarımı` adıyla 3-1'e, aynı adla 3-2'ye).
- **4. Yıl:** `Bitirme Projesi` → `Bitirme Projesi 1` (4-1) + `Bitirme Projesi 2` (4-2). Ayrıca `İş Hukuku ve Etiği` eklenmiş.
- **Seçmeli havuzları:** 2026 sonrası müfredat çoğu dersi korumuş, bazılarını güncellemiş (`Yapay Zekâya Giriş`→`Güncel Yapay Zeka Yaklaşımları`, `Kablosuz Ağlar`→`Kablosuz ve Mobil Ağlar`) ve tamamen yeni dersler eklemiş (Makine Öğrenimine Giriş, Blockchain Programlamaya Giriş, Bulut Bilişim vb.). Ayrıca eski müfredatta karşılığı olmayan, tamamen yeni bir **Fakülte Teknik Seçmeli** havuzu eklenmiş.

Tam liste için her iki PDF'e bakılabilir. Yukarıdaki her fark, ilgili ders klasörlerinde `🏷️ Müfredat:` etiketi ve çapraz referans notuyla da işaretli.
