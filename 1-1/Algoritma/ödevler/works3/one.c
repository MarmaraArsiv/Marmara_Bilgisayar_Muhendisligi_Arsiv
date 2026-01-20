#include <stdio.h>//ana kütüphaneleri ekliyoruz
#include <stdlib.h>//ana kütüphaneleri ekliyoruz


int main() {//ana fonksiyonumuzu oluþturuyoruz
	float number1;//birinci sayý için deðiþken oluþturuyoruz
	float number2;//ikinci sayý için deðiþken oluþturuyoruz
	char hangi;//hangi iþlemin yapýlacaðýný öðrenmek için char türünde bir deðiþken oluþturuyoruz.
	printf("Birinci sayiyi giriniz");//giriþ için kullanýcýya haber veriyoruz
	scanf("%f",&number1);//birinci sayýyý deðiþkene yazdýrýyoruz.
	
	printf("Ikýncý sayýyý giriniz");//giriþ için kullanýcýya haber veriyoruz
	scanf("%f",&number2);//ikinci sayýyý deðiþkene yazdýrýyoruz.
	 
	 printf("hangi opetator");//giriþ için kullanýcýya haber veriyoruz
	scanf(" %c",&hangi);//hangi operatörü kullanacaðýmýzý deðiþkene yazdýrýyoruz.
	 	
	switch(hangi){//swich kullanarak koþullarý kontrol edeceðiz
		case '*'://çarpma iþlemi için gereken operator girilince aþaðýdaki code'u uyguluyacak
	  printf("Sonuc: %f\n", number1 * number2);//çarpým iþlemini yaptýrýp console'a yazdýrýyoruz
            break;//bu iþlemden sonra kodu bitiriyoruz	
			
			case '+'://toplama iþlemi için gereken operator girilince aþaðýdaki code'u uyguluyacak
	  printf("Sonuc: %f\n", number1 + number2);//toplama iþlemini yaptýrýp console'a yazdýrýyoruz
            break;//bu iþlemden sonra kodu bitiriyoruz	
			
			case '-'://çýkartma iþlemi için gereken operator girilince aþaðýdaki code'u uyguluyacak
	  printf("Sonuc: %f\n", number1 - number2);//çýkarma iþlemini yaptýrýp console'a yazdýrýyoruz
            break;//bu iþlemden sonra kodu bitiriyoruz	
			
			
			case '/'://bölme iþlemi için gereken operator girilince aþaðýdaki code'u uyguluyacak
	  printf("Sonuc: %f\n", number1 / number2);//bölme iþlemini yaptýrýp console'a yazdýrýyoruz
            break;//bu iþlemden sonra kodu bitiriyoruz
            
        default://yanlýþ operatör girdisi koþulunda bu kod çalýþacak
        	printf("geçerli operator girilmedi");//verdiðimiz operatorler haricinde bir deðer girilirse default kýsmýna gelecek
	}

	return 0;//fonksiyonun çýktýsýný veriyoruz
} 
