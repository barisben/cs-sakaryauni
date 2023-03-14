package cc;

public class Hesap {
	private double bakiye;
	public Hesap() {
		bakiye=0;
	}
	public void ParaYatir(double miktar) {
		if(miktar<=0)	throw new ArithmeticException("Hatal� miktar!");
		bakiye+=miktar;
	}
	public void ParaCek(double miktar) {
		//kendi hata s�n�f�m�z� yazmadan �nce
		//if(miktar>bakiye)	throw new IllegalArgumentException("Yetersiz bakiye!");
		//kendi hata s�n�f�m�z� yazd�ktan sonra
		if(miktar>bakiye)	throw new YetersizBakiye("Yetersiz bakiye!");
		bakiye-=miktar;
	}
	
	@Override
	public String toString() {
		return String.valueOf(bakiye);
	}
}