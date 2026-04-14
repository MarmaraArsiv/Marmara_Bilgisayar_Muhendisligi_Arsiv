#include <stdio.h>
#include <stdlib.h>

// Function to print a greeting and sum 1..100
void Hello() {
    int t = 0;
    printf("Merhaba Dunyaliar\n");

    for (int i = 1; i <= 100; i++) {
        t += i;
    }

    printf("toplam = %d\n", t);
}

// Function to add two integers dynamically
int *add(int *a, int *b) {
    int *c = malloc(sizeof(*c));
    *c = *a + *b;
    return c;
}

int main() {
    int a = 12, b = 4;

    // dynamically compute sum
    int *p = add(&a, &b);
    printf("Toplam = %d\n", *p);

    Hello();

    // print p again to show value persists
    printf("Toplam = %d\n", *p);

    // free allocated memory
    free(p);

    return 0;
}