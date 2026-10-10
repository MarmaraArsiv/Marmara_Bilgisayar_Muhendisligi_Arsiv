#include <stdio.h>
#include <string.h> // strlen fonksiyonu için lazim

void alfabetikSirala(char dizgi[]);

int main() {
    char metin[100]; // diziyi tanimliyoruz

    printf("Bir karakter dizisi (string) giriniz: ");
    scanf("%s", metin);

    alfabetikSirala(metin);//fonksiyonu çagiriyoruz


    printf("Alfabetik siralanmis hali: %s\n", metin);
    
    // b) Sýralanmýþ dizi üzerinde en büyükleri bulma
    int uzunluk = strlen(metin);

    // En az 3 karakter girildiðini kontrol ediyoruz
    if (uzunluk >= 3) {
        printf("-------------------------------\n");
        printf("En buyuk 1. karakter: %c\n", metin[uzunluk - 1]); // Son karakter
        printf("En buyuk 2. karakter: %c\n", metin[uzunluk - 2]); 
        printf("En buyuk 3. karakter: %c\n", metin[uzunluk - 3]); 
        printf("-------------------------------\n");
    } else {
        printf("Hata: En az 3 karakter iceren bir kelime girmelisiniz.\n");
    }

    return 0;
}


void alfabetikSirala(char dizgi[]) {// Bubble Sort ile sýralama
    int n = strlen(dizgi);
    int i, j;
    char gecici;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            // Harfler ASCI tablosunda sayisal degerler ifade ederler bu ozelligi kullanarak siralama yapýyoruz.
            if (dizgi[j] > dizgi[j + 1]) {
                gecici = dizgi[j];
                dizgi[j] = dizgi[j + 1];
                dizgi[j + 1] = gecici;
            }
        }
    }
}
