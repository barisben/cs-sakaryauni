package cc;

import java.util.stream.Stream;

public class Program {

	public static void main(String[] args) {
		//diziler heapte ornek1
		int []x=new int[3];
		int [][]y=new int[3][2];
		System.out.println(x[0]);
		System.out.println(y[1][1]);
		
		//string ornek2
		String str="SAU";
		String tekrarEdilmis=str.repeat(5);
		System.out.println(tekrarEdilmis);
		
		//string ornek3
		String str2="Sakarya Universitesi\nBilgisayar Muhendisligi";
		Stream<String> satirlar=str2.lines();
		System.out.println(satirlar.findFirst());
		
		//referans-Sayi sinifindan ornek4
		Sayi p=new Sayi(100);
		Sayi r=new Sayi(50);
		Sayi tmp=p;
		p=r;
		r=tmp;
		System.out.println(p.deger);
		System.out.println(r.deger);
		
		//tanýmsýz object ornek5
		Object z=60;
		System.out.println(z);
		z="Sakarya";
		System.out.println(z);
		z=18.24;
		System.out.println(z);
		
		//veri türü tanýmý ornek6
		int e=7,t=2;
		double q=e/t;
		System.out.println(q);
		
		//bool ornek7
		int v=5,b=4;
		System.out.println(v>b);
	}

}