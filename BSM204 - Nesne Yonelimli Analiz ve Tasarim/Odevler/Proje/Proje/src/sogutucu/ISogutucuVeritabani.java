package sogutucu;

public interface ISogutucuVeritabani {
    InternetKullanicisi kullaniciDogrula(String kullaniciAdi, String sifre);
    void kritikSicaklikLog(float sicaklik);
}