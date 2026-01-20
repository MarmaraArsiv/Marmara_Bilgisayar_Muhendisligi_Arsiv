#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomsayiuret();//fonksiyonlarýn tanýmlanmasýný burada yapýyoruz.
int birincisayi(int d);
int ikincisayi(int n);

int main(int argc, char *argv[]) {
	printf("--------------------------------\n"); 
	srand(time(NULL)); //rasgelelik için kullanýyoruz
	int uyumluvar = 0 ;
	int a[10];//dizinin tanýmlanmasý
	int i;
	for(i = 0; i<10;i++){//a dizisini random sayýlarla dolduruyoruz
		a[i]= randomsayiuret();
	}
	int r=0,u=0;
	for(r;r<10;r++){//sýrasýyla tüm karþýlaþtýrmalarý aþaðýdaki fon
	
	int bir = birincisayi(a[r]);
	for(u=0;u<10;u++){
		int iki =ikincisayi(a[u]);
			if(iki == bir){
	printf("UYUMLU: Dizi[%d]=%d (Basamak Toplami: %d) ile Dizi[%d]=%d (Bolen Toplami: %d)\n", 
    r, a[r], bir, u, a[u], iki);
	uyumluvar =1; //true false mantýðýný kullanýyorum uyumluvar deðiþkeni için
	}
	}	
	
	}
	if(uyumluvar == 0){
				printf("birbirine uyumlu sayilar yoktur\n");

	}
	return 0;
}

int randomsayiuret() { //sayýyý mod alarak belli bir aralýkta tutuyoruz
  return (rand() % 49) + 2;
}

int birincisayi(int d){//birinci deðer için gereken iþlemleri içeren fonksiyon

	int toplam=0;
	
	while(d!=0){
		toplam += (d%10);
		d = d/10;
	}
	
	return toplam;
}
int ikincisayi(int n){//ikinci deðer için gereken iþlemleri içeren fonksiyon
    int toplam = 0;
    int i;
    for(i = 1; i < n; i++){
        if(n % i == 0)
            toplam += i;
    }
    return toplam;
}


