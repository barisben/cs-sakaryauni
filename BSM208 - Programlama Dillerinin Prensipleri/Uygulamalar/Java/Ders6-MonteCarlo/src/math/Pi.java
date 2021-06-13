package math;

import java.util.Random;

public class Pi {
	private final double hassasiyet;
	
	public Pi(double hassasiyet) {
		this.hassasiyet=hassasiyet;
	}
	
	public double deger() {
		int basariliVurus=0;
		Random rnd=new Random();
		for(double i=0;i<hassasiyet;i++) {
			double x=rnd.nextDouble();
			double y=rnd.nextDouble();
			double uzunluk=Math.sqrt(Math.pow(x, 2)+Math.pow(y, 2));
			if(uzunluk<=1) basariliVurus++;
		}
		return 4*(basariliVurus/hassasiyet);
	}

}
