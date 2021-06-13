package cc.ders10.NesnelerinDepolanmasi.crudinterface;

import java.util.List;

public interface IUrunRepository {
    Urun ara(int urunNumarasi);
    List<Urun> tumUrunler();
    void kaydet(Urun urun);
    void sil(int urunNumarasi);
}
