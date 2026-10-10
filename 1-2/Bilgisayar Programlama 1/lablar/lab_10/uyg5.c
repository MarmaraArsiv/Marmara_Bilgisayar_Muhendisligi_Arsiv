/*
Sayının Bitlerini Analiz Etme

Kullanıcıdan 0–255 arasında bir tam sayı alınız. Bu sayıyı 8 bitlik ikilik biçimde ekrana yazdırınız. 
Daha sonra:
Sayının tek mi çift mi olduğunu bitwise işlemle bulunuz.
Sayının kaç adet 1 biti içerdiğini hesaplayınız.
Kullanıcıdan bir bit pozisyonu alınız ve o bitin 1 mi 0 mı olduğunu kontrol ediniz.
Kullanıcıdan bir bit pozisyonu alınız ve o biti 1 yapınız.
*/

#include <stdio.h>

int main()
{
    unsigned int sayi;
    int i;
    int birSayisi = 0;
    int bitPozisyonu;
    unsigned int maske;

    // --------------------------------------------------
    // 1. ADIM: Kullanıcıdan 0-255 arasında sayı alma
    // --------------------------------------------------
    printf("0-255 arasinda bir sayi giriniz: ");
    scanf("%u", &sayi);

    // --------------------------------------------------
    // 2. ADIM: Sayıyı 8 bitlik ikilik biçimde yazdırma
    // En soldaki bitten en sağdaki bite doğru kontrol edilir.
    // --------------------------------------------------
    printf("\nSayinin 8 bitlik ikilik gosterimi: ");

    for (i = 7; i >= 0; i--)
    {
        // 1 sayısını i kadar sola kaydırarak maske oluşturuyoruz.
        // Örneğin i=7 için maske: 10000000
        maske = 1 << i;

        // sayi & maske sonucu 0 değilse ilgili bit 1'dir.sayı içindeki ilgili bit 1 mi?
        if ((sayi & maske) != 0)
            printf("1");
        else
            printf("0");
    }

    // --------------------------------------------------
    // 3. ADIM: Sayının tek mi çift mi olduğunu bulma
    // sayi & 1 ifadesi sayının en sağdaki bitini kontrol eder.
    // En sağdaki bit 1 ise sayı tektir, 0 ise çifttir.
    // --------------------------------------------------
    if ((sayi & 1) == 1)
        printf("\nSayi tektir.\n");
    else
        printf("\nSayi cifttir.\n");

    // --------------------------------------------------
    // 4. ADIM: Sayıdaki 1 bitlerinin adedini bulma
    // Her biti tek tek kontrol ediyoruz.
    // --------------------------------------------------
    for (i = 0; i < 8; i++)
    {
        maske = 1 << i;

        if ((sayi & maske) != 0)
        {
            birSayisi++;
        }
    }

    printf("Sayidaki 1 bitlerinin sayisi: %d\n", birSayisi);

    // --------------------------------------------------
    // 5. ADIM: Kullanıcıdan kontrol edilecek bit pozisyonunu alma
    // Bit pozisyonları 0'dan başlar.
    // 0. bit en sağdaki bittir.
    // --------------------------------------------------
    printf("\nKontrol etmek istediginiz bit pozisyonunu giriniz (0-7): ");
    scanf("%d", &bitPozisyonu);

    maske = 1 << bitPozisyonu;

    if ((sayi & maske) != 0)
        printf("%d. bit 1'dir.\n", bitPozisyonu);
    else
        printf("%d. bit 0'dir.\n", bitPozisyonu);

    // --------------------------------------------------
    // 6. ADIM: Kullanıcıdan 1 yapılacak bit pozisyonunu alma
    // OR işlemi kullanılır.
    // x | 1 ilgili biti 1 yapar.
    // --------------------------------------------------
    printf("\n1 yapmak istediginiz bit pozisyonunu giriniz (0-7): ");
    scanf("%d", &bitPozisyonu);

    maske = 1 << bitPozisyonu;

    sayi = sayi | maske;

    printf("Bit guncellendikten sonraki sayi: %u\n", sayi);

    printf("Yeni 8 bitlik ikilik gosterim: ");

    for (i = 7; i >= 0; i--)
    {
        maske = 1 << i;

        if ((sayi & maske) != 0)
            printf("1");
        else
            printf("0");
    }

    return 0;
}