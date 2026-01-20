#include<stdio.h>

int main()
{
    int i,j,k;
    for(i=0, j=2, k=1; i<=4; i++)
        printf("%d\n", i+j+k);
    return 0;
}
//forun baþýnda i=0, j=2, k=1 olarak tanýmlanmýþ i<= koþulundan dolayý i artcak olana kadar çalýþacak 
//birinci adýmda 1+0+2 (k+i+j)=3
//ikinci adýmda 1+1+2 (k+i+j)=4
//üçüncü adýmda 1+2+2 (k+i+j)=5
//dördüncü adýmda 1+3+2 (k+i+j)=6
//beþinci adýmda 1+4+2 (k+i+j)=7
