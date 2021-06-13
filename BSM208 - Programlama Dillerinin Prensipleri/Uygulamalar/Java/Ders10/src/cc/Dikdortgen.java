package cc;

public class Dikdortgen implements ISekil{
	private int genislik;
	private int yukseklik;
	
	public Dikdortgen(int genislik, int yukseklik) {
		this.genislik=genislik;
		this.yukseklik=yukseklik;
	}
	
	@Override
	public double Alan() {
		return genislik*yukseklik;
	}
}