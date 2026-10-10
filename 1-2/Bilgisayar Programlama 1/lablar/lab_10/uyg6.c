/*
32 Bitlik IP Adresini Noktalı Gösterime Çevirme
Kullanıcıdan 32 bitlik bir IP adresi alınız.
Program, bu sayıyı bitwise işlemler kullanarak 
noktalı IP adresi biçimine dönüştürmelidir.

Örnek:
3232235778  →  192.168.1.2
*/

#include <stdio.h>

// --------------------------------------------------
// 1. ADIM: 32 bitlik IP adresini parçalayacak fonksiyon
// --------------------------------------------------
void convertToDottedDecimal(unsigned int ip)
{
    // --------------------------------------------------
    // 2. ADIM: IP adresini 4 parçaya ayırmak için
    // unsigned char değişkenleri tanımlıyoruz.
    // Her octet 8 bittir.
    // --------------------------------------------------
    unsigned char octet1;
    unsigned char octet2;
    unsigned char octet3;
    unsigned char octet4;

    // --------------------------------------------------
    // 3. ADIM: İlk octeti elde etme
    // 24 bit sağa kaydırıyoruz.
    //
    // Örnek:
    // 11000000 10101000 00000001 00000010
    //
    // 24 bit sağa kaydırınca:
    // 00000000 00000000 00000000 11000000
    //
    // Bu değer 192 olur.
    // --------------------------------------------------
    octet1 = (ip >> 24) & 0xFF;

    // --------------------------------------------------
    // 4. ADIM: İkinci octeti elde etme
    // 16 bit sağa kaydırıyoruz.
    // Sonra sadece son 8 biti almak için
    // AND işlemi kullanıyoruz.
    // --------------------------------------------------
    octet2 = (ip >> 16) & 0xFF;

    // --------------------------------------------------
    // 5. ADIM: Üçüncü octeti elde etme
    // 8 bit sağa kaydırıyoruz.
    // --------------------------------------------------
    octet3 = (ip >> 8) & 0xFF;

    // --------------------------------------------------
    // 6. ADIM: Dördüncü octeti elde etme
    // En sağdaki 8 biti almak için
    // doğrudan AND işlemi yeterlidir.
    // --------------------------------------------------
    octet4 = ip & 0xFF;

    // --------------------------------------------------
    // 7. ADIM: Noktalı IP adresini yazdırma
    // --------------------------------------------------
    printf("\nIP Address: %d.%d.%d.%d\n",
           octet1,
           octet2,
           octet3,
           octet4);
}

int main()
{
    unsigned int ip;

    // --------------------------------------------------
    // 8. ADIM: Kullanıcıdan 32 bitlik IP adresi alma
    // --------------------------------------------------
    printf("32 bitlik IP adresini giriniz (orn. 3232235778): ");
    scanf("%u", &ip);

    // --------------------------------------------------
    // 9. ADIM: Fonksiyonu çağırma
    // --------------------------------------------------
    convertToDottedDecimal(ip);

    return 0;
}