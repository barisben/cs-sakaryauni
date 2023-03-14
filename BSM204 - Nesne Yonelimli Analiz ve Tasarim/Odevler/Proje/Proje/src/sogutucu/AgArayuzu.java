package sogutucu;

import java.util.Scanner;
import sogutucu.Veritabani.PostgreSQLSurucu;

public class AgArayuzu implements IObserver{
    private Scanner input;
    private ISogutucuVeritabani sogutucuVeritabani;
    private int basarisizGirisSayisi;
    private ISubject publisher;

    private static final int SOGUTUCU_AC = 1;
    private static final int SOGUTUCU_KAPA = 2;
    private static final int SICAKLIK_GORUNTULE = 3;
    private static final int CIKIS = 4;

    public AgArayuzu(){
        input=new Scanner(System.in);
        sogutucuVeritabani=new SogutucuVeritabani(new PostgreSQLSurucu());
        publisher=new Publisher();
        publisher.attach(this);
        basarisizGirisSayisi=0;
    }

    public void basla(){
        mesajGoruntule("Hoşgeldiniz, cihaz başlatılıyor...");
        Araclar.bekle(1000);

        InternetKullanicisi internetKullanicisi;
        do {
            mesajGoruntule("Kullanıcı adı ve şifre giriniz.");
            mesajGoruntule("Kullanıcı adı: ");
            String kullaniciAdi=input.next();
            mesajGoruntule("Sifre: ");
            String sifre=input.next();
            internetKullanicisi=this.kullaniciDogrulama(kullaniciAdi, sifre, sogutucuVeritabani);
            if (internetKullanicisi != null){
                IAnaIslemPlatformu anaIslemPlatformu=new AnaIslemPlatformu(publisher);
                mesajGoruntule("Kullanıcı doğrulandı! Ana menüye yönlendiriliyor...");
                Araclar.bekle();
                islemSecimi(anaIslemPlatformu);
            }
            else{
                if(basarisizGirisSayisi==2){
                    mesajGoruntule("3 defa başarısız giriş yaptığınızdan dolayı sistemden çıkış yapılıyor...");
                    break;
                }
                else    mesajGoruntule("Kullanıcı doğrulanamadı! Lütfen tekrar deneyiniz.");
                basarisizGirisSayisi++;
            }
        }while(internetKullanicisi == null);
    }

    @Override
    public void update(String mesaj, float sicaklik){
        mesajGoruntule("AgArayuzune gelen mesaj-> "+mesaj);
        this.sogutucuVeritabani.kritikSicaklikLog(sicaklik);
    }

    public InternetKullanicisi kullaniciDogrulama(String kullaniciAdi, String sifre, ISogutucuVeritabani sogutucuVeritabani){
        return sogutucuVeritabani.kullaniciDogrula(kullaniciAdi, sifre);
    }

    public static void mesajGoruntule(String mesaj) {
        System.out.println(mesaj);
    }

    private void islemSecimi(IAnaIslemPlatformu anaIslemPlatformu){
        int secim;
        do{
            secim=anaMenuyuGoster();
            switch (secim) {
                case SOGUTUCU_AC, SOGUTUCU_KAPA:
                    anaIslemPlatformu.eyleyiciyeBildir(secim);
                    break;
                case SICAKLIK_GORUNTULE:
                    anaIslemPlatformu.sicaklikAlgilayiciyaBildir();
                    break;
                case CIKIS:
                    mesajGoruntule("Çıkış yapılıyor...");
                    Araclar.bekle();
                    break;
                default:
                    mesajGoruntule("Geçersiz işlem! Geçerli bir işlem seçiniz.");
            }
        }while(secim!=4);
    }

    private int anaMenuyuGoster()
    {
        mesajGoruntule("**********************************************");
        mesajGoruntule("Ana Menu");
        mesajGoruntule("1-Soğutucuyu Aç");
        mesajGoruntule("2-Soğutucuyu Kapa");
        mesajGoruntule("3-Sıcaklığı Görüntüle");
        mesajGoruntule("4-Cikis");
        mesajGoruntule("Seciminiz:");
        mesajGoruntule("**********************************************");
        return input.nextInt();
    }
}