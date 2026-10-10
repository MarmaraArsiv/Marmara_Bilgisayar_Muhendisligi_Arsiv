/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package akilliulasim;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author merve
 */
public class Kiralama {

    private final List<Arac> araclar = new ArrayList<>();

    public void aracEkle(Arac a) {
        araclar.add(a);
    }

    public Arac idAra(String id) {
        for (Arac a : araclar) {
            if (a.getId().equals(id) && a.uygunMu()) return a;
        }
        
        return null;
    }

    public void yazdir() {
        for (Arac a : araclar) {
            System.out.println(a.bilgi());
        }
    }

  
    
}
