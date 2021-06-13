package cc;

public class Daire extends GeometrikSekil{
	private double yariCap;
	
	public Daire(String renk, double yariCap) {
		super(renk);
		this.yariCap=yariCap;
	}

	@Override
	public double Alan() {
		return Math.PI*Math.pow(yariCap, 2);
	}

	@Override
	public double Cevre() {
		return Math.PI*2*yariCap;
	}
}