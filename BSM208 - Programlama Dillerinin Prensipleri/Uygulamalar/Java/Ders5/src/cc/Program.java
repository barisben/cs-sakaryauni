package cc;

import java.util.Scanner;

public class Program {

	public static void main(String[] args) {
		//ornek1
		for(int i=0;i<10;i++) {
			if(i%2==0) System.out.print(i+" ");
		}
		//ornek2 koleksiyonda gezme(foreach benzeri)
		int []sayiDizisi= {10,20,30,40,50,60,70,80};
		Scanner in=new Scanner(System.in);
		System.out.print("\nAradiginiz sayi: ");
		int sayi=in.nextInt();
		for(int i : sayiDizisi) {
			if (i==sayi) {
				System.out.print("Sayi var!");
				break;
			}
		}
		//ornek3 do while asal sayý, regex
		int sayi1;
		Scanner in1=new Scanner(System.in);
		do {
			System.out.print("\nSayi: ");
			sayi1=in1.nextInt();
		} while (!new String(new char[sayi1]).matches(".?|(..+?)\\1+"));
		System.out.println("Girilen sayi asal degildir.");
		
		//ornek4 continue break
		double toplamAgirlik=0,agirlik;
		Scanner in2=new Scanner(System.in);
		do {
			System.out.println("Agirlik: ");
			agirlik=in2.nextDouble();
			if(agirlik <= 0) continue;
			if(toplamAgirlik+agirlik>100) break;
			toplamAgirlik+=agirlik;
		} while (toplamAgirlik<=100);
		System.out.println("Toplam Agirlik: "+toplamAgirlik);
		
		//ornek4 dýþ bloða break
		System.out.println("\n  	 Carpim Tablosu");
		System.out.println("-----------------------------------------");
		System.out.print("# |");
		for(int i=1;i<=9;i++){
			System.out.print("   "+i);
		}
		System.out.println("\n-----------------------------------------");
		outer:
		for(int i=1;i<=9;i++){//satir
			System.out.print(i+" |");
			for(int j=1;j<=9;j++){//sütun
				if(i*j<10) System.out.print("   "+i*j);//sonuc tek haneyse daha cok bosluk
				else break outer;
			}
			System.out.println("");
		}
		System.out.println("");

	}

}
