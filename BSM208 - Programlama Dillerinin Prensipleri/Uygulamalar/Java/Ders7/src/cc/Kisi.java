package cc;

public class Kisi {
		private String isim;
		private int yas;
		private float boy;
		private float kilo;
		private Canta tasidigiCanta;
		
		public Kisi(String isim, float boy, float kilo) {
			this.isim=isim;
			this.boy=boy;
			this.kilo=kilo;
			this.yas=0;
			this.tasidigiCanta=null;
		}
		
		public void yasIlerle(int yil) {
			yas+=yil;
			if(yas<18)	boy+=1;
		}
		
		public void yemekYe(float kalori) {
			kilo+=(kalori/1000);
		}
		@Override
		public String toString() {
			String str=isim+" "+yas+" "+boy+" "+kilo;
			if(tasidigiCanta!=null)	str+="\n"+tasidigiCanta;//tasidigiCanta s�n�f�ndaki toString'i �a��r�yor.
			return str;
		}
		public void cantaAl(float hacim) {
			tasidigiCanta=new Canta(hacim);
		}
		
		@Override
		protected void finalize() throws Throwable {
			try {
				System.out.println("�a��r�ld�!");
			} finally {
				super.finalize();
			}
		}
		
		private class Canta{
			private float hacim;
			public Canta(float hacim) {
				this.hacim=hacim;
			}
			@Override
			public String toString() {
				return "Hacim: "+tasidigiCanta.hacim;
			}
		}
}
