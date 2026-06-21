/*
Soru 5: Öğrenci Notlarını Geçen ve Kalan Olarak Ayırma
notlar.txt dosyasında her satırda bir öğrencinin adı ve notu bulunmaktadır. Notu 50 ve üzeri olan öğrencileri gecenler.txt, 50’den küçük olanları kalanlar.txt dosyasına yazınız.
Örnek notlar.txt:
Ali 75
Ayse 42
Mehmet 60
Zeynep 35
Fatma 90
Çözüm Mantığı
notlar.txt w ve r modlarında modunda açılır.
gecenler.txt ve kalanlar.txt yazma modunda açılır.
Dosyadan ad ve not bilgisi okunur.
Not 50 ve üzeriyse geçenler dosyasına yazılır.
Not 50’den küçükse kalanlar dosyasına yazılır.
*/

#include <stdio.h>

int main()
{   // dosya işaretçileri tanımlanır
    FILE *olustur;
    FILE *notDosyasi;
    FILE *gecenDosyasi;
    FILE *kalanDosyasi;

    char ad[50];
    int notDegeri;

    // --------------------------------------------------
    // 1. ADIM: notlar.txt dosyasını oluşturuyoruz
    // --------------------------------------------------
    olustur = fopen("notlar.txt", "w");

    if (olustur == NULL)
    {
        printf("notlar.txt dosyasi olusturulamadi!\n");
        return 1;
    }

    // Örnek öğrenci notları dosyaya yazılır.
    fprintf(olustur, "Ali 75\n");
    fprintf(olustur, "Ayse 42\n");
    fprintf(olustur, "Mehmet 60\n");
    fprintf(olustur, "Zeynep 35\n");
    fprintf(olustur, "Fatma 90\n");

    fclose(olustur);

    // --------------------------------------------------
    // 2. ADIM: notlar.txt dosyasını okuma modunda açıyoruz
    // --------------------------------------------------
    notDosyasi = fopen("notlar.txt", "r");

    if (notDosyasi == NULL)
    {
        printf("notlar.txt dosyasi acilamadi!\n");
        return 1;
    }

    // Geçen ve kalan öğrenciler için iki ayrı dosya oluşturulur.
    gecenDosyasi = fopen("gecenler.txt", "w");
    kalanDosyasi = fopen("kalanlar.txt", "w");

    if (gecenDosyasi == NULL || kalanDosyasi == NULL)
    {
        printf("Cikis dosyalari olusturulamadi!\n");
        fclose(notDosyasi);
        return 1;
    }

    // --------------------------------------------------
    // 3. ADIM: Dosyadan ad ve not bilgilerini oku
    // --------------------------------------------------
    while (fscanf(notDosyasi, "%s %d", ad, &notDegeri) != EOF)
    {
        if (notDegeri >= 50)
        {
            // Notu 50 ve üzeri olanlar geçenler dosyasına yazılır.
            fprintf(gecenDosyasi, "%s %d\n", ad, notDegeri);
        }
        else
        {
            // Notu 50’den küçük olanlar kalanlar dosyasına yazılır.
            fprintf(kalanDosyasi, "%s %d\n", ad, notDegeri);
        }
    }

    fclose(notDosyasi);
    fclose(gecenDosyasi);
    fclose(kalanDosyasi);

    printf("Ogrenciler gecenler.txt ve kalanlar.txt dosyalarina ayrildi.\n");

    return 0;
}