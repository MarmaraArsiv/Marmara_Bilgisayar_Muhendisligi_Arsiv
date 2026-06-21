/*
IPv4 Adresini Unsigned Integer Değere Çevirme

Kullanıcıdan bir IPv4 adresini (örneğin: "192.168.1.1") girdi olarak 
alarak bu adresi bir unsigned int değere çeviren bir C programı yazınız.

Daha sonra bu tam sayı değerini ekrana yazdırınız.
*/

#include <stdio.h>

// --------------------------------------------------
// 1. ADIM: IPv4 adresini tam sayıya dönüştüren fonksiyon
// --------------------------------------------------
unsigned int convertToDecimal(const char *ip)
{
    // --------------------------------------------------
    // 2. ADIM: IPv4 adresinin dört octet kısmını tutacak
    // değişkenleri tanımlıyoruz.
    // --------------------------------------------------
    unsigned int octet1;
    unsigned int octet2;
    unsigned int octet3;
    unsigned int octet4;

    // --------------------------------------------------
    // 3. ADIM: Son oluşacak tam sayı değerini tutacak
    // değişkeni tanımlıyoruz.
    // --------------------------------------------------
    unsigned int ip_decimal;

    // --------------------------------------------------
    // 4. ADIM: sscanf ile IPv4 adresini parçalıyoruz
    //
    // Örneğin:
    // "192.168.1.1"
    //
    // octet1 = 192
    // octet2 = 168
    // octet3 = 1
    // octet4 = 1
    // --------------------------------------------------
    sscanf(ip, "%u.%u.%u.%u",
           &octet1,
           &octet2,
           &octet3,
           &octet4);

    // --------------------------------------------------
    // 5. ADIM: Octet değerlerini bitwise işlemler ile
    // uygun konumlara yerleştiriyoruz.
    //
    // octet1 -> 24 bit sola kaydırılır
    // octet2 -> 16 bit sola kaydırılır
    // octet3 -> 8 bit sola kaydırılır
    // octet4 -> olduğu gibi kalır
    //
    // Sonra OR işlemi ile birleştirilir.
    // --------------------------------------------------
    ip_decimal =
        (octet1 << 24) |
        (octet2 << 16) |
        (octet3 << 8)  |
        octet4;

    // --------------------------------------------------
    // 6. ADIM: Oluşan tam sayı değerini geri döndürme
    // --------------------------------------------------
    return ip_decimal;
}

int main()
{
    // --------------------------------------------------
    // 7. ADIM: Kullanıcıdan alınacak IP adresini tutacak
    // karakter dizisini tanımlıyoruz.
    // --------------------------------------------------
    char ip[16];

    // --------------------------------------------------
    // 8. ADIM: Dönüştürülen tam sayı değerini tutacak
    // değişkeni tanımlıyoruz.
    // --------------------------------------------------
    unsigned int ip_decimal;

    // --------------------------------------------------
    // 9. ADIM: Kullanıcıdan IPv4 adresi alma
    // --------------------------------------------------
    printf("Lutfen bir IPv4 adresi girin (ornegin: 192.168.1.1): ");
    scanf("%15s", ip);

    // --------------------------------------------------
    // 10. ADIM: Fonksiyonu çağırarak dönüşüm yapma
    // --------------------------------------------------
    ip_decimal = convertToDecimal(ip);

    // --------------------------------------------------
    // 11. ADIM: Sonucu ekrana yazdırma
    // --------------------------------------------------
    printf("IPv4 adresinin tam sayi karsiligi: %u\n", ip_decimal);

    return 0;
}