package cc;

public class Mean extends Order{ //ortalama bulma sýnýfý
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
	public String toString() { //eðer mean sýnýfýnda tostring yazmasaydýk kalýtým aldýðý Order sýnýfýnda var mý önce ona bakardý
		return super.toString()+"\nOrtalama: "+ortalama();
	}
}
