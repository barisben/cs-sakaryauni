/**
*
* @author Barýþ Yýlmaz baris.yilmaz5@ogr.sakarya.edu.tr
* @since 10.04.2021
* <p>
* Programlama Dillerinin Prensipleri Odev1
* </p>
*/

package cc;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class G191210303 {

	public static void main(String[] args) {
			
		try {	
			Path path = Paths.get("src/Program.cpp");
			String file = Files.readString(path);
			file=file.replaceAll("//.*", "");
			
			ArrayList<String> siniflar = new ArrayList<String>();
			ArrayList<String> metotlar = new ArrayList<String>();
			ArrayList<String> metotlarListesi = new ArrayList<String>();
			ArrayList<String> donusTurleri = new ArrayList<String>();
			ArrayList<Integer> metotIndeksTutucu = new ArrayList<Integer>();
			ArrayList<String> parametreler = new ArrayList<String>();
			HashMap<String, Integer> superSiniflar=new HashMap<String, Integer>();	
			
			Pattern sinifPattern=Pattern.compile("\\bclass\\s+(\\w+)\\s*\\{?([:]([^{]+))?(.*?)(public\\s*:.*?)?\\}\\s*;",Pattern.DOTALL);
			Pattern privateProtectedPattern=Pattern.compile("private\\s*:|protected\\s*:",Pattern.DOTALL);
			Pattern metotPattern=Pattern.compile("(~?\\s*\\w+\\s*(<\\s*\\w*\\s*>)?\\s*[*&]*?)\\s*(\\w+|operator\\s*\\W+?\\s*[*&]*?)?\\s*\\(\\s*([^:{]+)?\\)", Pattern.DOTALL);
			Pattern parametrePattern=Pattern.compile("\\w+\s*(<\\s*\\w*\\s*>)?\s*[^\\w]+",Pattern.DOTALL);
			
			Matcher sinifMatcher=sinifPattern.matcher(file);
			Matcher privateProtectedMatcher=privateProtectedPattern.matcher("");
			Matcher metotMatcher=metotPattern.matcher("");
			Matcher parametreMatcher=parametrePattern.matcher("");
			
			String parametre="", parametrelerStr="", data="", yeniData="";
			int superSinifYeniValue=0, metotSayac=0, parametreSayac=0,  satirParametreSayac=0, susluAcSayac=0, susluKapatSayac=0;
			
			String[] parametreDizi;
			String[] superSiniflarDizi;
			
			//sýnýf buluyor
			while(sinifMatcher.find()) {
				siniflar.add(sinifMatcher.group(1));
				
				//kalýtým alýnan sýnýf var mý?
				if(sinifMatcher.group(3)!=null) {
					superSiniflarDizi=sinifMatcher.group(3).replaceAll("public|private|protected", "").split(",");//public, private, protected ibaresi varsa boþluk ile deðiþtiriyor ki yalnýz ismi kalsýn
					
					for (String superSinif : superSiniflarDizi) {
						superSinif=superSinif.trim();
						if(superSiniflar.containsKey(superSinif)) {
							superSinifYeniValue=superSiniflar.get(superSinif)+1;
							superSiniflar.replace(superSinif, superSinifYeniValue);
						}
						else superSiniflar.put(superSinif, 1);
					}
				}
				//public: var mý?
				if(sinifMatcher.group(5)!=null) {
					data=sinifMatcher.group(5);
					privateProtectedMatcher=privateProtectedPattern.matcher(data);
					if(privateProtectedMatcher.find())	data=data.substring(0, privateProtectedMatcher.start());//public: sonrasý private: veya protected: varsa oradan sonrasýný siliyor
					//public metotlarý teker teker süslü sayýlarýndan bularak metotlarListesi'ne atýyor.
					 for(int i = 0; i < data.length(); i++) {    
				            if(data.charAt(i) == '{')	susluAcSayac++;
				            else if(data.charAt(i) == '}')	susluKapatSayac++;
				            if(susluAcSayac==susluKapatSayac && susluAcSayac>0) {
				            	yeniData=data.substring(0, i+1);
				            	data=data.substring(i+1, data.length());
				            	metotlarListesi.add(yeniData);
				            	i=0;
				            	susluAcSayac=0;
				            	susluKapatSayac=0;
				            }
				        }
					
					for(String metot : metotlarListesi) {
						metotMatcher=metotPattern.matcher(metot);
						if(metotMatcher.find()) {
							//yýkýcý veya nesne döndüren metot deðil mi? Group3 boþsa yýkýcý veya nesne döndüren metottur.
							if(metotMatcher.group(3)!=null) {
								metotlar.add(metotMatcher.group(3).replaceAll("\\s+", ""));
								donusTurleri.add(metotMatcher.group(1).replaceAll("\\s+", ""));
								//parametreleri türlerini çýktýdaki þekle getirmek için ayrýþtýrarak tek bir String haline getiriyor
								if(metotMatcher.group(4)!=null) {
									parametreDizi=metotMatcher.group(4).split(",");
									satirParametreSayac=1;
									parametrelerStr="(";
									for (String i : parametreDizi) {
										i=i.replaceAll("const", ""); //const var ise rahat ayrýþtýrmak için siliniyor
										parametreMatcher=parametrePattern.matcher(i);
										parametreMatcher.find();
										parametre=parametreMatcher.group().trim().replaceAll("\\s+", "");
										if(i.matches(".*\\[\\s*\\d*\\s*\\]\\s*"))		parametre+="[]"; //parametre dizi alýyorsa parametreye [] ekleniyor
										
										if(parametreDizi.length!=satirParametreSayac)	parametrelerStr+=parametre+", ";
										else	parametrelerStr+=parametre+")";
										satirParametreSayac+=1;
									}
								}
								else parametrelerStr="0"; //parametreler kýsmý boþ ise string 0 oluyor
								parametreler.add(parametrelerStr);
								metotSayac+=1;
							}
							//nesne adresi veya yýkýcý ise
							else if(metotMatcher.group(1)!=null) {
								metotlar.add(metotMatcher.group(1).replaceAll("\\s+", ""));
								
								if(!metotMatcher.group(1).contains("~"))	donusTurleri.add("Nesne Adresi"); //yýkýcý deðilse nesne adresi dönüþ türü ekleniyor
								else	donusTurleri.add("void"); //yýkýcý ise void ekleniyor
								
								if(metotMatcher.group(4)!=null) {
									parametreDizi=metotMatcher.group(4).split(",");
									satirParametreSayac=1;
									parametrelerStr="(";
									for (String i : parametreDizi) {
										i=i.replaceAll("const", "");
										parametreMatcher=parametrePattern.matcher(i);
										parametreMatcher.find();
										parametre=parametreMatcher.group().trim().replaceAll("\\s+", "");
										if(i.matches(".*\\[\\s*\\d*\\s*\\]\\s*"))		parametre+="[]";
										
										if(parametreDizi.length!=satirParametreSayac)	parametrelerStr+=parametre+", ";
										else	parametrelerStr+=parametre+")";
										satirParametreSayac+=1;
									}
								}
								else parametrelerStr="0";
								parametreler.add(parametrelerStr);	
								metotSayac+=1;
							}
						}
					}
				}
				if(metotIndeksTutucu.size()!=0) 	metotIndeksTutucu.add(metotIndeksTutucu.get(metotIndeksTutucu.size()-1)+metotSayac); //sýnýfa ait kaç metodun bulunduðunu bilebilmek için sýnýflara ait metotlarýn kaçýncý indeksten kaçýncý indekse kadar devam ettiði
				else	metotIndeksTutucu.add(metotlar.size()); //ilk sýnýfýn metotlarý eklendiyse metotlarýn size'ý kadar ekleniyor
				metotSayac=0;
				metotlarListesi.clear();
			}
			
			for (int i=0; i<siniflar.size();i++) {
				System.out.println("Sýnýf: "+siniflar.get(i));
				if(i!=0) {
					//1 önceki sýnýfýn metotlarýnýn bittiði indeksten itibaren þimdiki sýnýfýn indeksine dek metotlar, parametreler ve dönüþ türleri ayný indeks numaralarýnda tutulduðu için bu þekilde yazdýrýlabiliyor
					for (int j=metotIndeksTutucu.get(i-1); j<metotIndeksTutucu.get(i); j++) {
						System.out.println("\t"+metotlar.get(j));
						if(parametreler.get(j)!="0") {
							parametreDizi=parametreler.get(j).split(",");
							parametreSayac=parametreDizi.length;
							System.out.println("\t\tParametre: "+parametreSayac+" "+parametreler.get(j));
						}
						else System.out.println("\t\tParametre: "+parametreler.get(j));
						System.out.println("\t\tDönüþ Türü: "+donusTurleri.get(j));
					}
				}
				//Ýlk sýnýfýn bilgileri yazdýrýlýyorsa algoritmanýn bozulmamasý için
				else {
					for (int j=0; j<metotIndeksTutucu.get(0); j++) {
						System.out.println("\t"+metotlar.get(j));
						if(parametreler.get(j)!="0") {
							parametreDizi=parametreler.get(j).split(",");
							parametreSayac=parametreDizi.length;
							System.out.println("\t\tParametre: "+parametreSayac+" "+parametreler.get(j));
						}
						else System.out.println("\t\tParametre: "+parametreler.get(j));
						System.out.println("\t\tDönüþ Türü: "+donusTurleri.get(j));
					}
				}
				System.out.println();
			}
			//süper sýnýflar var ise
			if(!superSiniflar.isEmpty()) {
				System.out.println("\nSuper Sýnýflar:");
				for (HashMap.Entry<String, Integer> superSinif : superSiniflar.entrySet()) {
					System.out.println("\t"+superSinif.getKey()+": "+superSinif.getValue());
				}
			}
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
}