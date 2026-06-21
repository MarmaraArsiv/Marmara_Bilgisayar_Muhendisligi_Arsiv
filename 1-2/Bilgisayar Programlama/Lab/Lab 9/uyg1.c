/*
Soru 1: Dosyadaki Karakter, Kelime ve Satır Sayısını Bulma
metin.txt adlı dosyada bulunan toplam karakter, kelime ve satır sayısını bulan C programını yazınız.
Çözüm Mantığı
Dosya önce yazma ardında okuma modunda açılır.
Dosya karakter karakter okunur.
Her okunan karakter için karakter sayısı artırılır.
\n görülürse satır sayısı artırılır.
Boşluk, tab veya satır sonu görülünce kelime kontrolü yapılır.
Sonuçlar ekrana yazdırılır.*/

#include <stdio.h>

int main()
{
    FILE *dosya;     //dosya işaretçisi
    FILE *olustur;

    char ch;

    int karakterSayisi = 0;
    int kelimeSayisi = 0;
    int satirSayisi = 0;

    // Bir kelimenin içinde olup olmadığımızı kontrol etmek için kullanılır.
    int kelimeIcinde = 0;

    // --------------------------------------------------
    // 1. ADIM: Önce metin.txt dosyasını oluşturuyoruz.
    // --------------------------------------------------
    // "w" modu dosya yoksa oluşturur.
    // Dosya varsa içeriğini silip yeniden yazar.
    olustur = fopen("metin.txt", "w");

    if (olustur == NULL)
    {
        printf("metin.txt dosyasi olusturulamadi!\n");
        return 1;
    }

    // Dosyanın içine örnek metin yazıyoruz.
    fprintf(olustur, "Merhaba Dunya\n");
    fprintf(olustur, "C Programlama Guzeldir\n");
    fprintf(olustur, "Dosya Islemleri Ogreniyorum\n");

    // Yazma işlemi bittikten sonra dosya kapatılır.
    fclose(olustur);

    // --------------------------------------------------
    // 2. ADIM: Oluşturulan metin.txt dosyasını okuyoruz.
    // --------------------------------------------------
    dosya = fopen("metin.txt", "r");

    if (dosya == NULL)
    {
        printf("metin.txt dosyasi acilamadi!\n");
        return 1;
    }

    // Dosya sonuna kadar karakter karakter okuma yapılır. EOF=End Of File
    while ((ch = fgetc(dosya)) != EOF)
    {
        // Her okunan karakter toplam karakter sayısını artırır.
        karakterSayisi++;

        // Satır sonu karakteri görülürse satır sayısı artırılır.
        if (ch == '\n')
        {
            satirSayisi++;
        }

        // Boşluk, tab veya satır sonu kelimenin bittiğini gösterir.
        if (ch == ' ' || ch == '\n' || ch == '\t')
        {
            kelimeIcinde = 0;
        }
        else if (kelimeIcinde == 0)
        {
            // Eğer boşluk dışı bir karakter geldiyse yeni kelime başlamıştır.
            kelimeSayisi++;
            kelimeIcinde = 1;
        }
    }

    fclose(dosya);

    printf("Karakter sayisi: %d\n", karakterSayisi);
    printf("Kelime sayisi: %d\n", kelimeSayisi);
    printf("Satir sayisi: %d\n", satirSayisi);

    return 0;
}