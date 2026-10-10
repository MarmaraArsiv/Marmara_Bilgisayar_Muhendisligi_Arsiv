#include <stdio.h>
#include <stdlib.h>

	int dizibir[100]={};//dizileri tanýmlýyoruz
	int diziiki[100]={};
	
	int diziveri(int dizi[],int diziNo);//fonksiyonlarý burada tanýmlýyoruz 
	int dizidearama(int uzunluk, int dizi[], int aranan);
	int ortakeleman(int dizi1[], int boyut1, int dizi2[], int boyut2);

	int main() {//ana fonksiyonumuz
	
    int uzunlukbir = 0, uzunlukiki = 0;
    
    uzunlukbir = diziveri(dizibir, 1);
    uzunlukiki = diziveri(diziiki, 2);
    
	int ortakSayi = ortakeleman(dizibir, uzunlukbir, diziiki, uzunlukiki);
    printf("\nOrtak eleman sayisi: %d\n", ortakSayi);

	return 0;
	}
	

	
int diziveri(int dizi[], int diziNo) {//dizilerimize veri girmek için kullandýðýmýz fonksiyon
    int i, uzunluk;
    
    printf("\n--Dizi %d--\n", diziNo);//dizinin uzunluðunu konsoldan alýyoruz
    printf("Dizinin uzunlugunu giriniz: ");
    scanf("%d", &uzunluk);
    
    printf("%d. dizinin elemanlarini giriniz:\n", diziNo);
    for(i = 0; i < uzunluk; i++) {//dizinin elemanlarýný konsoldan alýyoruz
        printf("%d. eleman: ", i + 1);
        scanf("%d", &dizi[i]);
    }
    
    // Girilen diziyi konsola yazdýrýyoruz
    printf("%d. dizi: ", diziNo);
    for(i = 0; i < uzunluk; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");
    
    return uzunluk;  // Uzunluðu geri döndür
}
    
int dizidearama(int uzunluk,int dizi[],int aranan){//arama fonksiyonumuz

int i = 0; 
for(i;i<uzunluk; i++){
	if(dizi[i]==aranan){
	return 1; //aranan deðer bulundu

	}
}
return 0;//aranan deðer bulunamadý
}

int ortakeleman(int dizi1[], int boyut1, int dizi2[], int boyut2) {//ortak eleman tespit eden fonksiyon
    int i, sayac = 0;
    for(i = 0; i < boyut1; i++) {
        if(dizidearama(boyut2, dizi2, dizi1[i]) == 1) {//dizidearama fonksiyonuyla entegre çalýþýyor
            sayac++;
        }
    }
    
    return sayac;
}
