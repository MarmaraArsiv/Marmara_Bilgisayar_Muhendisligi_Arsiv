#include <stdio.h>

void degistir(int *a) {
    *a = 10;
}

int main() {
    
    int x = 5;
    
    degistir(&x);

    printf("x degeri = %d", x);
}