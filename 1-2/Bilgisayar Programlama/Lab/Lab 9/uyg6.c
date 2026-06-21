/*
Soru 6: Dosyadaki Sayıların Ortalamasından Büyük Olanları Bulma

sayilar.txt dosyasında her satırda bir tam sayı bulunmaktadır. Dosyadaki sayıların ortalamasını bulunuz. Daha sonra ortalamadan büyük olan sayıları buyukler.txt dosyasına yazınız.

Çözüm Mantığı
Dosya önce yazma ardından okuma okuma modunda açılır.
Sayılar okunarak toplam ve adet bulunur.
Ortalama hesaplanır.
Dosya başına dönmek için dosya kapatılıp tekrar açılır.
Ortalamadan büyük sayılar başka dosyaya yazılır.*/

#include <stdio.h>

int main()
{
    FILE *olustur;
    FILE *dosya;
    FILE *buyukDosya;

    int sayi;
    int toplam = 0;
    int adet = 0;
    float ortalama;

    // --------------------------------------------------
    // 1. ADIM: sayilar.txt dosyasını oluşturuyoruz
    // --------------------------------------------------
    olustur = fopen("sayilar.txt", "w");

    if (olustur == NULL)
    {
        printf("sayilar.txt dosyasi olusturulamadi!\n");
        return 1;
    }

    // Örnek sayılar dosyaya yazılır.
    fprintf(olustur, "10\n");
    fprintf(olustur, "25\n");
    fprintf(olustur, "40\n");
    fprintf(olustur, "5\n");
    fprintf(olustur, "30\n");
    fprintf(olustur, "55\n");
    fprintf(olustur, "50\n");

    fclose(olustur);

    // --------------------------------------------------
    // 2. ADIM: Dosyayı okuma modunda açıyoruz
    // --------------------------------------------------
    dosya = fopen("sayilar.txt", "r");

    if (dosya == NULL)
    {
        printf("sayilar.txt dosyasi acilamadi!\n");
        return 1;
    }

    // İlk okuma: toplam ve adet bulunur.
    while (fscanf(dosya, "%d", &sayi) != EOF)
    {
        toplam += sayi;
        adet++;
    }

    fclose(dosya);

    // eğer dosyada sayı bulunamazsa
    if (adet == 0)
    {
        printf("Dosyada sayi bulunamadi!\n");
        return 1;
    }

    ortalama = (float)toplam / adet;

    // --------------------------------------------------
    // 3. ADIM: Dosyayı tekrar okuyup ortalamadan büyükleri buluyoruz
    // --------------------------------------------------
    dosya = fopen("sayilar.txt", "r");
    buyukDosya = fopen("buyukler.txt", "w");

    if (dosya == NULL || buyukDosya == NULL)
    {
        printf("Dosya acma hatasi!\n");
        return 1;
    }

    while (fscanf(dosya, "%d", &sayi) != EOF)
    {
        if (sayi > ortalama)
        {
            fprintf(buyukDosya, "%d\n", sayi);
        }
    }

    fclose(dosya);
    fclose(buyukDosya);

    printf("Ortalama: %.2f\n", ortalama);
    printf("Ortalamadan buyuk sayilar buyukler.txt dosyasina yazildi.\n");

    return 0;
}