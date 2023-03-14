package cc;

public class Mean extends Order{ //ortalama bulma s�n�f�
	public Mean(int []sayilar) {
		super(sayilar);
	}
	
	public double ortalama() {
		double toplam=0;
		for(var sayi:sayilar) {
			toplam+=sayi;
		}
		return toplam/sayilar.length;
	}
	
	@Override
	public String toString() { //e�er mean s�n�f�nda tostring yazmasayd�k kal�t�m ald��� Order s�n�f�nda var m� �nce ona bakard�
		return super.toString()+"\nOrtalama: "+ortalama();
	}
}
