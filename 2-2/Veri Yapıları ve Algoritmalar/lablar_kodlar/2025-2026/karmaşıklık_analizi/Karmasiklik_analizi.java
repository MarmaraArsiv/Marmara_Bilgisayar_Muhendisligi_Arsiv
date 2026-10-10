/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package karmasiklik_analizi;

import java.util.ArrayList;

/**
 *
 * @author merve
 */
public class Karmasiklik_analizi {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int[][] matrisA = {
                {1, 2, 3},
                {4, 5, 6}
        };

        int[][] matrisB = {
                {7, 8},
                {9, 10},
                {11, 12}
        };

        int satirA = matrisA.length;
        int sutunA = matrisA[0].length;
        int sutunB = matrisB[0].length;

        int[][] sonucMatris = new int[satirA][sutunB];

        for (int i = 0; i < satirA; i++) {
            for (int j = 0; j < sutunB; j++) {
                for (int k = 0; k < sutunA; k++) {
                    sonucMatris[i][j] += matrisA[i][k] * matrisB[k][j];
                }
            }
        }

        System.out.println("Sonuç Matrisi:");

        for (int i = 0; i < satirA; i++) {
            for (int j = 0; j < sutunB; j++) {
                System.out.print(sonucMatris[i][j] + " ");
            }
            System.out.println();
        }
        
         int[][] matris = {
                {1, 2, 3},
                {4, 5, 6}
        };

        int satir = matris.length;
        int sutun = matris[0].length;

        int[][] transpozMatris = new int[sutun][satir];

        for (int i = 0; i < satir; i++) {
            for (int j = 0; j < sutun; j++) {
                transpozMatris[j][i] = matris[i][j];
            }
        }

        System.out.println("Transpoz Matris:");

        for (int i = 0; i < sutun; i++) {
            for (int j = 0; j < satir; j++) {
                System.out.print(transpozMatris[i][j] + " ");
            }
            System.out.println();
        }
        int[][] dizi = {
                {12, 7, 9},
                {25, 3, 18},
                {4, 30, 11}
        };

        int satir1 = dizi.length;
        int sutun1 = dizi[0].length;

        int maksimum = dizi[0][0];

        for (int i = 0; i < satir1; i++) {
            for (int j = 0; j < sutun1; j++) {

                if (dizi[i][j] > maksimum) {
                    maksimum = dizi[i][j];
                }

            }
        }

        System.out.println("Dizideki maksimum eleman: " + maksimum);
        
        int[] liste1 = {1, 3, 5, 7, 9};
        int[] liste2 = {2, 3, 5, 8, 9};

        ArrayList<Integer> kesisim = new ArrayList<>();

        for (int i = 0; i < liste1.length; i++) {
            for (int j = 0; j < liste2.length; j++) {

                if (liste1[i] == liste2[j]) {
                    kesisim.add(liste1[i]);
                }

            }
        }

        System.out.println("Kesişim elemanları:");
        for (int sayi : kesisim) {
            System.out.print(sayi + " ");
            System.out.println("");     
    }
          int sayi = 25;
        int bitSayisi = 0;

        while (sayi > 0) {
            sayi = sayi / 2;
            bitSayisi++;
        }

        System.out.println("Sayının binary gösterimindeki bit sayısı: " + bitSayisi);
        
    
}
}
