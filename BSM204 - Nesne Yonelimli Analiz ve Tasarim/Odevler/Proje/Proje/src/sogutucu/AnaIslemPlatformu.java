package sogutucu;

public class AnaIslemPlatformu implements IAnaIslemPlatformu, IObserver{
    private IEyleyici eyleyici;
    private ISicaklikAlgilayici sicaklikAlgilayici;
    private ISubject publisher;

    public AnaIslemPlatformu(ISubject publisher){
        eyleyici=new Eyleyici();
        this.publisher=publisher;
        this.publisher.attach(this);
        sicaklikAlgilayici=new SicaklikAlgilayici.SicaklikAlgilayiciBuilder().publisher(publisher).build();
    }
    @Override
    public void eyleyiciyeBildir(int secim){
        if(secim==1)    eyleyici.sogutucuAc();
        else    eyleyici.sogutucuKapa();
    }
    @Override
    public void sicaklikAlgilayiciyaBildir(){
        sicaklikAlgilayici.sicaklikAlgila(eyleyici.getSogutucuDurum());
    }

    @Override
    public void update(String mesaj, float sicaklik){
        if(!eyleyici.getSogutucuDurum()){
            AgArayuzu.mesajGoruntule("AnaIslemPlatformuna gelen mesaj-> "+mesaj);
            eyleyiciyeBildir(1);
        }
    }
}