package cc.ders7.Uygulama1;

public class Adres {

    private String adresSatiri;
    private String il;

    public Adres(String adresSatiri, String il) {
        this.adresSatiri = adresSatiri;
        this.il = il;
    }

    @Override
    public String toString() {
        return "Adres{" +
                "adresSatiri='" + adresSatiri + '\'' +
                ", il='" + il + '\'' +
                '}';
    }
}