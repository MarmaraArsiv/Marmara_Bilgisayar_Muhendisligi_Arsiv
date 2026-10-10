#include <stdio.h>//ana kütüphaneyi projeye ekliyoruz.

int main() {//ana fonksiyonumuzu oluþturuz
    int a = 10, c;//a ve c deðiþkenlerini oluþturuyoruz a yý 10 yapýyoruz.

    c = a;//c yi a ya eþitliyoruz
    printf("c = %d\n", c);//ekrana "c = 10" deðeri yazacak

    c = ++a;//a yý önce bir arttýracak sonra c ye eþitleyecek(c þuan 11 oldu, a þuan 11 oldu)
    printf("c = %d\n", c);//ekrana "c = 11" deðeri yazýlacak

    c = a++; //a'yý önce atar c=11 olur sonra a deðeri bir artar ve 12 olur
    printf("c = %d\n", c);//ekrana "c = 11" yazýlacak

    c = a--;//a yý önce c'ye eþitlenecek sonra bir azaltýlacak(c þuan 12 oldu, a þuan 11 oldu)
    printf("c = %d\n", c);//ekrana "c = 12" yazýlacak

    c = --a; //a yý önce bir azaltacak sonra c ye eþitleyecek(c þuan 10 oldu, a þuan 10 oldu)
    printf("c = %d\n", c);//ekrana "c = 10" deðeri yazacak

    return 0;//bu kod fonksiyonu bitirir.
}



