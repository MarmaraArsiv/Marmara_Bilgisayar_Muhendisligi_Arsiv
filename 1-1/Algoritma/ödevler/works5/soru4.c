#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int n,i,j;//deðiþkenlerimiz
	printf("dizinin eleman sayisini giriniz ");
	scanf(" %d",&n);
	int dizi[n];
	for(i=0;i<(n/2);i++){

	printf("dizinin %d. elemanini giriniz ",i);//baþtan baþlayarak yazdýrma adým adým
	int a;
	scanf(" %d",&a);		dizi[i]=a;

		printf("dizinin %d. elemanini giriniz ",n-i);//sondan baþlayarak yazdýrma adým adým
	int b;
	scanf(" %d",&b);		dizi[n-i-1]=b;	
	}
	if (n % 2 != 0) {//eðer tek basamaklýysa ortadaki deðer boþ kalmýþ olcak yukarýdaki kodda onu ekliyoruz
		printf("Dizinin ortasindaki deðeri (%d. indeks) giriniz ", n / 2);
		scanf("%d", &dizi[n / 2]);
	}
	

	
	
		for(j=0;j<n;j++){printf("%d ",dizi[j]);}//eklediklerimizi yazdýrýyoruz
	return 0;

	}
	
	




