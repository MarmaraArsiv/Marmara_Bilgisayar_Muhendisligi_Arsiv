/*
Dosyada Belirli Karakter Konumlarına Gitme

karakterler.txt adlı dosyaya A’dan Z’ye kadar harfleri yazınız. 
Daha sonra kullanıcıdan bir sıra numarası alınız. 
Girilen sıra numarasındaki karakteri dosyadan okuyup ekrana yazdırınız.
Örnek:
Kullanıcı 5 girerse ekrana E yazmalıdır.*/

#include <stdio.h>

int main()
{
    FILE *dosya;
    char harf;
    int sira;

    // --------------------------------------------------
    // 1. ADIM: Dosyayı yazma modunda açıyoruz
    // --------------------------------------------------
    dosya = fopen("karakterler.txt", "w");

    if (dosya == NULL)
    {
        printf("Dosya olusturulamadi!\n");
        return 1;
    }

    // --------------------------------------------------
    // 2. ADIM: A'dan Z'ye kadar harfleri dosyaya yazıyoruz
    // --------------------------------------------------
    for (harf = 'A'; harf <= 'Z'; harf++)
    {
        fputc(harf, dosya);
    }

    fclose(dosya);

    // --------------------------------------------------
    // 3. ADIM: Kullanıcıdan okunacak karakter sırasını alıyoruz
    // --------------------------------------------------
    printf("Okumak istediginiz karakter sirasini giriniz (1-26): ");
    scanf("%d", &sira);

    // --------------------------------------------------
    // 4. ADIM: Dosyayı okuma modunda açıyoruz
    // --------------------------------------------------
    dosya = fopen("karakterler.txt", "r");

    if (dosya == NULL)
    {
        printf("Dosya acilamadi!\n");
        return 1;
    }

    // --------------------------------------------------
    // 5. ADIM: fseek ile istenen konuma gidiyoruz
    // sira 1 ise dosyada 0. byte'a gitmeliyiz.
    // Bu nedenle sira - 1 kullanılır.
    // Dosyanın başlangıcı 0.byte olarak kabul ediyoruz (SEEK_SET ile)
    // --------------------------------------------------
    fseek(dosya, sira - 1, SEEK_SET);

    // --------------------------------------------------
    // 6. ADIM: O konumdaki karakteri okuyoruz
    // --------------------------------------------------
    harf = fgetc(dosya);

    printf("%d. siradaki karakter: %c\n", sira, harf);

    fclose(dosya);

    return 0;
}