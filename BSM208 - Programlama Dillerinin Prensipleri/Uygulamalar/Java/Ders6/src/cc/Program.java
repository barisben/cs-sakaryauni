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
		
		//ornek3 buradan g�nderilen diziyi i�eride clonesuz i�letmenin g�nderilen diziyi de�i�tirmesi
		/*
		short[] sayilar= {2,4,6,8,9,7};
		Sayi s=new Sayi(sayilar);
		s.Guncelle();
		System.out.println(sayilar[3]);*/
		
		//ornek4 ozyineleme ve degisken say�da parametre
		Scanner in=new Scanner(System.in);
		System.out.print("Sayi: ");
		int deger=in.nextInt();
		Sayi s=new Sayi(deger);
		short[] rakamlar=s.rakamlar();
		for(short rakam : rakamlar) {
			System.out.print(rakam+" ");
		}
		if(s.asalMi()) System.out.print("Say� asald�r!");
		else System.out.print("Say� asal degildir!");
	}

}
