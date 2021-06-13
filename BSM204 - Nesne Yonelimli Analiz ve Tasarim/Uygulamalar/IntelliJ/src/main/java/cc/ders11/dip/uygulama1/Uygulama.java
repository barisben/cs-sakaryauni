package cc.ders11.dip.uygulama1;

public class Uygulama {
    public static void main(String[] args){

        Lamba lamba=new Lamba();
        Buton buton=new Buton(lamba);

        buton.ac();
        buton.kapat();

    }
}

