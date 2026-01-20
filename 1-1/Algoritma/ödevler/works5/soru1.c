 #include <stdio.h>

int main() {
    char word[100];
    int i = 0, uzunluk = 0;

    scanf("%s", word);//kullanýcadan kelimemizi alýyoruz

    while (word[uzunluk] != '\0') {// bu for ile dizimizin içindeki kelimenin uzunluðunu hesaplýyoruz
        uzunluk++;
    }
    printf("Tersi: ");
    for (i = uzunluk - 1; i >= 0; i--) { //dizideki kelimeyi for ile tersten yazdýrýyoruz.
        printf("%c", word[i]);
    }

    return 0;
}

