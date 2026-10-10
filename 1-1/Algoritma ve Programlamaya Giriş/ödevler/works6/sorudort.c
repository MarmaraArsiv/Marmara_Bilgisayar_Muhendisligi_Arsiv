#include <stdio.h>
#include <stdlib.h>
#include <time.h> //gerekli kütüphaneleri ekliyorum

int birincisayi(int n);//fonksiyon tanýmlamalarým burada yapýldý
int ikincisayi(int n);
void gunlerikarsilastir(int dizi[]);

int gunsayim[7];

int main(int argc, char *argv[]) {
	srand(time(NULL));//random olmasý için lazým kodun derlendiði zamaný kullanacak
	
	int girilen,i,j,k,l;//deðiþen tanýmlamalarý
	printf("\n\n%d", girilen);
	int veriler[7][10]; // 7 gün için 7 satir 10 veri için 10 sütun açýyoruz
	
	for(i = 0; i<7;i++){//tablonun yazdýrýlmasý
	
		for(j = 0 ; j < 10 ; j++){
		girilen = rand();
		girilen = girilen%500; //sonuçlarýn 500 ten küçük olmasýný tercih ettim
		veriler[i][j] = girilen;
		printf("%d ", girilen);
		}
		printf("\n\n\n");
		
	}
	for(k = 0; k < 7  ; k++)
	{
		int gunluk = 0;  // yeni gün için deðiþkeni sýfýrlýyoruz


		for (l = 0 ; l < 10 ; l++){
	int data=birincisayi(veriler[k][l]);

	int a;
	for(a=0;a<10;a++){
		if(a!=l){
		if (data == ikincisayi(veriler[k][a])){
			gun(k);
			printf("%d degerinin en buyuk basamagi ve %d. degerin kendisi haric pozitif bolenlerinin sayisi aynidir yani guc dengesi vardir\n",veriler[k][l],veriler[k][a]);
		gunluk++;	
		}
	
	
		}
	} // a for bitiþ


		
		} // l for bitiþ
        gunsayim[k] = gunluk;
        printf("-> Gun %d toplam: %d guc dengesi\n\n", k+1, gunluk);
	} // k foru bitiþ
	
	
	gunlerikarsilastir(gunsayim);
	return 0;
}




void gunlerikarsilastir(int dizi[]){
    int encok = -1;
    int enbuyukindex = 0;
    int u;
    
    for(u = 0; u < 7; u++){//en buyuk degeri olan gunu arýyoruz burada
        if(dizi[u] > encok){
            encok = dizi[u];
            enbuyukindex = u; // en buyuk olanýn dizideki yeri
        }
    } 
    
    printf("==========================================\n");
    if(encok > 0)
        printf("SONUC: En cok sayisal uyum %d. gunde bulundu (%d adet).", enbuyukindex + 1, encok);
    else
        printf("SONUC: Hicbir gunde uyum bulunamadi.");
    printf("\n==========================================\n");
}



int birincisayi(int n){//birinci sayýya uygulanacak iþlemleri fonksiyon olarak yazdým
	int biggest=0;
	if(n<0){
		n *= -1;
	}
	while(n>0)
	{
			if((n%10)>biggest){
		biggest = n%10;
	}
	n /= 10;
	}
	return biggest;
}
int ikincisayi (int n){//ikinci sayýya uygulanacak iþlemleri fonksiyon olarak yazdým
	int i, kactane = 0; 
	for(i=1;i<n;i++){
		if(n%i == 0){
			kactane++;
		}
	}
	return kactane;
}

void gun(int t){ //kacýncý gün olduðuna bakarak konsola yazýyor.
    if(t == 0){
        printf("Pazartesi: ");
    }
    else if(t == 1){
        printf("Sali: ");
    }
    else if(t == 2){
        printf("Carsamba: ");
    }
    else if(t == 3){
        printf("Persembe: ");
    }
    else if(t == 4){
        printf("Cuma: ");
    }
    else if(t == 5){
        printf("Cumartesi: ");
    }
    else if(t == 6){
        printf("Pazar: ");
    }
}
