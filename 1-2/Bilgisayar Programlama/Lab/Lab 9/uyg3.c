/*
Soru 3: Dosyadaki Sesli Harfleri Sayma

metin.txt dosyasındaki a, e, i, o, u sesli harflerinin kaç kez geçtiğini bulan C programını yazınız.

Çözüm Mantığı
Dosya okuma modunda açılır.
Karakter karakter okuma yapılır.
Okunan karakter sesli harflerden biriyse ilgili sayaç artırılır.
Sonuçlar ekrana yazdırılır.*/


#include <stdio.h>

int main()
{
    FILE *dosya;
    char ch;

    int aSayisi = 0;
    int eSayisi = 0;
    int iSayisi = 0;
    int oSayisi = 0;
    int uSayisi = 0;

    dosya = fopen("metin.txt", "r");

    if (dosya == NULL)
    {
        printf("metin.txt dosyasi acilamadi!\n");
        return 1;
    }

    // Dosyadan karakter karakter okuma yapılır.
    while ((ch = fgetc(dosya)) != EOF)
    {
        // Büyük harf gelirse küçük harfe çevrilir.
        if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + 32;
        }

        if (ch == 'a')
        {
            aSayisi++;
        }
        else if (ch == 'e')
        {
            eSayisi++;
        }
        else if (ch == 'i')
        {
            iSayisi++;
        }
        else if (ch == 'o')
        {
            oSayisi++;
        }
        else if (ch == 'u')
        {
            uSayisi++;
        }
    }

    fclose(dosya);

    printf("a harfi sayisi: %d\n", aSayisi);
    printf("e harfi sayisi: %d\n", eSayisi);
    printf("i harfi sayisi: %d\n", iSayisi);
    printf("o harfi sayisi: %d\n", oSayisi);
    printf("u harfi sayisi: %d\n", uSayisi);

    return 0;
}