#include <stdio.h>   // temel kütüphane
#include <stdlib.h>  // temel kütüphane

int main() {

    float boy, kilo; // kullanýcýdan alýnacak deðerler
    float indeks;    // hesaplanacak vücut kitle indeksi

    printf("Boyunuzu metre cinsinden giriniz (örnek: 1.75): ");
    scanf("%f", &boy);//boy verisini kullanýcýdan alýyoruz

    printf("Kilonuzu kilogram cinsinden giriniz: ");
    scanf("%f", &kilo);//kg verisini kullanýcýdan alýyoruz

    indeks = kilo / (boy * boy); //verilen formüle gore indeks hesaplamasý yapýyoruz

    printf("\nVücut Kitle Ýndeksiniz: %.2f\n", indeks);

    // sorudaki tabloya göre deðerlendirme
    if (indeks < 18.5) {
        printf("Durum: Zayýf\n");
    }
    else if (indeks >= 18.5 && indeks <= 24.9) {
        printf("Durum: Normal\n");
    }
    else if (indeks >= 25 && indeks <= 29.9) {
        printf("Durum: Fazla Kilolu\n");
    }
    else if (indeks >= 30 && indeks <= 34.9) {
        printf("Durum: 1. Derece Obez\n");
    }
    else if (indeks >= 35 && indeks <= 39.9) {
        printf("Durum: 2. Derece Obez\n");
    }
    else if (indeks >= 40) {
        printf("Durum: 3. Derece (Morbid) Obez\n");
    }

    return 0; //fonksiyona bir çýkýþ deðeri veriyoruz
}

