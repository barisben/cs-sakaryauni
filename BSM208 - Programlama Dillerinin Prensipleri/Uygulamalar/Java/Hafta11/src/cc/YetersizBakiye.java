package cc;

public class YetersizBakiye extends IllegalArgumentException{
	public YetersizBakiye() {
		
	}
	public YetersizBakiye(String hataMesaji) {
		super(hataMesaji);
	}
}