#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int n=0, i=0, deger=0, k, l;
	
	printf("Dizimiz kac deger boyutunda olsun: ");//kullanýcýdan dizinin uzunluðunu alýyoruz
	scanf("%d", &n);
	
	int a[n];//dizinin tanýmlanmasý
	
	for(i=0; i<n; i++){
		printf("Dizimizin %d.degeri ne olsun?\n", i+1);
		scanf("%d", &deger);
		a[i] = deger;	
	}
	
	// Bubble sorting algoritmasý ile sýralayacaðýz
	for(l=0; l<n-1; l++) {
		for(k=0; k<n-1; k++) {
			if(a[k] > a[k+1]) {
				int tasima = a[k];
				a[k] = a[k+1];
				a[k+1] = tasima;
			}
		}
	}
	
	// Sýralanmýþ diziyi yazýyoruz.
	printf("\nSiralanmis dizi: ");
	for(i=0; i<n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	
	//binary search için gereken sýralý diziyi oluþturduk þimdi binary search kodlarýný yazýyoruz
	int aranan, bulundu = 0, konum = -1;
	printf("\nAramak istediginiz degeri girin: ");
	scanf("%d", &aranan);
	
	int sol = 0, sag = n-1, orta;
	
	while(sol <= sag) {
		orta = (sol + sag) / 2;//dizinin ortasý bulmak için
		
		if(a[orta] == aranan) {
			bulundu = 1;
			konum = orta;
			break;//bulunduðunda döngüden çýkmayý saðlar
		}
		else if(a[orta] < aranan) {
			sol = orta + 1; // dizinin sað tarafýnda arama yap
		}
		else {
			sag = orta - 1; // dizinin sol tarafýnda arama yap
		}
	}
	
	if(bulundu) {//aranan deðerin bulunup bulunamadýðýný kontrol eden kod
		printf("Deger bulundu! Konum: %d\n", konum);
	} else {
		printf("Bulunamadi\n");
	}
	
	return 0;
}
