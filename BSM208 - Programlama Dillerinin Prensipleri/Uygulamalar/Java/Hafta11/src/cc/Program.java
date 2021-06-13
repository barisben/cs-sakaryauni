package cc;

import java.io.IOException;

public class Program {

	public static void main(String[] args) {
		//ornek 1, HESAP
		Hesap hesap=new Hesap();
		try {
			hesap.ParaCek(100);//bunun icin throws Yetersiz Bakiye!
			hesap.ParaYatir(-1);//bunun icin throws Hatali Miktar!
		}
		catch (ArithmeticException | IllegalArgumentException ex) {
			System.out.println(ex.getMessage());
		}
		finally {
			System.out.println(hesap);
		}
		
		//ornek 2, DOSYA
		//Dosya dosya=new Dosya("D:/eclipse/java-2020-12/eclipse-workspace/Hafta11/src/cc/deneme.txt");
		Dosya dosya=new Dosya("./src/cc/deneme.txt");
		try {
			System.out.println(dosya.Oku());
		}
		catch (IOException ex){
			System.out.println(ex.getMessage());
		}
		
	}
}