package sogutucu;

import java.util.Random;

public class SicaklikAlgilayici implements ISicaklikAlgilayici{
    private float sicaklik;
    private Random rand;
    private ISubject publisher;

    private SicaklikAlgilayici(SicaklikAlgilayiciBuilder builder)
    {
        this.rand = builder.rand;
        this.publisher=builder.publisher;
        this.sicaklik= builder.sicaklik;
    }
    private float randomSicaklik(boolean sogutucuDurum){
        if(sogutucuDurum)   return rand.nextInt(0 - (-20) + 1)+(-20);
        else    return rand.nextInt(61);
    }

    @Override
    public void sicaklikAlgila(boolean sogutucuDurum){
        AgArayuzu.mesajGoruntule("Sıcaklık bilgisi alınıyor...");
        Araclar.bekle(1000);
        sicaklik=randomSicaklik(sogutucuDurum);
        AgArayuzu.mesajGoruntule("Sicaklik: "+sicaklik+"°C");
        if(sicaklik>=40 && publisher!=null){
            publisher.notify("Sicaklik: "+sicaklik+"°C kritik esigi gecti!", sicaklik);
        }
    }

    public static class SicaklikAlgilayiciBuilder
    {
        private float sicaklik;
        private Random rand;
        private ISubject publisher;

        public SicaklikAlgilayiciBuilder() {
            rand = new Random(System.currentTimeMillis());
            sicaklik=0;
        }

        public SicaklikAlgilayiciBuilder publisher(ISubject publisher) {
            this.publisher=publisher;
            return this;
        }
        public SicaklikAlgilayici build() {
            return new SicaklikAlgilayici(this);
        }
    }
}