package cc.ders2.Kalitim;

import java.util.Scanner;

public class KalitimUygulamasi {
    public static void main(String[] args) {
        System.out.println("Merhaba dünya");

        Scanner input = new Scanner (System.in);

        System.out.print ("Yarıçapı giriniz ");
        float yariCap = input.nextFloat();  //klavyeden int değer okunuyor

        Daire daire1= new Daire(20,20,"mavi",yariCap);
        System.out.println(daire1);
        daire1.konumDegistir(30,50);
        System.out.println(daire1);
        System.out.println(daire1.getKonumX());
    }
}