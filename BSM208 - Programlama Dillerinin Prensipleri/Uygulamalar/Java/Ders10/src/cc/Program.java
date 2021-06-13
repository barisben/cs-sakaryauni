package cc;

public class Program {

	public static void main(String[] args) {
		//ornek1 abstract
		Daire daire=new Daire("Mavi", 12);
		System.out.println(daire);
		System.out.println();
		Kare kare=new Kare("Yeþil", 54);
		System.out.println(kare);
		
		//ornek2 interface
		ISekil sekil=new Dikdortgen(15, 5);
		System.out.println(sekil.Alan());
		
		//ornek3 object, yalnýzca toString'ini kullanabiliyoruz
		Object obj=new Daire("Mavi", 12);
		System.out.println(daire);
		System.out.println();
		obj=new Kare("Yeþil", 54);//boxing, unboxing
		System.out.println(kare);
		
		//System.out.println(((Kare)obj).kenar);//kenar public olsa idi çalýþýrdý
	}
}