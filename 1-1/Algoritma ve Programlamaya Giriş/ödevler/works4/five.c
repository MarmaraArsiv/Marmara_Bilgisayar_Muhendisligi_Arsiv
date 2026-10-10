#include <stdio.h>//temel kütüphaneyi ekliyoruz
#include <stdlib.h>//temel kütüphaneyi ekliyoruz
#include <locale.h>//türkçe karakter desteði için kütüphane ekliyoruz
#include <windows.h>//windows konsolunda türkçe karakter için kütüphane ekliyoruz

int main(int argc, char *argv[]) {//fonksiyonu oluþturuyoruz
    SetConsoleOutputCP(1254);//konsol çýktýsýný türkçe karakter setine ayarlýyoruz
    SetConsoleCP(1254);//konsol giriþini türkçe karakter setine ayarlýyoruz
    setlocale(LC_ALL, "Turkish");//programýn dilini türkçeye ayarlýyoruz
    
    char girilen[10] = "";//kullanýcýnýn gireceði veriyi saklamak için char dizisi tanýmlýyoruz
    printf("Veriyi giriniz lütfen: ");//kullanýcýdan veri istiyoruz
    scanf("%s", girilen);//girdiði veriyi girilen dizisine atýyoruz
    
    switch(girilen[0]) {//girilen verinin ilk karakterini kontrol ediyoruz
        case 'a': { printf("sesli harf"); break; } case 'A': { printf("sesli harf"); break; }//a harfi sesli harf
        case 'b': { printf("sessiz harf"); break; } case 'B': { printf("sessiz harf"); break; }//b harfi sessiz harf
        case 'c': { printf("sessiz harf"); break; } case 'C': { printf("sessiz harf"); break; }//c harfi sessiz harf
        case 'ç': { printf("sessiz harf"); break; } case 'Ç': { printf("sessiz harf"); break; }//ç harfi sessiz harf
        case 'd': { printf("sessiz harf"); break; } case 'D': { printf("sessiz harf"); break; }//d harfi sessiz harf
        case 'e': { printf("sesli harf"); break; } case 'E': { printf("sesli harf"); break; }//e harfi sesli harf
        case 'f': { printf("sessiz harf"); break; } case 'F': { printf("sessiz harf"); break; }//f harfi sessiz harf
        case 'g': { printf("sessiz harf"); break; } case 'G': { printf("sessiz harf"); break; }//g harfi sessiz harf
        case 'ð': { printf("sessiz harf"); break; } case 'Ð': { printf("sessiz harf"); break; }//ð harfi sessiz harf
        case 'h': { printf("sessiz harf"); break; } case 'H': { printf("sessiz harf"); break; }//h harfi sessiz harf
        case 'ý': { printf("sesli harf"); break; } case 'I': { printf("sesli harf"); break; }//ý harfi sesli harf
        case 'i': { printf("sesli harf"); break; } case 'Ý': { printf("sesli harf"); break; }//i harfi sesli harf
        case 'j': { printf("sessiz harf"); break; } case 'J': { printf("sessiz harf"); break; }//j harfi sessiz harf
        case 'k': { printf("sessiz harf"); break; } case 'K': { printf("sessiz harf"); break; }//k harfi sessiz harf
        case 'l': { printf("sessiz harf"); break; } case 'L': { printf("sessiz harf"); break; }//l harfi sessiz harf
        case 'm': { printf("sessiz harf"); break; } case 'M': { printf("sessiz harf"); break; }//m harfi sessiz harf
        case 'n': { printf("sessiz harf"); break; } case 'N': { printf("sessiz harf"); break; }//n harfi sessiz harf
        case 'o': { printf("sesli harf"); break; } case 'O': { printf("sesli harf"); break; }//o harfi sesli harf
        case 'ö': { printf("sesli harf"); break; } case 'Ö': { printf("sesli harf"); break; }//ö harfi sesli harf
        case 'p': { printf("sessiz harf"); break; } case 'P': { printf("sessiz harf"); break; }//p harfi sessiz harf
        case 'r': { printf("sessiz harf"); break; } case 'R': { printf("sessiz harf"); break; }//r harfi sessiz harf
        case 's': { printf("sessiz harf"); break; } case 'S': { printf("sessiz harf"); break; }//s harfi sessiz harf
        case 'þ': { printf("sessiz harf"); break; } case 'Þ': { printf("sessiz harf"); break; }//þ harfi sessiz harf
        case 't': { printf("sessiz harf"); break; } case 'T': { printf("sessiz harf"); break; }//t harfi sessiz harf
        case 'v': { printf("sessiz harf"); break; } case 'V': { printf("sessiz harf"); break; }//v harfi sessiz harf
        case 'u': { printf("sesli harf"); break; } case 'U': { printf("sesli harf"); break; }//u harfi sesli harf
        case 'ü': { printf("sesli harf"); break; } case 'Ü': { printf("sesli harf"); break; }//ü harfi sesli harf
        case 'y': { printf("sessiz harf"); break; } case 'Y': { printf("sessiz harf"); break; }//y harfi sessiz harf
        case 'z': { printf("sessiz harf"); break; } case 'Z': { printf("sessiz harf"); break; }//z harfi sessiz harf
        default: { printf("alfabede olmayan bir deðer"); break; }//hiçbiri deðilse alfabede olmayan deðer yazdýrýyoruz
    }
    
    return 0;//fonksiyonun dönmesini saðlýyoruz
}
