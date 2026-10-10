#include <stdio.h>
#include <string.h>

int main() {
    // int a;
    // char karakter;
    // printf("Bir karakter girin: ");
    // scanf("%d", &a);   // bosluga dikkat
    // scanf(" %c", &karakter);   // bosluga dikkat
    // printf("Girilen karakter: %c\n", karakter);

    // char isim[20];
    // printf("Isminizi girin: ");
    // scanf("%s", isim); 
    // printf("Girilen isim: %s\n", isim);


    char isim[] = "Marmara";
    printf("Isim: %s\n", isim);

    for (int i = 0; isim[i] != '\0'; i++) {
        printf("isim[%d] = %c\n", i, isim[i]);
    }


    return 0;
}