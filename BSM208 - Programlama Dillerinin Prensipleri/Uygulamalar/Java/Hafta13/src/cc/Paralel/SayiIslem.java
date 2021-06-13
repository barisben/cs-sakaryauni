package cc.Paralel;

public class SayiIslem implements Runnable{
	private int sonSayi;
	
	public SayiIslem(int s) {
		sonSayi=s;
	}
	
	@Override
	public void run() {
		for(int i=1; i<=sonSayi; i++) {
			System.out.print(i+" ");
		}
	}
}