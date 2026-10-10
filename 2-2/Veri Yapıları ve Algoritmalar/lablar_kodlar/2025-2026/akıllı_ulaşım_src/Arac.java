/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package akilliulasim;

/**
 *
 * @author merve
 */
abstract class Arac implements Odeme{
    public  String id;    
    public String model;
    public boolean kullanimDurumu = true;
    
    public Arac(String id, String model) {
        this.id = id;
        setModel(model); 
    }
     public String getId() {
        return id;
    }

    public String getModel() {
        return model;
    }
     public void setModel(String model) {
        if (model == null || model.trim().isEmpty()) {
            throw new IllegalArgumentException("Model boş olamaz.");
        }
        this.model = model;
    }
     public boolean uygunMu() {
        return kullanimDurumu;
    }

    void kirala() {
        if (!kullanimDurumu) {
            throw new IllegalStateException("Araç zaten kirada!");
        }
        kullanimDurumu = false;
            }


    public String bilgi() {
        return getType() + " [id=" + id + ", model=" + model + ", Uygun mu?=" + kullanimDurumu + "]";
    }

    void geriGetir() {
            kullanimDurumu = true;
            }
    public abstract String getType();
    
    
}
