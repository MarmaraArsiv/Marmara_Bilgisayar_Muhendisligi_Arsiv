#include <stdio.h>
#include <string.h>


void diziYazdir(int dizi[], int boyut) {
    for (int i = 0; i < boyut; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");
}

int diziToplam(int *dizi, int boyut) {
    int toplam = 0;

    for (int i = 0; i < boyut; i++) {
        toplam += dizi[i];
    }

    return toplam;
}

void diziDegistir(int dizi[], int boyut) {
    for (int i = 0; i < boyut; i++) {
        dizi[i] *= 2;
    }
}


void stringYazdir(char str[]) {
    printf("String: %s\n", str);
}

int stringUzunluk(char *str) {
    int sayac = 0;

    while (str[sayac] != '\0') {
        sayac++;
    }

    return sayac;
}



int main() {

    int sayilar[5] = {10, 20, 30, 40, 50};
    diziYazdir(sayilar, 5);

    int toplam = diziToplam(sayilar, 4);
    printf("Toplam: %d\n", toplam);

    diziDegistir(sayilar, 5);
    
    diziYazdir(sayilar, 5);


    // char isim[] = "Marmara";
    // stringYazdir(isim);

    // int len = stringUzunluk(isim);
    // printf("Uzunluk: %d\n", len);

    return 0;
}



/* =====================================================
   FONKSİYON TANIMLARI
   ===================================================== */

// 1️⃣ Dizi yazdırma




// 2️⃣ Dizi elemanları toplamı




// 3️⃣ Diziyi fonksiyon içinde değiştirme



