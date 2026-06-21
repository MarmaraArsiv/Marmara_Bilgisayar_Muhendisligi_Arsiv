/*
Soru 9: Dosyadaki Belirli Bir Kelimeyi Sayma

Kullanıcıdan aranacak bir kelime alınız. metin2.txt dosyasında bu kelimenin kaç kez geçtiğini bulan C programını yazınız.

metin2.txt dosyasının içeriği:
  C dili dosya islemleri icin onemlidir
  Dosya okuma ve dosya yazma C dilinde yapilir
  C programlama dersinde dosya konusu islenmektir

Çözüm Mantığı
Kullanıcıdan aranacak kelime alınır.
Dosya önce yazma ardından okuma modunda açılır.
Dosyadan kelime kelime okuma yapılır.
Okunan kelime aranan kelimeyle aynıysa sayaç artırılır.
Sonuç ekrana yazdırılır.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *olustur;
    FILE *dosya;

    char aranan[50];
    char kelime[50];

    int sayac = 0;

    // --------------------------------------------------
    // 1. ADIM: metin2.txt dosyasını oluşturuyoruz
    // --------------------------------------------------
    olustur = fopen("metin2.txt", "w");

    if (olustur == NULL)
    {
        printf("metin2.txt dosyasi olusturulamadi!\n");
        return 1;
    }

    fprintf(olustur, "C dili dosya islemleri icin onemlidir\n");
    fprintf(olustur, "Dosya okuma ve dosya yazma C dilinde yapilir\n");
    fprintf(olustur, "C programlama dersinde dosya konusu islenmektedir\n");

    fclose(olustur);

    // --------------------------------------------------
    // 2. ADIM: Kullanıcıdan aranacak kelime alınır
    // --------------------------------------------------
    printf("Aranacak kelimeyi giriniz: ");
    scanf("%s", aranan);

    // --------------------------------------------------
    // 3. ADIM: Dosya okuma modunda açılır
    // --------------------------------------------------
    dosya = fopen("metin2.txt", "r");

    if (dosya == NULL)
    {
        printf("metin2.txt dosyasi acilamadi!\n");
        return 1;
    }

    // Dosyadan kelime kelime okuma yapılır.
    while (fscanf(dosya, "%s", kelime) != EOF)
    {
        // strcmp sonucu 0 ise iki kelime aynıdır.
        if (strcmp(kelime, aranan) == 0)
        {
            sayac++;
        }
    }

    fclose(dosya);

    printf("'%s' kelimesi dosyada %d kez gecmektedir.\n", aranan, sayac);

    return 0;
}