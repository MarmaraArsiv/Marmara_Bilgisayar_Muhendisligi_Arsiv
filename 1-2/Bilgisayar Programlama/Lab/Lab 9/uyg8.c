/*
Soru 8: Basit Yoklama Kayıt Sistemi

Kullanıcıdan 5 öğrencinin adı ve yoklama durumu alınacaktır. Durum değeri G ise geldi, K ise gelmedi anlamına gelsin. Bilgiler yoklama.txt dosyasına yazılsın. Daha sonra dosyadan okunarak gelen ve gelmeyen öğrenci sayısı bulunsun.

Çözüm Mantığı
Dosya yazma modunda açılır.
5 öğrenci için ad ve durum bilgisi alınır.
Bilgiler dosyaya yazılır.
Dosya okuma modunda açılır.
G ve K değerleri sayılır.
*/

#include <stdio.h>

int main()
{
    FILE *dosya;

    char ad[50];
    char durum;

    int i;
    int gelen = 0;
    int gelmeyen = 0;

    // --------------------------------------------------
    // 1. ADIM: yoklama.txt dosyasını oluşturuyoruz
    // --------------------------------------------------
    dosya = fopen("yoklama.txt", "w");

    if (dosya == NULL)
    {
        printf("yoklama.txt dosyasi olusturulamadi!\n");
        return 1;
    }

    // Kullanıcıdan 5 öğrencinin yoklama bilgisi alınır.
    for (i = 0; i < 5; i++)
    {
        printf("%d. ogrencinin adi: ", i + 1);
        scanf("%s", ad);

        printf("Durum giriniz (G: geldi, K: gelmedi): ");
        scanf(" %c", &durum);

        fprintf(dosya, "%s %c\n", ad, durum);
    }

    fclose(dosya);

    // --------------------------------------------------
    // 2. ADIM: yoklama.txt dosyasını okuyoruz
    // --------------------------------------------------
    dosya = fopen("yoklama.txt", "r");

    if (dosya == NULL)
    {
        printf("yoklama.txt dosyasi okuma icin acilamadi!\n");
        return 1;
    }

    while (fscanf(dosya, "%s %c", ad, &durum) != EOF)
    {
        if (durum == 'G' || durum == 'g')
        {
            gelen++;
        }
        else if (durum == 'K' || durum == 'k')
        {
            gelmeyen++;
        }
    }

    fclose(dosya);

    printf("Gelen ogrenci sayisi: %d\n", gelen);
    printf("Gelmeyen ogrenci sayisi: %d\n", gelmeyen);

    return 0;
}