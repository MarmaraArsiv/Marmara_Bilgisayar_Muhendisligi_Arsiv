#include <stdio.h>//kütüphane ekleme

int main() {//fonksiyonun oluþturulmasý
    int x = 10, y = 3;//deðiþken tanýmlamak
    x %= y; //burada x i 10 mod 3 deðerine yani 1 e eþitliyoruz
    y += x * 2; //burada y ye x*2 ekliyoruz x az önce 1 olduðu için y nin yeni deðeri 3+2 den 5 oluyor
    printf("%d %d", x, y);//çýktýmýz 1 ve 5 olucaktýr.
    return 0;//bu kod fonksiyonu bitirir
}

