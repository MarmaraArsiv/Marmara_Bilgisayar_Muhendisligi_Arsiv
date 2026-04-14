#include <stdio.h>

int main() {
    
    // int x = 10;
    // int *p = &x;

    // printf("x'in degeri: %d\n", x);
    // printf("x'in adresi: %p\n", &x);
    // printf("p'nin tuttugu adres: %p\n", p);
    // printf("p'nin gosterdigi deger: %d\n", *p);


    int x = 5;
    int *p = &x;

    *p = 20;   // x artık 20 olur

    printf("x'in degeri: %d\n", x);

    return 0;
}