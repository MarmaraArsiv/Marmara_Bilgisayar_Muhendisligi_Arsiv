/* here is the array used for project 1 */
/*const, değeri sonradan değiştirilemeyecek bir değişken tanımlamak için kullanılır.
const, içeriğin değil, referansın değişmesini engeller
Yani: cart → aynı dizi olarak kalmak zorundadır, fakat dizinin içindeki elemanlar 
değişebilir */


const cart = [
      {
            product: {
                  title: "Portrait of Marten Soolmans",
                  filename: "105070.jpg",
                  price: 75.0
            },
            quantity: 3
      },
      {
            product: {
                  title: "View of Houses in Delft",
                  filename: "106060.jpg",
                  price: 125.0
            },
            quantity: 1
      },
      {
            product: {
                  title: "Woman Reading a Letter",
                  filename: "106050.jpg",
                  price: 100.0
            },
            quantity: 2
      },      
];
    /* Bu yapı, Tablodaki ürünlerin detaylarını ve miktarlarını saklamak için kullanılır. 
    Bu sayede, toplam tutar hesaplama, sepet içeriğini görüntüleme gibi işlemler kolayca gerçekleştirilebilir.
    Bu JavaScript kodu, bir alışveriş sepetini temsil eden cart adlı bir dizi (array) oluşturur. 
    Her bir öğe, sepetteki bir ürünü ve bu üründen kaç adet olduğunu gösterir.

cart Dizisi:

Bu dizi, sepetteki ürünleri temsil eden nesneleri (object) içerir.
Her bir nesne, iki anahtar içerir:
product: Ürünün detaylarını içeren bir nesne.
quantity: Ürünün sepetteki adet sayısını belirten bir sayı.

product Nesnesi:
title: Ürünün adını belirten bir metin (string).
filename: Ürüne ait resim dosyasının adını belirten bir metin.
price: Ürünün birim fiyatını belirten bir sayı (number). */