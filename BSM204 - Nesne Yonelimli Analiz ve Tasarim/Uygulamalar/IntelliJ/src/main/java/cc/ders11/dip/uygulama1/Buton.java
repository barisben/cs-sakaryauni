package cc.ders11.dip.uygulama1;

public class Buton {
    private Lamba lamba;

    public Buton(Lamba lamba) {
        this.lamba = lamba;
    }

    public void ac(){
        lamba.isigiYak();
    }
    public void kapat(){
        lamba.isigiKapat();
    }
}
