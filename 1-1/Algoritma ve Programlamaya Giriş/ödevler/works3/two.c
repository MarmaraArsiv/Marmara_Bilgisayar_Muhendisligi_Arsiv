#include <stdio.h>//Kütüphaneleri tanýmlýyoruz

int main() { //Ana fonksiyonumuzu ekliyoruz
    float vize, final, ortalama; //Deðiþkenleri tanýmlýyoruz

    printf("Vize notunu giriniz: ");//Kullanýcýdan vize notunu istiyoruz
    scanf("%f", &vize);//vize notunu kullanýcýdan alýyoruz

    printf("Final notunu giriniz: ");//Kullanýcýdan vize notunu istiyoruz
    scanf("%f", &final);//final notunu kullanýcýdan alýyoruz

    ortalama = vize * 0.40 + final * 0.60;//Aðýrlýklý ortalamalarýný alýyoruz

    printf("Ortalama: %.2f\n", ortalama);//Ortalamayý yazdýrýyoruz

    if (ortalama >= 60) {//Sonuçlarý belirleyen karar satýrý
        printf("Durum: gecti\n");//Sonuçlarý yazdýrýyoruz
    } else {
        printf("Durum: kaldi\n");//Sonuçlarý yazdýrýyoruz
    }

    return 0;//Fonksiyonu sonlandýrýyoruz
}
