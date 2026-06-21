/*
Soru 4: Dosyadaki En Uzun Satırı Bulma

dersnotlari.txt adlı dosyada birden fazla satır bulunmaktadır. Dosyadaki en uzun satırı ve bu satırın karakter sayısını bulan C programını yazınız.

Çözüm Mantığı
Dosya önce yazma modunda ardından okuma modunda açılır.
fgets() ile satır satır okuma yapılır.
Her satırın uzunluğu hesaplanır.
En uzun satır saklanır.
Dosya sonunda en uzun satır ekrana yazdırılır.*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *dosya;
    FILE *olustur; // Dosya oluşturmak için

    char satir[300];
    char enUzunSatir[300];

    int uzunluk;
    int enUzun = 0;

    // --------------------------------------------------
    // 1. ADIM: dersnotlari.txt dosyasını oluştur ve veri yaz
    // --------------------------------------------------
    olustur = fopen("dersnotlari.txt", "w");

    if (olustur == NULL)
    {
        printf("dersnotlari.txt dosyasi olusturulamadi!\n");
        return 1;
    }

    // Örnek satırlar yazıyoruz (farklı uzunlukta)
    fprintf(olustur, "Kisa satir\n");
    fprintf(olustur, "Bu biraz daha uzun bir satirdir\n");
    fprintf(olustur, "C programlama dersindeyiz\n");
    fprintf(olustur, "Bu satir digerlerinden cok daha uzun olabilir\n");

    fclose(olustur);

    // --------------------------------------------------
    // 2. ADIM: Dosyayı okuma modunda aç
    // --------------------------------------------------
    dosya = fopen("dersnotlari.txt", "r");

    if (dosya == NULL)
    {
        printf("dersnotlari.txt dosyasi acilamadi!\n");
        return 1;
    }

    // En uzun satırı başlangıçta boş kabul ediyoruz.
    enUzunSatir[0] = '\0';

    // --------------------------------------------------
    // 3. ADIM: Satır satır okuma ve karşılaştırma
    // --------------------------------------------------
    while (fgets(satir, sizeof(satir), dosya) != NULL)
    {
        // Okunan satırın uzunluğu bulunur
        uzunluk = strlen(satir);

        // Satır sonundaki '\n' karakterini sayıya dahil etmeyelim
        if (uzunluk > 0 && satir[uzunluk - 1] == '\n')
        {
            uzunluk--;
        }

        // Eğer bu satır daha uzunsa kaydet
        if (uzunluk > enUzun)
        {
            enUzun = uzunluk;
            strcpy(enUzunSatir, satir);
        }
    }

    fclose(dosya);

    // --------------------------------------------------
    // 4. ADIM: Sonucu yazdır
    // --------------------------------------------------
    printf("En uzun satir:\n%s", enUzunSatir);
    printf("Karakter sayisi: %d\n", enUzun);

    return 0;
}