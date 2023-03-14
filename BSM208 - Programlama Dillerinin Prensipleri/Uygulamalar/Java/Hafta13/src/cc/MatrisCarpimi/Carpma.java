package cc.MatrisCarpimi;

public class Carpma implements Runnable{
	private int satir;
	private int[] sutun;
	private Matris A;
	private Matris B;
	private Matris sonuc;
	
	public Carpma(int satir, int[] sutun, Matris A, Matris B, Matris sonuc) {
		this.satir=satir;
		this.sutun=sutun;
		this.A=A;
		this.B=B;
		this.sonuc=sonuc;
	}
	
	@Override
	public void run() {
		for(int s : sutun) {
			//kare matrisle iþlem yapacaðýmýz için A veya B'nin dizi boyutu
			for(int i=0; i<B.dizi.length; i++) {
				sonuc.dizi[satir][s]+=A.dizi[satir][i]*B.dizi[i][s];
			}
		}
	}
}