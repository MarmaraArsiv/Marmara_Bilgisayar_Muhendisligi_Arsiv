#include <stdio.h>

int main()
{
    int *p;
    int **pp;
    int val = 1903;

    // p işaretçisine val adresi atanıyor
    p = &val;
    // pp işaretçisine p işaretçisinin adresi atanıyor
    pp = &p;

    printf("Degerler:\n**********\n");
    printf("val = %d\n", val);
    printf("*p = %d\n", *p);
    printf("**pp = %d\n", **pp);

    printf("\nAdresler:\n**********\n");
    printf("&val = %p\n", &val);
    printf("p = %p\n", p);
    printf("&p = %p\n", &p);
    printf("pp = %p\n", pp);

    return 0;
}