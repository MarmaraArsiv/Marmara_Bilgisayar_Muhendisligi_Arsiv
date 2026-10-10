#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int a[5];//dizilerin tanýmlanmasý
	int b[5];
	int c[5];
	int deger=0,i=0;
	for(i=0;i<5;i++){ //dizilerin verilerini kullanýcan alýyoruz -burada a dizisi-
		printf("Lutfen A dizinin birinci degerini giriniz\n");
		scanf("%d",&deger);
		a[i]= deger;
	}	
	printf("A dizisi baþarýyla girildi!\n");
		for(i=0;i<5;i++){//dizilerin verilerini kullanýcan alýyoruz -burada b dizisi-
		printf("Lütfen B dizinin birinci degerini giriniz\n");
		scanf("%d",&deger);
		b[i]= deger;
	}	
	printf("B dizisi basariyla girildi!\n");
		for(i=0;i<5;i++){//tek tek tüm deðerleri toplayýp baþka bir diziye yazdýrýyoruz
		c[i] = a[i]+b[i];
		printf("c dizinin %d. degeri :%d\n",i,c[i]);
	}

	return 0;
}
