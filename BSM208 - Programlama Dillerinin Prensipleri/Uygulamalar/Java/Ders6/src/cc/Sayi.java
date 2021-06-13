package cc;

public class Sayi {
	public int deger;
	private int basamakSayisi;
	//public short[] basamaklar; ornek3
	
	public Sayi(int dgr) {
		deger=dgr;
		basamakSayisi=String.valueOf(deger).length();
	}
	
	//ornek3
	/*
	public Sayi(short[] bsm) {
		basamaklar=bsm;
	}
	
	public void Guncelle() {
		basamaklar[3]=0;
	}
	*/
	
	public short[] rakamlar() {
		int tmp=deger;
		short[] rakamlar=new short[basamakSayisi];
		int indeks=basamakSayisi-1;
		while(tmp>0) {
			rakamlar[indeks--]=(short)(tmp%10);
			tmp/=10;
		}
		return rakamlar;
	}
	
	public boolean asalMi(int... bolen) {
		if(bolen.length==0) return asalMi(2);
		if(deger==bolen[0]) return true;
		if(deger%bolen[0]==0) return false;
		return asalMi(bolen[0]+1);
	}
	
	public int uzunluk() {
		return basamakSayisi;
	}

}
