package cc.ders6.Veritabani;

import cc.ders6.Araclar;
import cc.ders6.IBankaBilgiSistemi;
import cc.ders6.MusteriHesabi;

public class SanalVeritabaniSurucu implements IBankaBilgiSistemi {
    @Override
    public MusteriHesabi kullaniciDogrula(int hesapNumarasi, int sifre) {
        MusteriHesabi musteriHesabi =null;

        System.out.println("banka bilgi sistemi  kullanıcıyı doğruluyor...");
        Araclar.bekle(2000);
        System.out.println("veritabanına bağlandı (sanal veritabanı yönetim sistemi) ve kullanıcıyı sorguluyor...");
        Araclar.bekle(2000);
        if(hesapNumarasi==2 && sifre==2)
            musteriHesabi = new MusteriHesabi(hesapNumarasi, 1000, "Zeynep", "Gök");
        return musteriHesabi;
    }

    @Override
    public void hesapGuncelle(MusteriHesabi musteriHesabi) {

    }
}
