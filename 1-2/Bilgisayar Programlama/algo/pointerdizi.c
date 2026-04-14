#include <stdio.h>

int main()
{

    // int arr[3] = {10, 20, 30};
    // int *p = arr;

    // printf("%d\n", *p);       // 10
    // printf("%d\n", *(p + 1)); // 20
    // printf("%d\n", *(p + 2)); // 30


    // int arr[] = {2, 6, 12};
    // int *p = arr;

    // p++;              
    // printf("%d\n", *p);

    
    // char dizi[] = "Ahmet";
    // char *ptr = "Mehmet";
    // printf("Dizi: %s\n", dizi);
    // printf("Pointer: %s\n", ptr);

    char isim[3];
    printf("adres: %p\n", isim);
    printf("adres: %p\n", isim+1);
    printf("adres: %p\n", &isim+1);

}