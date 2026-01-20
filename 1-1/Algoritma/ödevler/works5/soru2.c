#include <stdio.h>

int main() {
	int sayilar[]={1,2,-3,-4,5,6,-2,22,-2,2,-4,5,-66,8,-7,-33,55};//afaki bir sayý dizisi istediðimizi yazabiliriz
	int pozitif=0;int neg=0;int i=0;//deðiþken tanýmlama
	for(i;i<=16;i++){//for ile tek tek deðerlere bakýp pozitif,negatif ayrýmý yapýlýyor
		if(sayilar[i]>=0){
			pozitif++;
		}
		else{
			neg++;
		}
	}
	printf("%d:tane negatif sayi \n%d tane pozitif sayi",neg,pozitif);//sonuçlarýn yazdýrýlmasý
    return 0;
}
