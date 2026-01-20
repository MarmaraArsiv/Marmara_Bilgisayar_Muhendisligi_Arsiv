#include <stdio.h>

int diziboyutual();//fonksiyonlarimizi tanimliyoruz.
void dizielemanlari(int dizi[], int n);//fonksiyonlarimizi tanimliyoruz.
int modHesapla(int[], int);//fonksiyonlarimizi tanimliyoruz.
int enbuyukeleman(int[], int);//fonksiyonlarimizi tanimliyoruz.

int main() {
    int n;
    n = diziboyutual();
    int dizi[n];
    dizielemanlari(dizi, n);//diziyi oluþturan verileri konsoldan alýyoruz.

    int sonuc = modHesapla(dizi, n);
    
    printf("\n\n");
    printf("Notlarin Kipi (Mod): %d\n", sonuc);
    printf("....................\n");
    
    return 0;
}

int diziboyutual() {//bu fonksiyonla dizinin boyutunu kullanicidan aliyoruz.
    int n;
    printf("Lutfen dizinin eleman sayisini giriniz: ");
    scanf("%d", &n);
    return n;
}

void dizielemanlari(int dizi[], int n) {//dizinin uzunlugu kadar elemani kullanicidan aliyoruz.
    int i;
    for(i = 0; i < n; i++) {
        printf("%d. elemani giriniz: ", i+1);
        scanf("%d", &dizi[i]);
    }
    printf("Dizi elemanlari: ");
    
    for(i = 0; i < n; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");
}

	int modHesapla(int notlar[], int n) {
		
    int counts[101] = {0}; //bir frekans dizisi olusturuyoruz. Tum elemanlari 0 olacak.
	int i = 0;
    for (i = 0; i < n; i++) {
       
        if(notlar[i] >= 0 && notlar[i] <= 100) {
             counts[notlar[i]]++;
        }
    }

    int mod = enbuyukeleman(counts, 101);//frekansi(tekrari) en fazla olan dogal olarak dizinin modu olacaktir. 

    return mod;
}


int enbuyukeleman(int dizi[], int boyut) { //frekans dizisindeki en büyük deðeri bulmak için for kullaniyoruz.
    int max = 0,ii = 1;
    for (ii = 1; ii < boyut; ii++) {
        if (dizi[ii] > dizi[max]) {
            max = ii;
        }
    }
    return max;
}
