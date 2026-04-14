#include <stdio.h>
#include <string.h>

int main() {
    
    char a[20] = "Ali";
    char b[20] = "Veli";

    printf("Uzunluk a: %zu\n", strlen(a));

    strcpy(a, b);   // a = b
    printf("a =  %s\n", a);

    if (strcmp(a, b) == 0) {
        printf("Stringler esit\n");
    } else {
        printf("Stringler esit degil\n");
    }
}