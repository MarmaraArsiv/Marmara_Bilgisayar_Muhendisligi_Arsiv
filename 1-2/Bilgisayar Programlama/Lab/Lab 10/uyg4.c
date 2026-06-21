/*Belirli Bir Öğrenci Kaydını Güncelleme

ogrenciler.dat adlı binary dosyada öğrenci kayıtları bulunmaktadır.
Kullanıcıdan güncellenecek öğrenci sıra numarası alınsın.
Program doğrudan ilgili kayda giderek öğrencinin yeni notunu alsın ve 
dosyadaki eski notu güncellesin.*/

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
    int sira;
    float yeniNot;

    // --------------------------------------------------
    // 1. ADIM: Dosyayı hem okuma hem yazma modunda açıyoruz
    // rb+: binary dosyada okuma ve yazma yapılabilir
    // --------------------------------------------------
    dosya = fopen("ogrenciler.dat", "rb+");

    if (dosya == NULL)
    {
        printf("ogrenciler.dat dosyasi acilamadi!\n");
        return 1;
    }

    // --------------------------------------------------
    // 2. ADIM: Kullanıcıdan güncellenecek öğrenci sırasını alıyoruz
    // --------------------------------------------------
    printf("Guncellenecek ogrenci sirasini giriniz: ");
    scanf("%d", &sira);

    // --------------------------------------------------
    // 3. ADIM: İstenen öğrencinin dosyadaki konumuna gidiyoruz
    // --------------------------------------------------
    fseek(dosya, (sira - 1) * sizeof(Ogrenci), SEEK_SET);

    // --------------------------------------------------
    // 4. ADIM: Mevcut kaydı okuyoruz
    // fread(adres, boyut, adet, dosya)
    // --------------------------------------------------
    fread(&ogrenci, sizeof(Ogrenci), 1, dosya);

    printf("\nMevcut Ogrenci Bilgileri:\n");
    printf("Numara: %d\n", ogrenci.no);
    printf("Ad: %s\n", ogrenci.ad);
    printf("Not: %.2f\n", ogrenci.not);

    // --------------------------------------------------
    // 5. ADIM: Yeni not bilgisini kullanıcıdan alıyoruz
    // --------------------------------------------------
    printf("\nYeni notu giriniz: ");
    scanf("%f", &yeniNot);

    ogrenci.not = yeniNot;

    // --------------------------------------------------
    // 6. ADIM: fread işleminden sonra dosya göstergeci bir kayıt ilerlemiştir.
    // Bu yüzden aynı kaydın başına tekrar dönmemiz gerekir.
    // --------------------------------------------------
    fseek(dosya, (sira - 1) * sizeof(Ogrenci), SEEK_SET);

    // --------------------------------------------------
    // 7. ADIM: Güncellenmiş öğrenci kaydını aynı konuma yazıyoruz
    // --------------------------------------------------
    fwrite(&ogrenci, sizeof(Ogrenci), 1, dosya);

    printf("\nOgrenci notu basariyla guncellendi.\n");

    fclose(dosya);

    return 0;
}