#include <stdio.h>//main kütüphaneler
#include <stdlib.h>//main kütüphaneler

int main() {
    int i, j, k;//for döngüleri için gereken deðiþkenler
    int satir = 25; // kaç satýr olacaðýný ayarlýyoruz

    for(i = 1; i <= satir; i++) {//satýr döngüsü
        for(j = 1; j <= satir - i; j++) {  //eklenece boþluk sayýsýný ayarlar
            printf(" ");// boþluklarý ekliyoruz
        }
        for(k = 1; k <= (2*i - 1); k++) {  //bu for kaç tane yýldýz ekleneceðini ayarlar piramitte 1,3,5,7,9 diye gider bu sayý ondan 2i-1 dedim
            printf("*");// yýldýzlarý ekliyoruz
        }
        printf("\n");//satýr atlamak maksatlý
    }

    return 0;//fonksiyondan çýkýþ 
}

