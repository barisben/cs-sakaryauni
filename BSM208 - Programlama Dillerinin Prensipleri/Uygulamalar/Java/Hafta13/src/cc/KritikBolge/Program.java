package cc.KritikBolge;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Program {

	public static void main(String[] args) {
		Hesap hesap=new Hesap();
		ExecutorService havuz=Executors.newFixedThreadPool(3);
		
		for(int i=0; i<100; i++) {
			havuz.execute(new ParaYatir(hesap, 1));
		}
		
		havuz.shutdown();
		while(!havuz.isTerminated());
		
		System.out.println("Son Bakiye: "+ hesap.getBakiye() + " TL");
	}
}