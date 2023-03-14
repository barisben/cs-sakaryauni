package cc;

public class Order {//s�ralama i�lemi s�n�f�
	protected int[] sayilar;
	
	public Order(int []sayilar) {
		this.sayilar=new int[sayilar.length];	//burada direkt gelen sayilar dizisine esitleseydik ve sonra this.sayilar �zerinde de�i�iklik yapsayd�k o da de�i�ecekti, o y�zden newledik.
		for(int i=0; i<sayilar.length;i++) {
			this.sayilar[i]=sayilar[i];
		}
	}
	
	public Order(int sayi) {//gelen sayinin her bir basamagini bir indexe yerlestirme
		sayilar=new int[String.valueOf(sayi).length()];
		int index=sayilar.length-1;
		while(sayi>0) {
			sayilar[index--]=sayi%10;
			sayi/=10;
		}
	}
	
	public int[] sirala() {//bubble sort
		for(int i=0; i<sayilar.length-1; i++) {
			for(int j=1; j<sayilar.length-i; j++) {
				if(sayilar[j] < sayilar[j-1]) {
					int tmp=sayilar[j-1];
					sayilar[j-1]=sayilar[j];
					sayilar[j]=tmp;
				}
			}
		}
		int []sirali=new int[sayilar.length]; //d��ar�da kullan�laca�� i�in yeni bir dizi olu�turup yolluyoruz
		for(int i=0; i<sayilar.length;i++) {
			sirali[i]=sayilar[i];
		}
		return sirali;
	}
	
	@Override
	public String toString() {
		String str="";
		sirala();
		for(int sayi:sayilar) {
			str+=sayi+" ";
		}
		return str;
	}
}