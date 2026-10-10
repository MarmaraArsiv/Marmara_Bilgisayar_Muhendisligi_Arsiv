#include <stdio.h>//temel kütüphaneyi ekliyoruz
#include <stdlib.h>//temel kütüphaneyi ekliyoruz
#include <time.h>//random sayý üretmek için kütüphane ekliyoruz
#include <stdbool.h>//bool veri tipi için kütüphane ekliyoruz

int main() {//fonksiyonu oluþturuyoruz
    srand(time(NULL));//her seferinde farklý random sayý üretmek için
    int sayi = rand() % 100;//0-99 arasý random sayý üretiyoruz
    printf("Random sayý uretildi (0-99 arasi)\n");//kullanýcýya bilgi veriyoruz
    
    int kullanici, sayac = 0;//kullanýcýnýn tahmini ve deneme sayýsý için deðiþken oluþturuyoruz
    bool x = false;//doðru tahmin yapýlýp yapýlmadýðýný kontrol etmek için bool deðiþken oluþturuyoruz
    int s = 5;
    for(s; s >= 1; s--) {//kullanýcýya 5 tahmin hakký vermek için döngü oluþturuyoruz
        printf("Tahmininizi giriniz: ");//kullanýcýdan tahmin istiyoruz
        scanf("%d", &kullanici);//girdiði tahmini kullanici deðiþkenine atýyoruz
        
        if(kullanici > sayi){//eðer tahmin büyükse
            printf("Daha kucuk bir deðer giriniz. Kalan hakkiniz %d\n", s-1);//küçük deðer girmesini söylüyoruz
        }
        else if(kullanici < sayi){//eðer tahmin küçükse
            printf("Daha buyuk bir deðer giriniz. Kalan hakkiniz %d\n", s-1);//büyük deðer girmesini söylüyoruz
        }
        else if(kullanici == sayi){//eðer tahmin doðruysa
            x = true;//x deðiþkenini true yapýyoruz
        }
        
        if(x){//eðer doðru tahmin yapýldýysa
            printf("tebrikler doðru bildiniz\n");//tebrik mesajý yazdýrýyoruz
            break;//döngüden çýkýyoruz
        }
    }
    
    if(!x){//eðer doðru tahmin yapýlmadýysa
        printf("Tahmin hakkýnýz bitti. Dogru sayý: %d\n", sayi);//doðru sayýyý gösteriyoruz
    }
    
    return 0;//fonksiyonun bir deðerle dönmesini saðlýyoruz
}
