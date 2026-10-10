#include <stdio.h>//main kütüphaneleri ekliyoruz
#include <stdlib.h>//main kütüphaneleri ekliyoruz


int main() {//ana fonksiyonumuzu oluþturuyoruz
	float kenarbir, kenariki, alan,cevre;//deðiþkenlerimizi oluþturuyoruz

    printf("Birinci kenari giriniz: ");//kullanýcýdan dikdörgenin birinci kenarý için veri istiyoruz
    scanf("%f", &kenarbir);//kenarbir deðerini scanf ile alýyoruz
	if(kenarbir<0)//hiç bir dikdörtgen negatif kenarý olamaz 
 	return 0;//fonksiyonu bitirir
     printf("Ikinci kenari giriniz: ");//kullanýcýdan dikdörgenin ikinci kenarý için veri istiyoruz
    scanf("%f", &kenariki);//kenariki deðerini scanf ile alýyoruz
	if(kenariki<0)//hiç bir dikdörtgen negatif kenarý olamaz 
 	return 0;//fonksiyonu bitirir
    cevre= 2*kenarbir+kenariki*2;//çevre hesabý
    alan=kenarbir*kenariki;//alan hesabý
  printf(" alan:");	printf("%f\n",alan);//sonuçlarý yazdýrýyoruz
  printf(" cevre:");	printf("%f\n",cevre);//sonuçlarý yazdýrýyoruz
	  

	  
	return 0;//fonksiyonu bitirir
}
