package cc.ders2.Arayuz;

public class PostgreSQLSurucu implements VeritabaniSurucu {

    @Override
    public void baglan() {
        System.out.println("PostgreSQL veritabanına bağlanıyor...");
    }

    @Override
    public void sorguCalistir() {
        System.out.println("PostgreSQL sorgusu çalıştırılıyor...");
    }

    @Override
    public void baglantiSonlandir() {
        System.out.println("PostgreSQL veritabanı bağlantısı sonlandırılıyor...");
    }
}