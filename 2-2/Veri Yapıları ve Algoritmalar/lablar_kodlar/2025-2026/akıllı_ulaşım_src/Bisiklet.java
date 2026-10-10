/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package akilliulasim;

/**
 *
 * @author merve
 */
public class Bisiklet extends Arac{

     private int tekerSayisi;

    public Bisiklet(String id, String model, int tekerSayisi) {
        super(id, model);
        this.tekerSayisi=tekerSayisi;       

    }


    @Override
    public String getType() {
        return "Bisiklet";
    }

    @Override
    public double ucretHesapla(int minutes) {
        if (minutes <= 0) return 0;
        return minutes * 1.2;
    }

    @Override
    public String bilgi() {
        return super.bilgi() + " (teker sayısı=" + tekerSayisi + ")";
    }
    
}
