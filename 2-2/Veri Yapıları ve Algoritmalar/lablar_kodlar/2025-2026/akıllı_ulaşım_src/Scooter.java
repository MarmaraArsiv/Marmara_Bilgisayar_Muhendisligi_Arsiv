/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package akilliulasim;

/**
 *
 * @author merve
 */
public class Scooter extends Arac{

    private int bataryaYuzdesi; // encapsulation

    public Scooter(String id, String model, int bataryaYuzdesi) {
        super(id, model);
        setbataryaYuzdesi(bataryaYuzdesi);
    }

    public int getbataryaYuzdesi() {
        return bataryaYuzdesi;
    }

    public void setbataryaYuzdesi(int bataryaYuzdesi) {
        if (bataryaYuzdesi < 0 || bataryaYuzdesi > 100) {
            throw new IllegalArgumentException("Batarya yüzdesi 0-100 aralığında olmalı.");
        }
        this.bataryaYuzdesi = bataryaYuzdesi;
    }

    @Override
    public String getType() {
        return "Scooter";
    }

 
    @Override
    public double ucretHesapla(int minutes) {
        if (minutes <= 0) return 0;
        return minutes * 2.5;
    }


    @Override
    public String bilgi() {
        return super.bilgi() + " (batarya=" + bataryaYuzdesi + "%)";
    }
    
}
