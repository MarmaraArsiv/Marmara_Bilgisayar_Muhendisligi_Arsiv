/*
Soru 10: Reçete Kayıt Sistemi
Bir eczane için reçete kayıt sistemi yazınız. Kullanıcıdan müşteri adı, ilaç adı ve dozaj bilgisi alınız. Bu bilgileri receteler.txt dosyasının sonuna ekleyiniz. Program her çalıştığında eski reçeteleri silmeden yeni reçete eklemelidir.
Çözüm Mantığı
Dosya "a" modunda açılır. 
Kullanıcıdan müşteri adı, ilaç adı, dozaj bilgisi alınır. 
Bilgiler dosyanın sonuna eklenir. Dosya kapatılır. 
*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *dosya;

    char musteriAdi[100];
    char ilacAdi[100];
    char dozaj[100];

    // --------------------------------------------------
    // 1. ADIM: receteler.txt dosyasını ekleme modunda açıyoruz
    // --------------------------------------------------
    // "a" modu dosya yoksa oluşturur.
    // Dosya varsa eski bilgileri silmeden sonuna ekleme yapar.
    dosya = fopen("receteler.txt", "a");

    if (dosya == NULL)
    {
        printf("receteler.txt dosyasi acilamadi!\n");
        return 1;
    }

    printf("Musteri adi: ");
    fgets(musteriAdi, sizeof(musteriAdi), stdin);
    musteriAdi[strcspn(musteriAdi, "\n")] = '\0';

    printf("Ilac adi: ");
    fgets(ilacAdi, sizeof(ilacAdi), stdin);
    ilacAdi[strcspn(ilacAdi, "\n")] = '\0';

    printf("Dozaj bilgisi: ");
    fgets(dozaj, sizeof(dozaj), stdin);
    dozaj[strcspn(dozaj, "\n")] = '\0';

    // Reçete bilgileri dosyaya düzenli biçimde eklenir.
    fprintf(dosya, "Musteri: %s\n", musteriAdi);
    fprintf(dosya, "Ilac: %s\n", ilacAdi);
    fprintf(dosya, "Dozaj: %s\n", dozaj);
    fprintf(dosya, "-------------------------\n");

    fclose(dosya);

    printf("Recete bilgisi dosyaya eklendi.\n");

    return 0;
}