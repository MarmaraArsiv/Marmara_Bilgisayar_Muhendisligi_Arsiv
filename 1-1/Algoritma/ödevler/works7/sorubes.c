#include <stdlib.h>
int main() {
    
    char myStr1[100];
    char myStr2[100];//dizilerimizi tanýmlýyoruz
    printf("Birinci degeri giriniz ");
    gets(myStr1); //dizilere consoledan veri alýyoruz
    printf("Ikinci degeri giriniz ");
    gets(myStr2);
    
    int i = 0, j=0; //for döngüleri için degiskenler
    for (i; myStr1[i]; i++){//bu for döngüsü girilen degerin tum karekterlerini buyuk harf yapýyor
        myStr1[i] = toupper(myStr1[i]);
    }
    
    for (j; myStr2[j]; j++){//bu for döngüsü girilen degerin tum karekterlerini buyuk harf yapýyor
        myStr2[j] = toupper(myStr2[j]);
    }
    
    int cmp = strcmp(myStr1, myStr2); //strcmp fonksiyonuna elimizdeki verileri veriyoruz
    if(cmp==0) { //fonksiyonun cýktýsý 1 se ikisi esittir
        printf("\nGirilenler birbirlerine esittir \n");
    }
    else{ //1 degilse esit degildirler
     printf("\nGirilenler esit degildir \n");
    if(cmp < 0){//fonksiyonun cýktýlarýna göre alfabetik sýralama yaptýrýyoruz.
        printf("Alfabetik sirada once gelen: %s\n", myStr1);
    }
    else{
        printf("Alfabetik sirada once gelen: %s\n", myStr2);
    }
     
    }
    return 0;
}
