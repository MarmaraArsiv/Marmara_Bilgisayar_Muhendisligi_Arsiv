/* add loop and other code here ... in this simple exercise we are not
   going to concern ourselves with minimizing globals, etc 
*/
/* const, JavaScript'te bir değişken tanımlama yöntemidir.
   prompt, kullanıcıdan veri almak için bir girdi penceresi açar.*/

const tax_rate = prompt('Enter tax rate (0.10)');
/* Kullanıcıdan bir vergi oranı istenir. */ 
const shipping_threshold = prompt('Enter shipping threshold (1000)');
/* Kullanıcıdan ücretsiz kargo eşik değeri girmesi istenir.*/

/* running total for subtotals */
/* let komutu, bir değişken tanımlamak için kullanılır. */
let subtotal = 0;
/* subtotal: Sepetteki ürünlerin toplam fiyatını biriktirmek için kullanılan değişken. 
   Başlangıç değeri olarak 0 atanır. */

for (let item of cart) {
    /* cart dizisinin her bir öğesi (item) üzerinde dönen bir for döngüsü */

    let total = calculateTotal(item.quantity,item.product.price);
    /* Ürün miktarı (quantity) ve birim fiyatı (price) kullanılarak toplam fiyat hesaplanır. */
    subtotal += total;
    /* Her ürünün toplam fiyatı (total) subtotal (ara toplam) değişkenine eklenir.*/
    outputCartRow(item,total);
    /* Her ürün için tabloya bir satır eklenir.
       outputCartRow fonksiyonu ürün görselini, başlığını, miktarını, birim fiyatını ve toplam fiyatını tabloya yazar.*/
}

const tax = calculateTax(subtotal,tax_rate);
/* Ara toplam (subtotal) ve kullanıcı tarafından girilen vergi oranı (tax_rate) kullanılarak vergi tutarı hesaplanır.*/
const shipping = calculateShipping(subtotal,shipping_threshold);
/* Ara toplam (subtotal) ve kargo eşiği (shipping_threshold) kullanılarak kargo ücreti belirlenir.*/
const grand = calculateGrandTotal(subtotal,tax,shipping);
/* Ara toplam (subtotal), vergi tutarı (tax) ve kargo ücreti (shipping) kullanılarak genel toplam hesaplanır.*/