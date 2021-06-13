package cc.MatrisCarpimi;

import java.util.Random;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Program {

	public static void main(String[] args) {
		int boyut=100; //100x100 küçük ölçekli, seri daha hýzlý
		//int boyut=500; //100x100 büyük ölçekli, paralel daha hýzlý
		
		Random rand=new Random();
		
		Matris A=new Matris(rand, boyut);
		Matris B=new Matris(rand, boyut);
		Matris sonuc=new Matris(boyut);
		
		//indekslerin tutuldugu diziye indeksler atama
		int[] sutun=new int[boyut];
		for(int i=0; i<boyut; i++)
			sutun[i]=i;
		
		//Paralellik
		ExecutorService havuz=Executors.newFixedThreadPool(5);
		long baslangicParalel=System.nanoTime();
		for(int satir=0; satir<boyut; satir++) {
			havuz.execute(new Carpma(satir, sutun, A, B, sonuc));
		}
		
		havuz.shutdown();
		while(!havuz.isTerminated());
		long bitisParalel=System.nanoTime();
		double sureParalel=(bitisParalel-baslangicParalel)/1000000;
		
		//Seri
		havuz=Executors.newFixedThreadPool(1);
		long baslangicSeri=System.nanoTime();
		for(int satir=0; satir<boyut; satir++) {
			havuz.execute(new Carpma(satir, sutun, A, B, sonuc));
		}
		havuz.shutdown();
		while(!havuz.isTerminated());
		long bitisSeri=System.nanoTime();
		double sureSeri=(bitisSeri-baslangicSeri)/1000000;
		
		//System.out.println("A Matrisi: \n"+A);
		//System.out.println("B Matrisi: \n"+B);
		//System.out.println("Sonuc Matrisi: \n"+sonuc);
		System.out.println("Paralel Sure: "+String.format("%.2f", sureParalel) + " milisaniye");
		System.out.println("Seri Sure: "+String.format("%.2f", sureSeri) + " milisaniye");
	}
}