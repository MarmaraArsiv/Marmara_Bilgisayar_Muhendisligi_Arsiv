#include <stdio.h>//temel kütüphaneleri ekliyoruz
#include <stdlib.h>//temel kütüphaneleri ekliyoruz


int main() {//fonksiyonu oluþturuyoruz
float baslangic=70000.0,faiz=1.134;int sayac=0;//deðiþkenleri oluþturuyoruz

while(baslangic<150000){//baslangic 
	baslangic = baslangic*faiz;//yýllýk faizi bütçeye uyguluyoruz
	sayac++;//yýl sayacýný arttýrýyoruz
}
printf("%d",sayac);//sonucu ekrana yazdýrýyoruz
	return 0;//fonksiyonun bir deðerle dönmesini saðlýyoruz
}
