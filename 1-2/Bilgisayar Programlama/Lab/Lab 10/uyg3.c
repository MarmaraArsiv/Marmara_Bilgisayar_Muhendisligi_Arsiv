/*
Rastgele Erişimli Öğrenci Kayıt Dosyası Oluşturma ve Okuma

Bir öğrencinin numarası, adı ve notu bilgilerini tutan bir struct tanımlayınız.
5 öğrencinin bilgilerini ogrenciler.dat adlı binary dosyaya fwrite() ile yazınız.
Daha sonra kullanıcıdan bir öğrenci sıra numarası alarak sadece o öğrencinin kaydını 
fseek() ve fread() ile okuyup ekrana yazdırınız.
*/

#include <stdio.h>

typedef struct
{
    int no;
    char ad[30];
    float not;
} Ogrenci;

int main()
{
    FILE *dosya;
    Ogrenci ogrenci;
    int i;
    int sira;

    // --------------------------------------------------
    // 1. ADIM: Binary dosyayı yazma modunda açıyoruz
    // wb: write binary
    // --------------------------------------------------
    dosya = fopen("ogrenciler.dat", "wb");

    if (dosya == NULL)
    {
        printf("Dosya olusturulamadi!\n");
        return 1;
    }

    // --------------------------------------------------
    // 2. ADIM: 5 öğrencinin bilgilerini kullanıcıdan alıyoruz
    // --------------------------------------------------
    for (i = 0; i < 5; i++)
    {
        printf("\n%d. ogrencinin numarasini giriniz: ", i + 1);
        scanf("%d", &ogrenci.no);

        printf("%d. ogrencinin adini giriniz: ", i + 1);
        scanf("%s", ogrenci.ad);

        printf("%d. ogrencinin notunu giriniz: ", i + 1);
        scanf("%f", &ogrenci.not);

        // --------------------------------------------------
        // 3. ADIM: Öğrenci kaydını binary dosyaya yazıyoruz
        // fwrite(adres, boyut, adet, dosya)
        // --------------------------------------------------
        fwrite(&ogrenci, sizeof(Ogrenci), 1, dosya);
    }

    fclose(dosya);

    // --------------------------------------------------
    // 4. ADIM: Kullanıcıdan okunacak öğrenci sırasını alıyoruz
    // --------------------------------------------------
    printf("\nBilgilerini okumak istediginiz ogrenci sirasini giriniz (1-5): ");
    scanf("%d", &sira);

    // --------------------------------------------------
    // 5. ADIM: Dosyayı okuma modunda açıyoruz
    // rb: read binary
    // --------------------------------------------------
    dosya = fopen("ogrenciler.dat", "rb");

    if (dosya == NULL)
    {
        printf("Dosya acilamadi!\n");
        return 1;
    }

    // --------------------------------------------------
    // 6. ADIM: İstenen öğrencinin kaydına doğrudan gidiyoruz
    // Her kayıt sizeof(Ogrenci) kadar yer kaplar.
    // 1. öğrenci için 0. konuma gidilir.
    // 2. öğrenci için 1 * sizeof(Ogrenci) konumuna gidilir.
    // --------------------------------------------------
    fseek(dosya, (sira - 1) * sizeof(Ogrenci), SEEK_SET);

    // --------------------------------------------------
    // 7. ADIM: O konumdaki bir öğrenci kaydını okuyoruz
    // --------------------------------------------------
    fread(&ogrenci, sizeof(Ogrenci), 1, dosya);

    printf("\n--- Ogrenci Bilgileri ---\n");
    printf("Numara: %d\n", ogrenci.no);
    printf("Ad: %s\n", ogrenci.ad);
    printf("Not: %.2f\n", ogrenci.not);

    fclose(dosya);

    return 0;
}