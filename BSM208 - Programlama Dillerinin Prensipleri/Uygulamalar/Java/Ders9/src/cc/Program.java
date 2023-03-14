package cc;

public class Program {

	public static void main(String[] args) {
		//ORNEK1 ASIL ORNEK
		int[] notlar=new int[] {18,63,97,100,52,27,35};
		Mean m=new Mean(notlar);
		System.out.println(m);
		
		//ORNEK2
		Sayi s1=new Sayi(500);
		Sayi s2=new Sayi(500);
		if(s1==s2) System.out.println("Sayilar esit!");
		else System.out.println("Sayilar esit degil!");
		
		//ORNEK3
		if(s1.equals(s2)) System.out.println("Sayilar esit!");
		else System.out.println("Sayilar esit degil!");
	}
}