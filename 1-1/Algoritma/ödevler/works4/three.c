#include <stdio.h>//temel kütüphaneleri ekliyoruz
#include <stdlib.h>//temel kütüphaneleri ekliyoruz

int main(int argc, char *argv[]) {
    int sayac=1, maksimum=0, ikinci=0, ucuncu=0, sayi;//deðiþenleri oluþturduk
    
    for(sayac; sayac<11; sayac++) {//iþlemin 10 kez tekrarlanmasý için
        printf("Lutfen sayiyi giriniz\n");//kullanýcýdan sayýyý istiyoruz
        scanf(" %d", &sayi);//girdiði sayýyý sayi deðiþkenine tanýmlýyoruz
        
        if(sayi > maksimum) {//eðer girilen sayý o anki maksimum sayýsýndan büyükse
            ucuncu = ikinci;//eski 2. en büyüðü 3. en büyük yapýyoruz
            ikinci = maksimum;//eski maksimumu 2. en büyük yapýyoruz
            maksimum = sayi;//girilen sayýyý maksimum yapýyoruz
        }
        else if(sayi > ikinci) {//eðer girilen sayý maksimumdan küçük ama 2. en büyükten büyükse
            ucuncu = ikinci;//eski 2. en büyüðü 3. en büyük yapýyoruz
            ikinci = sayi;//girilen sayýyý 2.en büyük yapýyoruz
        }
        else if(sayi > ucuncu) {//eðer girilen sayý sadece 3. en büyükten büyükse
            ucuncu = sayi;//girilen sayýyý 3. en büyük yapýyoruz
        }
    }
    
    printf("\nGirilen en buyuk sayi: %d\n", maksimum);//kod bitince maksimum sayýsýný döndürüyoruz ve ekrana yazdýrýyoruz
    printf("Girilen 2. en buyuk sayi: %d\n", ikinci);//2. en büyük sayýyý ekrana yazdýrýyoruz
    printf("Girilen 3. en buyuk sayi: %d\n", ucuncu);//3. en büyük sayýyý ekrana yazdýrýyoruz
    
    return 0;//fonksiyonun bir deðerle dönmesini saðlýyoruz
}
