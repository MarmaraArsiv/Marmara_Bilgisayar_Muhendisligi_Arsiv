#include <stdio.h>

int main() {
    int a = 5;
    int b = 20;

    //Const data
    const int *p1 = &a;
    //*p1 = 15;         
    p1 = &b;
    printf("*p1 = %d\n", *p1);               

    //Const pointer
    int *const p2 = &a;    
    *p2 = 15;              
    //p2 = &b;
    printf("*p2 = %d\n", *p2);              
    
    // //Const pointer ve const data
    const int *const p3 = &a;
    // *p3 = 30;            
    // p3 = &b;
    printf("*p3 = %d\n", *p3);

    return 0;
}