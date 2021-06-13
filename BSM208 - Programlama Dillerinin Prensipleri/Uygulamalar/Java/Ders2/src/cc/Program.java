package cc;

import java.util.ArrayList;

public class Program {

	public static void main(String[] args) {
		//ornek1
		char ch='\u0391';
		System.out.println(ch);
		
		//ornek2
		float x=10;
		double a=10;
		float y=3;
		double b=3;
		float z=x/y;
		double c=a/b;
		if(z==c) System.out.println("Esit");
		else System.out.println("Esit degil!");
		
		//ornek3
		double pi=3.14;
		int q=(int)pi;
		System.out.println(q);
		
		//ornek4
		final double yercekim;
		double kutle=100;
		yercekim=9.8;
		System.out.println("Kuvvet: "+(yercekim*kutle));
		
		//ornek 5
		var v=new ArrayList<Double>();
		//x="Merhaba";
	}

}