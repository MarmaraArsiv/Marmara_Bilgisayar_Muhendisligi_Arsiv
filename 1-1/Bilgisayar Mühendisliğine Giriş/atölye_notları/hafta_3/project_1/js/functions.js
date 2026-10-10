/* define your functions here */
/* document.write, bir web sayfasına dinamik olarak içerik eklemek için kullanılan bir metottur. 
   Bu metot, HTML belgesinin içeriğini yazdırır veya değiştirebilir.*/
function outputCartRow(item, total) {
    document.write('<tr>');
    /* Tablo için bir satır başlatır */
    document.write('<td class="painting"><img src="images/'+item.product.filename + '"></td>');
    /* Bir tablo hücresine ürünün görselini ekler.
       Görsele data.js dosyasından erişilir.*/
    document.write('<td>' + item.product.title + '</td>');
    /* Bir tablo hücresine ürün ismini ekler
       Ürünün ismine data.js dosyasından erişilir.*/
    document.write('<td class="center">' + item.quantity + '</td>');
    /* Bir tablo hücresine ürün miktarını ekler
       Ürünün miktarına data.js dosyasından erişilir.*/
    document.write('<td class="right">$' + item.product.price.toFixed(2) + '</td>');
    /* Bir tablo hücresine ürün fiyatını ekler
       Ürünün fiyatına data.js dosyasından erişilir.
       toFixed(2) ile fiyatı 2 ondalık basamağa yuvarlar.
       Ör: 123.4567 sayısı, 2 ondalık basamağa yuvarlanır ve "123.46" olarak döner.*/ 
    document.write('<td class="right">$' + total.toFixed(2) + '</td>');
    /* Ürünün toplam fiyatını (total) gösterir. Bu da 2 ondalık basamağa yuvarlanır.*/ 
    document.write('</tr>');        
    /* Satırı kapatır */    
}

/*Fonksiyon, kendisine gönderilen verileri kullanarak tablodaki tek bir satırı 
göstermek için document.write() çağrılarını kullanmalıdır.

Sayısal değişkenleri iki ondalık basamak ile göstermek için
toFixed() metodunu kullanın.*/ 

function calculateTotal(quantity, price) {
    return quantity * price;
} 
/* Total Fiyatı Hesaplar
ürün adedi ile fiyatını çarparak total fiyatı hesaplar */

function calculateTax(subtotal, rate) {
    return subtotal * rate;
}
/* Vergi Miktarını Hesaplar
Ara toplam ile vergi oranını çarparak vergi miktarını hesaplar */

function calculateShipping(subtotal, threshold) {
    if (subtotal > threshold) {
        return 0;
    }
    else {
        return 40;
    }
}
/* Kargo Ücretini Hesaplar
Ara toplam belirlenen fiyat eşiğinin üstünde ise kargo ücreti 0,
Ara toplam belirlenen fiyat eşiğinin altında ise 40 dolar kargo ücreti belirlenir. */

function calculateGrandTotal(subtotal,tax,shipping) {
    return subtotal + tax + shipping;   
}
/* Genel Toplamı Hesaplar
Ara toplam, vergi ve kargo ücretini toplayarak genel toplamı hesaplar */

function outputCurrency(num) {
    document.write("$" + num.toFixed(2));   
}
/* Ücret yazılan yerlere dolar sembolünü ekler 
   toFixed(2) ile fiyatı 2 ondalık basamağa yuvarlar.*/
        
