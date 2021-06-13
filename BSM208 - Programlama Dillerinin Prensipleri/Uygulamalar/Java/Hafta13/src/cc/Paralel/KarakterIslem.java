package cc.Paralel;

public class KarakterIslem implements Runnable {
	private char yazilanKarakter;
	private int kacKere;
	
	public KarakterIslem(char c, int k) {
		yazilanKarakter=c;
		kacKere=k;
	}
	
	@Override
	public void run() {
		for(int i=0; i<kacKere; i++) {
			System.out.print(yazilanKarakter);
			//Thread.yield();
			if(i>50) {
				try {
					Thread.sleep(10);
				}
				catch (InterruptedException e) {
				}
			}
		}
	}
}