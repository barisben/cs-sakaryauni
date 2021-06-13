package cc.KritikBolge;

public class ParaYatir implements Runnable{
	private Hesap hesap;
	private int miktar;
	
	public ParaYatir(Hesap h, int m) {
		hesap=h;
		miktar=m;
	}

	@Override
	public void run() {
		hesap.paraYatir(miktar);
	}
}