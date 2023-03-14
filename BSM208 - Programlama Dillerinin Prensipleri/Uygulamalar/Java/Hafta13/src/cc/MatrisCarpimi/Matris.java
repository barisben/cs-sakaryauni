package cc.MatrisCarpimi;

import java.util.Random;

public class Matris {
	public int dizi[][];
	
	public Matris(Random rnd, int boyut) {
		dizi=new int[boyut][boyut];
		
		for(int i=0; i<boyut; i++) {
			for(int j=0; j<boyut; j++) {
				dizi[i][j]=rnd.nextInt(10);
			}
		}
	}
	
	public Matris(int boyut) {
		dizi=new int[boyut][boyut];
	}
	
	@Override
	public String toString() {
		String ekran="";
		for(int[] satir : dizi) {
			for(int hucre : satir) {
				ekran+="\t"+hucre;
			}
			ekran+="\n";
		}
		return ekran;
	}
}