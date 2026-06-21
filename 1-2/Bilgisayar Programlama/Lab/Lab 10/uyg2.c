/*
Dosya Boyutunu Bulma ve Son Karakteri Okuma

Öncelikle kullanıcıdan bir metin alarak metin.txt adlı dosyaya yazınız.
Daha sonra bu dosyanın boyutunu byte cinsinden bulan ve dosyanın son karakterini 
ekrana yazdıran C programını yazınız.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *dosya;
    char metin[200];
    long boyut;
    char sonKarakter;

    // --------------------------------------------------
    // 1. ADIM: Kullanıcıdan metin alma
    // --------------------------------------------------

    printf("Bir metin giriniz: ");
    fgets(metin, sizeof(metin), stdin);
   
    // ENTER karakterini silme
    metin[strcspn(metin, "\n")] = '\0';

    // --------------------------------------------------
    // 2. ADIM: Dosyayı yazma modunda açma
    // --------------------------------------------------

    dosya = fopen("metin.txt", "w");

    if (dosya == NULL)
    {
        printf("Dosya olusturulamadi!\n");
        return 1;
    }

    // --------------------------------------------------
    // 3. ADIM: Kullanıcının girdiği metni dosyaya yazma
    // --------------------------------------------------

    fprintf(dosya, "%s", metin);

    // --------------------------------------------------
    // 4. ADIM: Dosyayı kapatma
    // --------------------------------------------------

    fclose(dosya);

    // --------------------------------------------------
    // 5. ADIM: Dosyayı tekrar okuma modunda açma
    // --------------------------------------------------

    dosya = fopen("metin.txt", "r");

    if (dosya == NULL)
    {
        printf("Dosya acilamadi!\n");
        return 1;
    }

    // --------------------------------------------------
    // 6. ADIM: Dosya göstergecini dosyanın sonuna götürme
    // SEEK_END = dosyanın sonu
    // --------------------------------------------------

    fseek(dosya, 0, SEEK_END);

    // --------------------------------------------------
    // 7. ADIM: ftell ile dosya boyutunu öğrenme
    // ftell bize dosya başından itibaren kaç byte ilerlediğimizi verir.
    // Şu anda dosya sonunda olduğumuz için bu değer dosya boyutudur.
    // --------------------------------------------------

    boyut = ftell(dosya);

    printf("\nDosya boyutu: %ld byte\n", boyut);

    // --------------------------------------------------
    // 8. ADIM: Son karakteri okumak için
    // dosya sonundan 1 byte geri gitme
    // --------------------------------------------------

    fseek(dosya, -1, SEEK_END);

    // --------------------------------------------------
    // 9. ADIM: Son karakteri okuma
    // --------------------------------------------------

    sonKarakter = fgetc(dosya);

    printf("Dosyanin son karakteri: %c\n", sonKarakter);

    // --------------------------------------------------
    // 10. ADIM: Dosyayı kapatma
    // --------------------------------------------------

    fclose(dosya);

    return 0;
}