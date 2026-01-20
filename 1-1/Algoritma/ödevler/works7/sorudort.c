#include <stdio.h>

//fonksiyonlari ekliyoruz
int diziboyutual();
void dizielemanlari(char dizi[], int n);
int rakamTopla(const char str[]);
char harfKaydir(char c);

int main() {
    int n;
    n = diziboyutual();
    
    char dizi[n]; 
    
    dizielemanlari(dizi, n);

    
    printf("\n\n");
  
    printf("....................\n");
      int toplam = rakamTopla(dizi);
    printf("Rakamlarin toplami: %d\n", toplam);
		int i;
    
    for (i = 0; dizi[i] != '\0'; i++) {//stringin sonuna kadar calisacak bir for dongusu
        if (isalpha(dizi[i])) {//isalpha deger harf mi degil mi kontrol eder 
            dizi[i] = harfKaydir(dizi[i]);
        }
    }

    printf("Sifrelenmis string: %s\n", dizi);//diziyi yazdiriyoruz.
    return 0;
}

int diziboyutual() {//dizi boyutu aliyoruz
    int n;
    printf("Lutfen dizinin eleman sayisini giriniz: ");
    scanf("%d", &n);
    return n;
}

void dizielemanlari(char dizi[], int n) {//elemanlari aliyoruz
    int i;
    for(i = 0; i < n; i++) {
        printf("%d. harfi giriniz: ", i+1);
        
        
        scanf(" %c", &dizi[i]);
    }
    
    printf("Girilen harfler: ");
    for(i = 0; i < n; i++) {
      
        printf("%c ", dizi[i]);
    }
    printf("\n");
}

int rakamTopla(const char dizim[]) {//diziyi degistirememek icin const olarak ekledik
    int toplam = 0;
    int i;

    for (i = 0; dizim[i] != '\0'; i++) {
        if (isdigit(dizim[i])) { //isdigit fonksiyonu girilen deðerin sayý/metin olup olmadýðýný ayýrt eder.
            toplam += dizim[i] - '0';//
        }
    }
    return toplam;
}
char harfKaydir(char c) {//uc sýnýr degerlerine dikkat ediyoruz
       if (c >= 'a' && c <= 'z') {
        c = c + 3;
        if (c > 'z') {//eger toplam 'z' sinirini gectiyse alfabenin basina döndürüyoruz
            c = c - 26;
        }
    }
    else if (c >= 'A' && c <= 'Z') {//uc sýnýr degerlerine dikkat ediyoruz
        c = c + 3;
        if (c > 'Z') {//eger toplam 'z' sinirini gectiyse alfabenin basina döndürüyoruz
            c = c - 26;
        }
    }
    return c;
}

