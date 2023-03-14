/**
*
* @author Bar�� Y�lmaz baris.yilmaz5@ogr.sakarya.edu.tr
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
			
			//s�n�f buluyor
			while(sinifMatcher.find()) {
				siniflar.add(sinifMatcher.group(1));
				
				//kal�t�m al�nan s�n�f var m�?
				if(sinifMatcher.group(3)!=null) {
					superSiniflarDizi=sinifMatcher.group(3).replaceAll("public|private|protected", "").split(",");//public, private, protected ibaresi varsa bo�luk ile de�i�tiriyor ki yaln�z ismi kals�n
					
					for (String superSinif : superSiniflarDizi) {
						superSinif=superSinif.trim();
						if(superSiniflar.containsKey(superSinif)) {
							superSinifYeniValue=superSiniflar.get(superSinif)+1;
							superSiniflar.replace(superSinif, superSinifYeniValue);
						}
						else superSiniflar.put(superSinif, 1);
					}
				}
				//public: var m�?
				if(sinifMatcher.group(5)!=null) {
					data=sinifMatcher.group(5);
					privateProtectedMatcher=privateProtectedPattern.matcher(data);
					if(privateProtectedMatcher.find())	data=data.substring(0, privateProtectedMatcher.start());//public: sonras� private: veya protected: varsa oradan sonras�n� siliyor
					//public metotlar� teker teker s�sl� say�lar�ndan bularak metotlarListesi'ne at�yor.
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
							//y�k�c� veya nesne d�nd�ren metot de�il mi? Group3 bo�sa y�k�c� veya nesne d�nd�ren metottur.
							if(metotMatcher.group(3)!=null) {
								metotlar.add(metotMatcher.group(3).replaceAll("\\s+", ""));
								donusTurleri.add(metotMatcher.group(1).replaceAll("\\s+", ""));
								//parametreleri t�rlerini ��kt�daki �ekle getirmek i�in ayr��t�rarak tek bir String haline getiriyor
								if(metotMatcher.group(4)!=null) {
									parametreDizi=metotMatcher.group(4).split(",");
									satirParametreSayac=1;
									parametrelerStr="(";
									for (String i : parametreDizi) {
										i=i.replaceAll("const", ""); //const var ise rahat ayr��t�rmak i�in siliniyor
										parametreMatcher=parametrePattern.matcher(i);
										parametreMatcher.find();
										parametre=parametreMatcher.group().trim().replaceAll("\\s+", "");
										if(i.matches(".*\\[\\s*\\d*\\s*\\]\\s*"))		parametre+="[]"; //parametre dizi al�yorsa parametreye [] ekleniyor
										
										if(parametreDizi.length!=satirParametreSayac)	parametrelerStr+=parametre+", ";
										else	parametrelerStr+=parametre+")";
										satirParametreSayac+=1;
									}
								}
								else parametrelerStr="0"; //parametreler k�sm� bo� ise string 0 oluyor
								parametreler.add(parametrelerStr);
								metotSayac+=1;
							}
							//nesne adresi veya y�k�c� ise
							else if(metotMatcher.group(1)!=null) {
								metotlar.add(metotMatcher.group(1).replaceAll("\\s+", ""));
								
								if(!metotMatcher.group(1).contains("~"))	donusTurleri.add("Nesne Adresi"); //y�k�c� de�ilse nesne adresi d�n�� t�r� ekleniyor
								else	donusTurleri.add("void"); //y�k�c� ise void ekleniyor
								
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
				if(metotIndeksTutucu.size()!=0) 	metotIndeksTutucu.add(metotIndeksTutucu.get(metotIndeksTutucu.size()-1)+metotSayac); //s�n�fa ait ka� metodun bulundu�unu bilebilmek i�in s�n�flara ait metotlar�n ka��nc� indeksten ka��nc� indekse kadar devam etti�i
				else	metotIndeksTutucu.add(metotlar.size()); //ilk s�n�f�n metotlar� eklendiyse metotlar�n size'� kadar ekleniyor
				metotSayac=0;
				metotlarListesi.clear();
			}
			
			for (int i=0; i<siniflar.size();i++) {
				System.out.println("S�n�f: "+siniflar.get(i));
				if(i!=0) {
					//1 �nceki s�n�f�n metotlar�n�n bitti�i indeksten itibaren �imdiki s�n�f�n indeksine dek metotlar, parametreler ve d�n�� t�rleri ayn� indeks numaralar�nda tutuldu�u i�in bu �ekilde yazd�r�labiliyor
					for (int j=metotIndeksTutucu.get(i-1); j<metotIndeksTutucu.get(i); j++) {
						System.out.println("\t"+metotlar.get(j));
						if(parametreler.get(j)!="0") {
							parametreDizi=parametreler.get(j).split(",");
							parametreSayac=parametreDizi.length;
							System.out.println("\t\tParametre: "+parametreSayac+" "+parametreler.get(j));
						}
						else System.out.println("\t\tParametre: "+parametreler.get(j));
						System.out.println("\t\tD�n�� T�r�: "+donusTurleri.get(j));
					}
				}
				//�lk s�n�f�n bilgileri yazd�r�l�yorsa algoritman�n bozulmamas� i�in
				else {
					for (int j=0; j<metotIndeksTutucu.get(0); j++) {
						System.out.println("\t"+metotlar.get(j));
						if(parametreler.get(j)!="0") {
							parametreDizi=parametreler.get(j).split(",");
							parametreSayac=parametreDizi.length;
							System.out.println("\t\tParametre: "+parametreSayac+" "+parametreler.get(j));
						}
						else System.out.println("\t\tParametre: "+parametreler.get(j));
						System.out.println("\t\tD�n�� T�r�: "+donusTurleri.get(j));
					}
				}
				System.out.println();
			}
			//s�per s�n�flar var ise
			if(!superSiniflar.isEmpty()) {
				System.out.println("\nSuper S�n�flar:");
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