package cc.KritikBolge;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Hesap {
	private int bakiye;
	private final Lock bolge;
	
	public Hesap() {
		bolge=new ReentrantLock();
		bakiye=0;
	}
	
	public int getBakiye() {
		return bakiye;
	}
	
	public void paraYatir(int miktar) {
		bolge.lock();
		
		int yeniBakiye=bakiye+miktar;
		try {
			Thread.sleep(1);
		} catch (InterruptedException e) {}
		bakiye=yeniBakiye;
		
		bolge.unlock();
	}
}