package cc.Paralel;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Program {

	public static void main(String[] args) {
		//ORNEK 1 HAVUZSUZ
		/*
		Runnable aYaz=new KarakterIslem('a', 100);
		Runnable bYaz=new KarakterIslem('b', 100);
		Runnable yaz100=new SayiIslem(100);
		
		Thread thread1=new Thread(aYaz);
		Thread thread2=new Thread(bYaz);
		Thread thread3=new Thread(yaz100);
		
		thread1.start();
		thread2.start();
		thread3.start();
		
		while(thread1.isAlive() || thread2.isAlive() || thread3.isAlive());
		*/
		
		//ORNEK 2 HAVUZLU
		ExecutorService havuz=Executors.newFixedThreadPool(3);
		havuz.execute(new KarakterIslem('a', 100));
		havuz.execute(new KarakterIslem('b', 100));
		havuz.execute(new SayiIslem(100));
		havuz.shutdown();
		while(!havuz.isTerminated());
				
	}
}