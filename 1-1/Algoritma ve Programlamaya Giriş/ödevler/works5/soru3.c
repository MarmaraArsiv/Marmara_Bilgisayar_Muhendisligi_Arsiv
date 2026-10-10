#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	int sayilar[20];
	srand(time(NULL));//rasgele sayý kýsmý için time.h kütüphanesi ve bu konutu kullanýyoruz
	int min=65,max=90,i=0,j;
	for(i=0;i<=19;i++){//bu for ile 20 tane rasgele sayýyý sayilar[] ýn içine ekliyoruz
			sayilar[i]=rand() % (max - min + 1) + min;//internette bulduðum bir aralýk verme yöntemi
			printf("%d ",sayilar[i]);
	}
	printf("\n");
int sessiz=0, sesli=0;
	for(j=0;j<=19;j++){//elde edilen rasgele sayýlarýn asci tablosuna göre harf karþýlýðýný console a yazdýrýyoruz
	//sesli sessiz harf kýsmýnýda bu aþamada hallediyoruz
		int c = sayilar[j];
		 switch(c) {
             case 65: 
            printf("A");
            sesli++;
            break;
        case 66: 
            printf("B");
            sessiz++;
            break;
        case 67: 
            printf("C");
            sessiz++;
            break;
        case 68: 
            printf("D");
            sessiz++;
            break;
        case 69: 
            printf("E");
            sesli++;
            break;
        case 70: 
            printf("F");
            sessiz++;
            break;
        case 71: 
            printf("G");
            sessiz++;
            break;
        case 72: 
            printf("H");
            sessiz++;
            break;
        case 73: 
            printf("I");
            sesli++;
            break;
        case 74: 
            printf("J");
            sessiz++;
            break;
        case 75: 
            printf("K");
            sessiz++;
            break;
        case 76: 
            printf("L");
            sessiz++;
            break;
        case 77: 
            printf("M");
            sessiz++;
            break;
        case 78: 
            printf("N");
            sessiz++;
            break;
        case 79: 
            printf("O");
            sesli++;
            break;
        case 80: 
            printf("P");
            sessiz++;
            break;
        case 81: 
            printf("Q");
            sessiz++;
            break;
        case 82: 
            printf("R");
            sessiz++;
            break;
        case 83: 
            printf("S");
            sessiz++;
            break;
        case 84: 
            printf("T");
            sessiz++;
            break;
        case 85: 
            printf("U");
            sesli++;
            break;
        case 86: 
            printf("V");
            sessiz++;
            break;
        case 87: 
            printf("W");
            sessiz++;
            break;
        case 88: 
            printf("X");
            sessiz++;
            break;
        case 89: 
            printf("Y");
            sessiz++;
            break;
        case 90: 
            printf("Z");
            sessiz++;
            break;
        default:
            printf("%d: Büyük harf deðil\n", c);
            break;
    }
	}	
	printf("\nsesli harf sayisi %d \nsessiz harf sayisi %d",sesli,sessiz);
	return 0;
}
	
	

