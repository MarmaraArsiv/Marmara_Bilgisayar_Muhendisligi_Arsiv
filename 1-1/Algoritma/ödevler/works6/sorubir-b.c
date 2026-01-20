#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomsayiuret();

int main() {
    srand(time(NULL)); // sadece 1 kez

    int i, k;
    int a[2][2];//dizilerin tanýmlanmasý
    int b[2][2];
    int c[2][2];


    // A matrisi
    printf("A matrisi:\n");
    for(i = 0; i < 2; i++){
        for(k = 0; k < 2; k++){
            a[i][k] = randomsayiuret();
            printf("%d ", a[i][k]);
        }
        printf("\n");
    }

    // b matrisi
    printf("\nB matrisi:\n");
    for(i = 0; i < 2; i++){
        for(k = 0; k < 2; k++){
            b[i][k] = randomsayiuret();
            printf("%d ", b[i][k]);
        }
        printf("\n");
    }

    // c = a + b
    printf("\nC matrisi (A + B):\n");
    for(i = 0; i < 2; i++){
        for(k = 0; k < 2; k++){
            c[i][k] = a[i][k] + b[i][k];
            printf("%d ", c[i][k]);
        }
        printf("\n");
    }

    return 0;
}

int randomsayiuret() { //belli bir aralýkta random sayý ürettirme kodu
    int r;
    do {
        r = rand();
    } while(r < 12 || r > 150);

    return r;
}

