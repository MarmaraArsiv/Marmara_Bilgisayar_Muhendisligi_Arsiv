/*
Soru 7: Ürün Stok Takip Sistemi

Kullanıcıdan 5 ürün için ürün adı, fiyatı ve stok miktarı alınsın. Bu bilgiler stok.txt dosyasına yazılsın. Daha sonra dosya okunarak stok miktarı 10’dan az olan ürünler ekrana yazdırılsın.

Çözüm Mantığı
Dosya yazma modunda açılır.
5 ürün bilgisi kullanıcıdan alınır.
Bilgiler dosyaya yazılır.
Dosya okuma modunda tekrar açılır.
Stok miktarı 10’dan az olan ürünler listelenir.
*/

#include <stdio.h>

int main()
{
    FILE *dosya;

    char urunAdi[50];
    float fiyat;
    int stok;
    int i;

    // --------------------------------------------------
    // 1. ADIM: stok.txt dosyasını yazma modunda açıyoruz
    // --------------------------------------------------
    dosya = fopen("stok.txt", "w");

    if (dosya == NULL)
    {
        printf("stok.txt dosyasi olusturulamadi!\n");
        return 1;
    }

    // Kullanıcıdan 5 ürün bilgisi alınır.
    for (i = 0; i < 5; i++)
    {
        printf("%d. urun adi: ", i + 1);
        scanf("%s", urunAdi);

        printf("%d. urun fiyati: ", i + 1);
        scanf("%f", &fiyat);

        printf("%d. urun stok miktari: ", i + 1);
        scanf("%d", &stok);

        // Ürün bilgileri dosyaya yazılır.
        fprintf(dosya, "%s %.2f %d\n", urunAdi, fiyat, stok);
    }

    fclose(dosya);

    // --------------------------------------------------
    // 2. ADIM: stok.txt dosyasını okuma modunda açıyoruz
    // --------------------------------------------------
    dosya = fopen("stok.txt", "r");

    if (dosya == NULL)
    {
        printf("stok.txt dosyasi okuma icin acilamadi!\n");
        return 1;
    }

    printf("\nStok miktari 10'dan az olan urunler:\n");

    // Dosyadan ürün bilgileri okunur.
    while (fscanf(dosya, "%s %f %d", urunAdi, &fiyat, &stok) != EOF)
    {
        if (stok < 10)
        {
            printf("Urun: %s | Fiyat: %.2f | Stok: %d\n", urunAdi, fiyat, stok);
        }
    }

    fclose(dosya);

    return 0;
}