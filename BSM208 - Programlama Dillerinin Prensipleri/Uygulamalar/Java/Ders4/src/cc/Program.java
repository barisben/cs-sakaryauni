package cc;

import java.util.Scanner;

public class Program {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		System.out.println("Ulke: ");
		String ulke;
		ulke=in.next();
		switch(ulke) {
		case "Turkiye":
			System.out.println("Yurtici");
			break;
		case "Kibris":
			System.out.println("Yavru Vatan");
			break;
		default:
			break;
		}
	}
}