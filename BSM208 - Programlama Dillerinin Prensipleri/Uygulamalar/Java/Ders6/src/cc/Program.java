package cc;

import java.util.Scanner;

public class Program {
	//ornek2
	/*public static void Degistir(Sayi s) {
		//s.deger=800; //boyle 800 yazar sy
		s=null; //boyle 100 yazar sy
	}*/

	public static void main(String[] args) {
		
		//ornek 1, refsiz
		/*Scanner in=new Scanner(System.in);
		System.out.print("Sayi: ");
		int deger=in.nextInt();
		Sayi s=new Sayi(deger);
		short[] rakamlar=s.rakamlar();
		for(short rakam : rakamlar) {
			System.out.print(rakam+" ");
		}
		in.close();*/
		
		//ornek2 refli
		/*
		Sayi sy=new Sayi(100);
		Degistir(sy);
		System.out.println(sy.deger);*/
		
		//ornek3 buradan gönderilen diziyi içeride clonesuz iþletmenin gönderilen diziyi deðiþtirmesi
		/*
		short[] sayilar= {2,4,6,8,9,7};
		Sayi s=new Sayi(sayilar);
		s.Guncelle();
		System.out.println(sayilar[3]);*/
		
		//ornek4 ozyineleme ve degisken sayýda parametre
		Scanner in=new Scanner(System.in);
		System.out.print("Sayi: ");
		int deger=in.nextInt();
		Sayi s=new Sayi(deger);
		short[] rakamlar=s.rakamlar();
		for(short rakam : rakamlar) {
			System.out.print(rakam+" ");
		}
		if(s.asalMi()) System.out.print("Sayý asaldýr!");
		else System.out.print("Sayý asal degildir!");
	}

}
