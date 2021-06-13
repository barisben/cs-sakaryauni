package cc.ders11.ocp.uygulama1;

import cc.ders7.Uygulama2.Siparis;
import cc.ders7.Uygulama2.SiparisKalemi;

import java.time.LocalDateTime;

public class Fatura {
    private Siparis siparis;
    private LocalDateTime siparisTarihi;
    private double faturaToplami=0;

    public Fatura(Siparis siparis) {
        this.siparis=siparis;
    }

    public Siparis getSiparis() {
        return siparis;
    }

    public double toplamTutariHesapla(){
        for(SiparisKalemi siparisKalemi:siparis.getSiparisKalemleri())
            faturaToplami+=siparisKalemi.araToplam()*1.18;
        return faturaToplami;
    }

    ///*
    public String faturaYazdir(FaturaServisi faturaServisi){
        return faturaServisi.faturaOlustur(this);
    }
    //*/
    /*
    public String faturaYazdir(FaturaServisi faturaServisi, byte tur){
        return faturaServisi.faturaOlustur(this,tur);
    }
    */


    @Override
    public String toString() {
        return "Fatura{" +
                "siparis=" + siparis +
                ", siparisTarihi=" + siparisTarihi +
                ", faturaToplami=" + faturaToplami +
                '}';
    }
}
