package sogutucu;

public class Eyleyici implements IEyleyici{
    private boolean sogutucuDurum=false;

    @Override
    public boolean getSogutucuDurum(){
        return sogutucuDurum;
    }

    @Override
    public void sogutucuAc(){
        AgArayuzu.mesajGoruntule("Soğutucu açılıyor...");
        Araclar.bekle(1000);
        if(!sogutucuDurum){
            sogutucuDurum=true;
            AgArayuzu.mesajGoruntule("Soğutucu açıldı!");
        }
        else AgArayuzu.mesajGoruntule("Soğutucu zaten açık!");
    }

    @Override
    public void sogutucuKapa(){
        AgArayuzu.mesajGoruntule("Soğutucu kapatılıyor...");
        Araclar.bekle(1000);
        if(sogutucuDurum){
            sogutucuDurum=false;
            AgArayuzu.mesajGoruntule("Soğutucu kapatıldı!");
        }
        else AgArayuzu.mesajGoruntule("Soğutucu zaten kapalı!");
    }
}