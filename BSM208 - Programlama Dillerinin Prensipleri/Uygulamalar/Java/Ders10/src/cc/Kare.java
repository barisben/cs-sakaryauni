package cc;

public class Kare extends GeometrikSekil {
	private int kenar;
	
	public Kare(String renk, int kenar) {
		super(renk);
		this.kenar=kenar;
	}

	@Override
	public double Alan() {
		return Math.pow(kenar, 2);
	}

	@Override
	public double Cevre() {
		return 4*kenar;
	}
}