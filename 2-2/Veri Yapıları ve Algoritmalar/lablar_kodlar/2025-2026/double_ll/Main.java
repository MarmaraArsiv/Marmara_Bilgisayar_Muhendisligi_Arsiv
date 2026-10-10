public class Main {
    public static void main(String[] args) {
        DoubleLL liste=new DoubleLL();
        liste.yazdir();
        liste.baslat(1);
        liste.SonaElemanEkle(2);
        liste.SonaElemanEkle(3);
        liste.SonaElemanEkle(4);
        liste.yazdir();
        liste.sayici();
        liste.elemanAra(8);
        liste.basaElemanEkle(5);
        liste.basaElemanEkle(6);
        liste.yazdir();
        System.out.println("----------------");
        liste.sil(1);
        liste.yazdir();
        liste.yazdirDetayli();

    }
}