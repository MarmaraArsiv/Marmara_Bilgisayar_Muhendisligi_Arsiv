#include <stdio.h>

int main()
{
    int x = 10;
    int *p = &x;
    int **pp = &p;

    printf("%d\n", x);

    printf("%d\n", *p);
    
    
    printf("%p\n", pp);
}