package cc;

import java.util.Date;

abstract public class GeometrikSekil {
	private String renk;
	private Date olusturulmaTarihi;
	
	public GeometrikSekil(String renk) {
		olusturulmaTarihi=new Date();
		this.renk=renk;
	}
	public Date getOlusturulmaTarihi() {
		return olusturulmaTarihi;
	}
	@Override
	public String toString() {
		String cikti="Tarih: "+olusturulmaTarihi;
		cikti+="\nRenk: "+renk;
		cikti+="\nAlan: "+Alan();
		cikti+="\nCevre: "+Cevre();
		return cikti;
	}
	public abstract double Alan();
	public abstract double Cevre();
}