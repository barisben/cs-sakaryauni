package sogutucu.Veritabani;

import sogutucu.AgArayuzu;
import sogutucu.ISogutucuVeritabani;
import sogutucu.InternetKullanicisi;
import sogutucu.Araclar;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class PostgreSQLSurucu implements ISogutucuVeritabani {
    private Connection conn;

    private void baglan(){
        try {
            AgArayuzu.mesajGoruntule("Sogutucu veritabanina bağlaniliyor...");
            Araclar.bekle(1000);
            this.conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/Sogutucu",
                    "postgres", "admin");
            if (this.conn != null) {
                AgArayuzu.mesajGoruntule("Veritabanına bağlandı!");
                Araclar.bekle(700);
            } else AgArayuzu.mesajGoruntule("Bağlantı girişimi başarısız!");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public InternetKullanicisi kullaniciDogrula(String kullaniciAdi, String sifre) {
        InternetKullanicisi internetKullanicisi =null;

        try
        {
            baglan();
            AgArayuzu.mesajGoruntule("Kullanıcı sorgulanıyor...");
            String sql= "SELECT *  FROM \"Kullanici\" WHERE \"kullaniciAdi\"="+"'"+kullaniciAdi+"'"+"AND \"sifre\"="+"'"+sifre+"'";

            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery(sql);

            conn.close();

            String kAdi;
            String pw;

            while(rs.next())
            {
                kAdi = rs.getString("kullaniciAdi");
                pw = rs.getString("sifre");

                internetKullanicisi = new InternetKullanicisi(kAdi, pw);
            }

            rs.close();
            stmt.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return internetKullanicisi;
    }
    
    @Override
    public void kritikSicaklikLog(float sicaklik){
        try
        {
            baglan();

            AgArayuzu.mesajGoruntule("Kritik sicaklik bilgisi loglaniyor...");
            Araclar.bekle(700);

            DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
            LocalDateTime tarih = LocalDateTime.now();

            String sql= "INSERT INTO \"KritikSicaklikLog\" (\"tarih\", \"sicaklik\") VALUES (\'"+dtf.format(tarih)+"\', "+sicaklik+");";

            Statement stmt = conn.createStatement();
            stmt.executeUpdate(sql);

            conn.close();
            stmt.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}