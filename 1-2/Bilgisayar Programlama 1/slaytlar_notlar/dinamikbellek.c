#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n = 5;

    //malloc
    arr = (int *)malloc(n * sizeof(int));
    //arr = malloc(n * sizeof(int));
    //arr = malloc(n * sizeof(*arr));
    for (int i = 0; i < n; i++) 
        arr[i] = i + 5;
    printf("malloc: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);

    // calloc
    // int *arr2 = (int *)calloc(5, sizeof(int));
    // printf("calloc: ");
    // for (int i = 0; i < 5; i++) 
    //     printf("%d ", arr2[i]);
    // printf("\n");
    // free(arr2);

    // // realloc
    // arr = realloc(arr, 5 * sizeof(int));

    // arr[3] = 4; arr[4] = 5;
    // printf("realloc: ");
    // for (int i = 0; i < 5; i++) 
    //     printf("%d ", arr[i]);
    // printf("\n");
    // free(arr);
    
    return 0;
}