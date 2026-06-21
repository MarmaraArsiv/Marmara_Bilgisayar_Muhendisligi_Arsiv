/*
Soru 2: Dosyadaki Büyük Harfleri Küçük Harfe Çevirme

metin.txt dosyasındaki büyük harfleri küçük harfe çevirerek kucuk_metin.txt adlı yeni bir dosyaya yazan C programını yazınız.

Çözüm Mantığı
metin.txt okuma modunda açılır.
kucuk_metin.txt yazma modunda açılır.
Dosyadan karakter karakter okuma yapılır.
Karakter büyük harf ise küçük harfe çevrilir.
Yeni karakter diğer dosyaya yazılır.*/


#include <stdio.h>

int main()
{
    FILE *giris;
    FILE *cikis;

    char ch;

    // Okunacak dosya açılır.
    giris = fopen("metin.txt", "r");

    if (giris == NULL)
    {
        printf("metin.txt dosyasi acilamadi!\n");
        return 1;
    }

    // Yazılacak yeni dosya açılır.
    cikis = fopen("kucuk_metin.txt", "w");

    if (cikis == NULL)
    {
        printf("kucuk_metin.txt dosyasi olusturulamadi!\n");
        fclose(giris);
        return 1;
    }

    // Dosya sonuna kadar karakter karakter okuma yapılır.
    while ((ch = fgetc(giris)) != EOF)
    {
        // Eğer karakter A-Z arasında ise büyük harftir.
        if (ch >= 'A' && ch <= 'Z')
        {
            // ASCII mantığına göre büyük harf küçük harfe çevrilir.
            ch = ch + 32;
        }

        // Karakter yeni dosyaya yazılır.
        fputc(ch, cikis);
    }

    fclose(giris);
    fclose(cikis);

    printf("Dosyadaki buyuk harfler kucuk harfe cevrildi.\n");

    return 0;
}