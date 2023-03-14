package sogutucu;

public class SogutucuVeritabani implements ISogutucuVeritabani{
    private ISogutucuVeritabani veritabani;

    public SogutucuVeritabani(ISogutucuVeritabani veritabani){
        this.veritabani=veritabani;
    }

    @Override
    public InternetKullanicisi kullaniciDogrula(String kullaniciAdi, String sifre) {
        return veritabani.kullaniciDogrula(kullaniciAdi, sifre);
    }

    @Override
    public void kritikSicaklikLog(float sicaklik){
        veritabani.kritikSicaklikLog(sicaklik);
    }
}