#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
int max,ikinci,ucuncu,i;
srand(time(NULL));//rasgele sayý üretme kodu
int sayilar[50];

for(i=0;i<50;i++){
	 sayilar[i]= rand()%1000; //1000 den büyük sonuçlar çýkmasýn diye mod 1000 yaptým
	
}
max = sayilar[0];//baþlangýç deðerleri bunlar pek mühim deðil ama dizinin içinden olmasý faydalý (dizinin dýþýna çýkma riski yok)
ikinci= sayilar[1];
ucuncu= sayilar[2];

if(ikinci>max){int t=max; max=ikinci;ikinci=t;}//buradaki if döngülerinde deðiþkenlerimizi aralarýnda sýralýyoruz
if(ucuncu>ikinci){int t=ikinci; ikinci=ucuncu;ucuncu=t;}
if(ucuncu>max){int t=max; max=ucuncu;ucuncu=t;}

for(i=0;i<50;i++){//Bu for döngüsünün içinde sayý dizisindeki kalan tüm deðerleri karþýlaþtýrýyoruz
        if(sayilar[i] > max){
            ucuncu = ikinci;
            ikinci = max;
            max = sayilar[i];
        }
        else if(sayilar[i] > ikinci){
            ucuncu = ikinci;
            ikinci = sayilar[i];
        }
        else if(sayilar[i] > ucuncu){
            ucuncu = sayilar[i];
        }
}

printf("maximum: %d\nikinci buyuk:%d\nUcuncu buyuk: %d",max,ikinci,ucuncu);//deðerleri yazdýrýyorum.
    return 0;
}

