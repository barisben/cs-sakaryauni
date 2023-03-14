package cc;

public class Program {

	public static void main(String[] args) {
		Kisi k=new Kisi("Ahmet", 35, 5);
		try {
			k.finalize();
		} catch (Throwable e) {
			
		}
		k.yemekYe(1200);
		k.cantaAl(5);
		System.out.println(k);
	}
}