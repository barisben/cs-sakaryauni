package cc.ders12.singleton;

public class Uygulama {
    public static void main(String [] args){
        LogYoneticisi.getInstance("./src/main/java/cc/ders12/singleton/Log.txt").dosyayaYaz("[WARNING]:uyari mesajı 1");
        LogYoneticisi.getInstance("./src/main/java/cc/ders12/singleton/Log.txt").dosyayaYaz("[ERROR]:hata mesajı 1");
    }
}