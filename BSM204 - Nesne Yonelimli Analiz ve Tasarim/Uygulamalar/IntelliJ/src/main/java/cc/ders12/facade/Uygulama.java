package cc.ders12.facade;

public class Uygulama {
    public static void main(String [] args){
        SiparisOlusturFacade siparisFatura=new SiparisOlusturFacade();
        siparisFatura.siparisOlustur();
        siparisFatura.faturaOlustur();
    }
}