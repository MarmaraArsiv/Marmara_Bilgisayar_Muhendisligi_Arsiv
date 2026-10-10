/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package akilliulasim;

/**
 *
 * @author merve
 */
public class AkilliUlasim {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
         Kiralama servis = new Kiralama();

        Arac s1 = new Scooter("S-101", "Xiaomi Pro", 85);
        Arac b1 = new Bisiklet("B-201", "Carraro City", 2);

        servis.aracEkle(s1);
        servis.aracEkle(b1);

        System.out.println("=== Sistemdeki Araçlar ===");
        servis.yazdir();

        System.out.println("\n=== Kiralama Senaryosu ===");
        Arac secilen = servis.idAra("S-101");
        if (secilen != null) {
            secilen.kirala(); 

            int dakika = 12;
            double ucret = secilen.ucretHesapla(dakika);

            System.out.println("Kiraladın: " + secilen.bilgi());
            System.out.println(dakika + " dk ücret: " + ucret + " TL");

            secilen.geriGetir();
        }

        System.out.println("\n=== Güncel Durum ===");
        servis.yazdir();
    }
    
}
