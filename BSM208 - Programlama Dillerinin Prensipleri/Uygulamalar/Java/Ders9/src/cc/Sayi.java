package cc;

public class Sayi {
	private int deger;
	public Sayi(int dgr) {
		deger=dgr;
	}
	@Override
	public String toString() {
		return String.valueOf(deger);
	}
	@Override
	public boolean equals(Object obj) {
		if(obj==null)	return false;
		
		if(getClass()!=obj.getClass())	return false;
		
		final Sayi sy=(Sayi)obj;
		return this.deger==sy.deger;
	}
}