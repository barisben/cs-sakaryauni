/****************************************************************************
**					     SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				      PROGRAMLAMAYA GİRİŞ DERSİ
**					    2019-2020 YAZ DÖNEMİ
**
**				ÖDEV NUMARASI..........: Proje/Tasarım
**				ÖĞRENCİ ADI............: BARIŞ YILMAZ
**				ÖĞRENCİ NUMARASI.......: G191210303
**              DERSİN ALINDIĞI GRUP...: 1/A
****************************************************************************/

#include <windows.h>
#include <fstream>
#include <iostream> 
#include <stdio.h>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>

using namespace std;

/*Hakedislerde 1'den fazla urun kaydı olabilecegi durumlarda silme, guncelleme ve total hakedis hesaplama islemlerinde urun no, urun adeti, toplam fiyat ifadelerini ayirarak
islemlerin yapilabilmesini saglayan fonksiyon. Aralarında "-" olan ifadeler her - arası alınarak vektöre kaydediliyor, ardından vektörden çekilerek gerekli işlemler yapılıyor.*/
void parcala(string const& str, const char tire,
	vector<string>& out)
{
	size_t basla;
	size_t bitir = 0;
	while ((basla = str.find_first_not_of(tire, bitir)) != string::npos)
	{
		bitir = str.find(tire, basla);
		out.push_back(str.substr(basla, bitir - basla));
	}
}
//insaatmalzemeleri.txt icin gerekli olan girdilerin tanımlanması.
struct Urun
{
	string urunNo, urunAdi, urunBirim, urunMarka, urunBirimFiyat;
}urun;
//insaatmalzemeleri.txt dosyasında tum satırları okuyarak girilen urun no'nun dosyada olup olmadıgının kontrolunu saglayan fonksiyon. Var ise kontrol 1, yok ise 0 donduruyor.
bool urunNo_Kontrol(string urunNum)
{
	bool kontrol = 0;
	fstream Dosya;
	string satir;
	Dosya.open("insaatmalzemeleri.txt", ios::in | ios::app);
	while (getline(Dosya, satir))
	{
		stringstream ss(satir);
		getline(ss, urun.urunNo, ',');
		getline(ss, urun.urunAdi, ',');
		getline(ss, urun.urunBirim, ',');
		getline(ss, urun.urunBirimFiyat, ',');
		getline(ss, urun.urunMarka, ',');
		if (urun.urunNo == urunNum)
		{
			kontrol = 1;
		}
	}
	return kontrol;
	Dosya.close();
}
//insaatmalzemeleri.txt dosyasına urunun eklenmesini saglayan fonksiyon.
void UrunEkle()
{
	string urunNum;
	fstream Dosya;
	Dosya.open("insaatmalzemeleri.txt", ios::out | ios::app);
	cout << "\nUrun No :"; cin >> urunNum;
	//Urunler dosyasinda girilen urun no'nun bulunup bulunmadigi sorgulaniyor. Yok ise diger bilgiler alınarak dosyaya kaydediliyor.
	if (urunNo_Kontrol(urunNum) == 1)
	{
		cout << "Bu urun no mevcut. Lutfen yeniden deneyiniz.\n";
	}
	else
	{
		urun.urunNo = urunNum;
		cin.ignore();
		cout << "\nUrun Adi :"; getline(cin, urun.urunAdi);
		cout << "\nUrun Birimi :"; cin >> urun.urunBirim;
		cout << "\nUrun Birim Fiyat :"; cin >> urun.urunBirimFiyat;
		cin.ignore();
		cout << "\nUrun Marka :"; getline(cin, urun.urunMarka);
		Dosya << urun.urunNo << "," << urun.urunAdi << "," << urun.urunBirim << "," << urun.urunBirimFiyat << "," << urun.urunMarka << "\n";
		cout << "Urun eklenmistir.\n";
	}
	Dosya.close();
}
//insaatmalzemeleri.txt dosyasından urun silinebilmesini saglayan fonksiyon.
void UrunSil(string urunSilNo)
{
	fstream Dosya;
	fstream YeniDosya;
	string satir;
	Dosya.open("insaatmalzemeleri.txt", ios::in | ios::app);
	YeniDosya.open("insaatmalzemeleriyeni.txt", ios::out | ios::app);
	bool kontrol = 0;
	//Urunun olup olmadigi kontrolu yapiliyor. Var ise tum satirlar taranarak urun no'nun dosyadaki urun no'ya esit olmadıgı durumdaki satirlari gecici olarak olusturulan yeni dosyaya yazdırıyor.
	if (urunNo_Kontrol(urunSilNo) == 0)
	{
		cout << "Urun no zaten mevcut degil.\n";
	}
	else
	{
		kontrol = 1; //Urun no'nun mevcut olup, islem yapildigini ifade ederek 1 degeri aliyor.
		while (getline(Dosya, satir))
		{
			stringstream ss(satir);
			getline(ss, urun.urunNo, ',');
			getline(ss, urun.urunAdi, ',');
			getline(ss, urun.urunBirim, ',');
			getline(ss, urun.urunBirimFiyat, ',');
			getline(ss, urun.urunMarka, ',');
			if (urun.urunNo != urunSilNo)
			{
				YeniDosya << urun.urunNo << "," << urun.urunAdi << "," << urun.urunBirim << "," << urun.urunBirimFiyat << "," << urun.urunMarka << "\n";
			}
		}
	}
	Dosya.close();
	YeniDosya.close();
	//Kayit girildiyse eski dosya siliniyor ve gecici olarak olusturulan dosya eski dosyasının adını alıyor.
	if (kontrol == 1)
	{
		remove("insaatmalzemeleri.txt");
		rename("insaatmalzemeleriyeni.txt", "insaatmalzemeleri.txt");
		cout << "Urun silindi.\n";
	}
	else
	{
		remove("insaatmalzemeleriyeni.txt");
	}
}
//insaatmalzemeleri.txt dosyasından urun aratilabilmesini saglayan fonksiyon.
void UrunAra(string urunBulNo)
{
	fstream Dosya;
	string satir;
	Dosya.open("insaatmalzemeleri.txt", ios::in | ios::app);
	//Urunun olup olmadigi sorgulaniyor. Urun var ise tum satirlar okunarak girilen urun no'nun dosyadaki urun no'ya esit oldugu satir ekrana yazdiriliyor.
	if (urunNo_Kontrol(urunBulNo) == 0)
	{
		cout << "Urun no mevcut degil.\n";
	}
	else
	{
		while (getline(Dosya, satir))
		{
			stringstream ss(satir);
			getline(ss, urun.urunNo, ',');
			getline(ss, urun.urunAdi, ',');
			getline(ss, urun.urunBirim, ',');
			getline(ss, urun.urunBirimFiyat, ',');
			getline(ss, urun.urunMarka, ',');
			if (urun.urunNo == urunBulNo)
			{
				cout << left << setw(12) << "UrunNo" << setw(17) << "UrunAdi" << setw(15) << "UrunBirimi" << setw(20) << "UrunBirimFiyat" << setw(15) << "UrunMarka" << endl;
				cout << "------------------------------------------------------------------------------" << endl;
				cout << left << setw(12) << urun.urunNo << setw(17) << urun.urunAdi << setw(15) << urun.urunBirim << setw(20) << urun.urunBirimFiyat << setw(15) << urun.urunMarka << "\n";
			}
		}
	}
	Dosya.close();
}
//insaatmalzemeleri.txt dosyasından tum urunlerin listelenebilmesini saglayan fonksiyon. Tum satirlar okunarak ekrana yazdiriliyor.
void UrunListele()
{
	fstream Dosya;
	string satir;
	Dosya.open("insaatmalzemeleri.txt", ios::in | ios::app);
	cout << left << setw(12) << "UrunNo" << setw(17) << "UrunAdi" << setw(15) << "UrunBirimi" << setw(20) << "UrunBirimFiyat" << setw(15) << "UrunMarka" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	while (getline(Dosya, satir))
	{
		stringstream ss(satir);
		getline(ss, urun.urunNo, ',');
		getline(ss, urun.urunAdi, ',');
		getline(ss, urun.urunBirim, ',');
		getline(ss, urun.urunBirimFiyat, ',');
		getline(ss, urun.urunMarka, ',');
		cout << left << setw(12) << urun.urunNo << setw(17) << urun.urunAdi << setw(15) << urun.urunBirim << setw(20) << urun.urunBirimFiyat << setw(15) << urun.urunMarka << "\n";
	}
	Dosya.close();
}
//hakedisler.txt icin gerekli olan girdilerin tanımlanması.
struct Hakedis
{
	string projeNo, donem, urunNo, urunAdet, urunToplamFiyat;
}hakedis;
//hakedisler.txt dosyasında tum satırları okuyarak girilen proje no'nun dosyada olup olmadıgının kontrolunu saglayan fonksiyon. Var ise kontrol 1, yok ise 0 donduruyor.
bool HakedisProjeNo_Kontrol(string hakedisProjeNum)
{
	bool kontrol = 0;
	string satir;
	fstream Dosya;
	Dosya.open("hakedisler.txt", ios::in | ios::app);
	while (getline(Dosya, satir))
	{
		stringstream ss(satir);
		getline(ss, hakedis.projeNo, ',');
		getline(ss, hakedis.donem, ',');
		getline(ss, hakedis.urunNo, ',');
		getline(ss, hakedis.urunAdet, ',');
		getline(ss, hakedis.urunToplamFiyat, ',');
		if (hakedis.projeNo == hakedisProjeNum)
		{
			kontrol = 1;
		}
	}
	return kontrol;
	Dosya.close();
}
//hakedisler.txt dosyasında tum satırları okuyarak girilen urun no'nun dosyada olup olmadıgının kontrolunu saglayan fonksiyon. Var ise kontrol 1, yok ise 0 donduruyor.
bool HakedisUrunNo_Kontrol(string hakedisUrunNum)
{
	bool kontrol = 0;
	string satir;
	fstream Dosya;
	Dosya.open("hakedisler.txt", ios::in | ios::app);
	while (getline(Dosya, satir))
	{
		stringstream ss(satir);
		getline(ss, hakedis.projeNo, ',');
		getline(ss, hakedis.donem, ',');
		getline(ss, hakedis.urunNo, ',');
		getline(ss, hakedis.urunAdet, ',');
		getline(ss, hakedis.urunToplamFiyat, ',');
		if (hakedis.urunNo.find(hakedisUrunNum + "-") != string::npos)
		{
			kontrol = 1;
		}
	}
	return kontrol;
	Dosya.close();
}
//hakedisler.txt dosyasında tum satırları okuyarak girilen donemin dosyada olup olmadıgının kontrolunu saglayan fonksiyon. Var ise kontrol 1, yok ise 0 donduruyor.
bool HakedisDonem_Kontrol(string hakedisDonem)
{
	bool kontrol = 0; //hakedisProjeNum kayıtlı değil ise 0 alıyor.
	string satir;
	fstream Dosya;
	Dosya.open("hakedisler.txt", ios::in | ios::app);
	while (getline(Dosya, satir))
	{
		stringstream ss(satir);
		getline(ss, hakedis.projeNo, ',');
		getline(ss, hakedis.donem, ',');
		getline(ss, hakedis.urunNo, ',');
		getline(ss, hakedis.urunAdet, ',');
		getline(ss, hakedis.urunToplamFiyat, ',');
		if (hakedis.donem == hakedisDonem)
		{
			kontrol = 1;
		}
	}
	return kontrol;
	Dosya.close();
}
/*hakedisler.txt dosyasında tum satırları okuyarak girilen proje no ve donemin dosyada olup olmadıgının kontrolunu saglayan fonksiyon. Fonksiyonun 
amacı bazı hakedis islemlerinde proje no var ise o proje no'ya girilen donemde de veri var mıdır. Var ise kontrol 1, yok ise 0 donduruyor.*/
bool HakedisteProjeNoveDonemVarMi(string projeNum, string donem)
{
	bool kontrol = 0;
	string satir;
	fstream Dosya;
	Dosya.open("hakedisler.txt", ios::in | ios::app);
	while (getline(Dosya, satir))
	{
		stringstream ss(satir);
		getline(ss, hakedis.projeNo, ',');
		getline(ss, hakedis.donem, ',');
		getline(ss, hakedis.urunNo, ',');
		getline(ss, hakedis.urunAdet, ',');
		getline(ss, hakedis.urunToplamFiyat, ',');
		if (hakedis.projeNo == projeNum && hakedis.donem == donem)
		{
			kontrol = 1;
		}
	}
	return kontrol;
	Dosya.close();
}
//projeler.txt icin gerekli olan girdilerin tanımlanması.
struct Proje
{
	string projeNo, projeAdi, projeFirma, projeSorumlu, projeKontrolor;
}proje;
//projeler.txt dosyasında tum satırları okuyarak girilen proje no'nun dosyada olup olmadıgının kontrolunu saglayan fonksiyon. Var ise kontrol 1, yok ise 0 donduruyor.
bool ProjeNo_Kontrol(string projeNum)
{
	bool kontrol = 0;
	string satir;
	fstream Dosya;
	Dosya.open("projeler.txt", ios::in | ios::app);
	while (getline(Dosya, satir))
	{
		stringstream ss(satir);
		getline(ss, proje.projeNo, ',');
		getline(ss, proje.projeAdi, ',');
		getline(ss, proje.projeFirma, ',');
		getline(ss, proje.projeSorumlu, ',');
		getline(ss, proje.projeKontrolor, ',');
		if (proje.projeNo == projeNum)
		{
			kontrol = 1;
		}
	}
	return kontrol;
	Dosya.close();
}
//projeler.txt dosyasina projenin eklenmesini saglayan fonksiyon.
void ProjeEkle()
{
	string projeNum;
	fstream Dosya;
	Dosya.open("projeler.txt", ios::out | ios::app);
	cout << "\nProje No :"; cin >> projeNum;
	//Proje numarasının projeler.txt dosyasında olup olmadıgını kontrolu yapılıyor. Yok ise diger bilgiler alınarak dosyaya kaydediliyor.
	if (ProjeNo_Kontrol(projeNum) == 1)
	{
		cout << "Proje no zaten mevcut. Lutfen yeniden deneyiniz.\n";
	}
	else
	{
		proje.projeNo = projeNum;
		cin.ignore();
		cout << "\nProje Adi :"; getline(cin, proje.projeAdi);
		cout << "\nProje Firma :"; getline(cin, proje.projeFirma);
		cout << "\nProje Sorumlusu :"; getline(cin, proje.projeSorumlu);
		cout << "\nProje Kontrollor :"; getline(cin, proje.projeKontrolor);
		Dosya << proje.projeNo << "," << proje.projeAdi << "," << proje.projeFirma << "," << proje.projeSorumlu << "," << proje.projeKontrolor << "\n";
		cout << "Proje eklenmistir.\n";
	}
	Dosya.close();
}
//projeler.txt dosyasindan proje silinebilmesini saglayan fonksiyon.
void ProjeSil(string projeSilNo)
{
	fstream Dosya;
	fstream YeniDosya;
	string satir;
	Dosya.open("projeler.txt", ios::in | ios::app);
	YeniDosya.open("projeleryeni.txt", ios::out | ios::app);
	bool kontrol = 0;
	//Projenin olup olmadigi kontrolu yapiliyor. Var ise tum satirlar taranarak proje no'nun dosyadaki proje no'ya esit olmadıgı durumdaki satirlari gecici olarak olusturulan yeni dosyaya yazdırıyor.
	if (ProjeNo_Kontrol(projeSilNo) == 0)
	{
		cout << "Proje no zaten mevcut degil.\n";
	}
	else
	{
		if (HakedisProjeNo_Kontrol(projeSilNo) == 0)
		{
			kontrol = 1; //Proje no'nun mevcut olup, islem yapildigini ifade ederek 1 degeri aliyor.
			while (getline(Dosya, satir))
			{
				stringstream ss(satir);
				getline(ss, proje.projeNo, ',');
				getline(ss, proje.projeAdi, ',');
				getline(ss, proje.projeFirma, ',');
				getline(ss, proje.projeSorumlu, ',');
				getline(ss, proje.projeKontrolor, ',');
				if (proje.projeNo != projeSilNo)
				{
					YeniDosya << proje.projeNo << "," << proje.projeAdi << "," << proje.projeFirma << "," << proje.projeSorumlu << "," << proje.projeKontrolor << "\n";
				}
			}
		}
		else
		{
			cout << "Proje no hakedis listesinde oldugundan silinemez.\n";
		}
	}
	Dosya.close();
	YeniDosya.close();
	//Kayit girildiyse eski dosya siliniyor ve gecici olarak olusturulan dosya eski dosyasının adını alıyor.
	if (kontrol == 1)
	{
		remove("projeler.txt");
		rename("projeleryeni.txt", "projeler.txt");
		cout << "Proje silindi.\n";
	}
	else
	{
		remove("projeleryeni.txt");
	}
}
//projeler.txt dosyasından proje aratilabilmesini saglayan fonksiyon.
void ProjeAra(string projeBulNo)
{
	fstream Dosya;
	string satir;
	Dosya.open("projeler.txt", ios::in | ios::app);
	//Projenin olup olmadigi sorgulaniyor. Proje var ise tum satirlar okunarak girilen proje no'nun dosyadaki proje no'ya esit oldugu satir ekrana yazdiriliyor.
	if (ProjeNo_Kontrol(projeBulNo) == 0)
	{
		cout << "Proje no mevcut degil.\n";
	}
	else
	{
		while (getline(Dosya, satir))
		{
			stringstream ss(satir);
			getline(ss, proje.projeNo, ',');
			getline(ss, proje.projeAdi, ',');
			getline(ss, proje.projeFirma, ',');
			getline(ss, proje.projeSorumlu, ',');
			getline(ss, proje.projeKontrolor, ',');
			if (proje.projeNo == projeBulNo)
			{
				cout << left << setw(12) << "ProjeNo" << setw(17) << "ProjeAdi" << setw(25) << "ProjeFirma" << setw(25) << "ProjeSorumlusu" << setw(15) << "ProjeKontroller" << endl;
				cout << "-----------------------------------------------------------------------------------------------" << endl;
				cout << left << setw(12) << proje.projeNo << setw(17) << proje.projeAdi << setw(25) << proje.projeFirma << setw(25) << proje.projeSorumlu << setw(15) << proje.projeKontrolor << "\n";
			}
		}
	}
	Dosya.close();
}
//projeler.txt dosyasından tum projelerin listelenebilmesini saglayan fonksiyon. Tum satirlar okunarak ekrana yazdiriliyor.
void ProjeListele()
{
	fstream Dosya;
	string satir;
	Dosya.open("projeler.txt", ios::in | ios::app);
	cout << left << setw(12) << "ProjeNo" << setw(17) << "ProjeAdi" << setw(25) << "ProjeFirma" << setw(25) << "ProjeSorumlusu" << setw(15) << "ProjeKontroller" << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	while (getline(Dosya, satir))
	{
		stringstream ss(satir);
		getline(ss, proje.projeNo, ',');
		getline(ss, proje.projeAdi, ',');
		getline(ss, proje.projeFirma, ',');
		getline(ss, proje.projeSorumlu, ',');
		getline(ss, proje.projeKontrolor, ',');
		cout << left << setw(12) << proje.projeNo << setw(17) << proje.projeAdi << setw(25) << proje.projeFirma << setw(25) << proje.projeSorumlu << setw(15) << proje.projeKontrolor << "\n";
	}
	Dosya.close();
}
//hakedisler.txt dosyasina hakedis eklenebilmesini saglayan fonksiyon.
void HakedisEkle()
{
	string projeNum, urunNum, donem, satir;
	int urunAdet, birimFiyat = 0;
	fstream Dosya;
	vector<string> urunNolar;
	vector<int> urunAdetler;
	vector<int> urunToplamFiyatlar;
	char cevap = 'e';
	Dosya.open("hakedisler.txt", ios::out | ios::app);
	cout << "\nProje No :"; cin >> projeNum;
	//Projeler dosyasinda girilen proje no'nun bulunup bulunmadigi sorgulaniyor.
	if (ProjeNo_Kontrol(projeNum) == 0)
	{
		cout << "Proje no proje listesinde mevcut degil.\n";
	}
	else
	{
		cout << "\nHakedis Donemi :"; cin >> donem;
		//Proje no mevcut ise bu proje no'ya ait girilen boyle bir donem mevcut mu onun kontrolu yapiliyor. Mevcutsa bu proje no'ya bu donemin tekrar girilmesi engelleniyor.
		if (HakedisteProjeNoveDonemVarMi(projeNum, donem) == 0)
		{
			do
			{
				cout << "\nUrun No:"; cin >> urunNum;
				/*Urunlerin bulundugu dosyada urun no'nun bulunup bulunmadigi sorgulaniyor. Boyle bir urun var ise adet bilgisi de istenerek urunler dosyasindan birim fiyat cekildikten sonra
				girilen miktar ile carpilarak toplam fiyata yaziliyor. Birden fazla urun girilebilme ihtimaline karsin girilen veriler vectorlere islenerek tutuluyor ve urunno, miktar,
				toplamfiyat bolumlerinde aralarina "-" isareti bulunuyor.*/
				if (urunNo_Kontrol(urunNum) == 0)
				{
					cout << "Urun no urun listesinde mevcut degil. Lutfen yeniden deneyiniz.\n";
				}
				else
				{
					hakedis.projeNo = projeNum;
					hakedis.donem = donem;
					urunNolar.push_back(urunNum);
					cout << "\nUrun adet :"; cin >> urunAdet;
					urunAdetler.push_back(urunAdet);
					fstream Dosya;
					Dosya.open("insaatmalzemeleri.txt", ios::in | ios::app);
					while (getline(Dosya, satir))
					{
						stringstream ss(satir);
						getline(ss, urun.urunNo, ',');
						getline(ss, urun.urunAdi, ',');
						getline(ss, urun.urunBirim, ',');
						getline(ss, urun.urunBirimFiyat, ',');
						getline(ss, urun.urunMarka, ',');
						if (urun.urunNo == urunNum)
						{
							birimFiyat = stoi(urun.urunBirimFiyat);
						}
					}
					Dosya.close();
					urunToplamFiyatlar.push_back(birimFiyat * urunAdet);
				}
				cout << "\nBu hakedise baska urun kaydi yapacak misiniz?(e/h)\n"; cin >> cevap;
			} while (!(cevap == 'h'));
			/*Oncelikle urun listesinde olmayan bir urun girilirse yeniden hakedise baska urun kaydi yapilip yapilmadigi soruldugundan dolayi boyle bir durumda
			h basip direkt cikilmasi ihtimaline karsin vectore veri girildiginin kontrolu yapiliyor. Girildi ise dosyaya yaziliyor.*/
			if (urunNolar.size() > 0)
			{
				hakedis.urunNo = "";
				hakedis.urunAdet = "";
				hakedis.urunToplamFiyat = "";
				for (int i = 0; i < urunNolar.size(); i++)
				{
					hakedis.urunNo += urunNolar[i] + "-";
					hakedis.urunAdet += to_string(urunAdetler[i]) + "-";
					hakedis.urunToplamFiyat += to_string(urunToplamFiyatlar[i]) + "-";
				}
				Dosya << hakedis.projeNo << "," << hakedis.donem << "," << hakedis.urunNo << "," << hakedis.urunAdet << "," << hakedis.urunToplamFiyat << "\n";
			}	
		}
		else
		{
			cout << "Proje no'ya ait boyle bir donem hakediste mevcut.\n";
		}
	}
	urunNolar.clear();
	urunAdetler.clear();
	urunToplamFiyatlar.clear();
	Dosya.close();
}
//hakedisler.txt dosyasinda hakedise eklenmis olan urunlerin yeniden girilebilmesini saglayan fonksiyon.
void HakedisUrunGuncelle(string projeNum)
{
	string urunNum, donem, satir;
	int urunAdet, birimFiyat = 0;
	fstream Dosya;
	fstream YeniDosya;
	vector<string> urunNolar;
	vector<int> urunAdetler;
	vector<int> urunToplamFiyatlar;
	char cevap = 'e';
	Dosya.open("hakedisler.txt", ios::in | ios::app);
	YeniDosya.open("hakedisleryeni.txt", ios::out | ios::app);
	bool kontrol = 0;
	//Projeler dosyasinda girilen proje no'nun bulunup bulunmadigi sorgulaniyor.
	if (ProjeNo_Kontrol(projeNum) == 0)
	{
		cout << "Proje no projeler listesinde mevcut degil.\n";
	}
	else
	{
		//Hakedisler dosyasinda girilen proje no'nun olup olmadigi kontrolu yapiliyor.
		if (HakedisProjeNo_Kontrol(projeNum) == 1)
		{
			cout << "Hakedis donemini giriniz.\n"; cin >> donem;
			//Proje no hakedisler dosyasinda da mevcut ise bu proje no'ya ait girilen boyle bir donem mevcut mu onun kontrolu yapiliyor. Mevcutsa bu hakedis icin yeniden urun no ve miktar bilgileri aliniyor.
			if (HakedisteProjeNoveDonemVarMi(projeNum, donem) == 1)
			{
				while (getline(Dosya, satir))
				{
					stringstream ss(satir);
					getline(ss, hakedis.projeNo, ',');
					getline(ss, hakedis.donem, ',');
					getline(ss, hakedis.urunNo, ',');
					getline(ss, hakedis.urunAdet, ',');
					getline(ss, hakedis.urunToplamFiyat, ',');
					/*Hakedisler dosyasindan tum satirlar okunarak proje no ve donemin girdilere esit oldugu satirlar icin kosula giriyor ve true ise yeniden urun no ve miktar bilgileri aliniyor
					ve urunler dosyasindan birim miktar cekilerek verilerek tekrar hakedis eklemede oldugu gibi yaziliyor. false ise o satir aynen yeniden yaziliyor.*/
					if (hakedis.projeNo == projeNum && hakedis.donem == donem)
					{
						do
						{
							cout << "\nUrun No:"; cin >> urunNum;
							if (urunNo_Kontrol(urunNum) == 0)
							{
								cout << "Urun no urun listesinde mevcut degil. Lutfen yeniden deneyiniz.\n";
							}
							else
							{
								urunNolar.push_back(urunNum);
								cout << "\nUrun adet :"; cin >> urunAdet;
								urunAdetler.push_back(urunAdet);
								fstream Dosya;
								Dosya.open("insaatmalzemeleri.txt", ios::in | ios::app);
								while (getline(Dosya, satir))
								{
									stringstream ss(satir);
									getline(ss, urun.urunNo, ',');
									getline(ss, urun.urunAdi, ',');
									getline(ss, urun.urunBirim, ',');
									getline(ss, urun.urunBirimFiyat, ',');
									getline(ss, urun.urunMarka, ',');
									if (urun.urunNo == urunNum)
									{
										birimFiyat = stoi(urun.urunBirimFiyat);
									}
								}
								Dosya.close();
								urunToplamFiyatlar.push_back(birimFiyat * urunAdet);
							}
							cout << "\nBaska urun kayit yapacak misiniz?(e/h)\n"; cin >> cevap;
						} while (!(cevap == 'h'));
						/*Oncelikle urun listesinde olmayan bir urun girilirse yeniden hakedise baska urun kaydi yapilip yapilmadigi soruldugundan dolayi boyle bir durumda
						h basip direkt cikilmasi ihtimaline karsin vectore veri girildiginin kontrolu yapiliyor. Girildi ise dosyaya yaziliyor.*/
						if (urunNolar.size() > 0)
						{
							kontrol = 1;
							hakedis.urunNo = "";
							hakedis.urunAdet = "";
							hakedis.urunToplamFiyat = "";
							for (int i = 0; i < urunNolar.size(); i++)
							{
								hakedis.urunNo += urunNolar[i] + "-";
								hakedis.urunAdet += to_string(urunAdetler[i]) + "-";
								hakedis.urunToplamFiyat += to_string(urunToplamFiyatlar[i]) + "-";
							}
							YeniDosya << hakedis.projeNo << "," << hakedis.donem << "," << hakedis.urunNo << "," << hakedis.urunAdet << "," << hakedis.urunToplamFiyat << "\n";
						}
					}
					else
					{
						YeniDosya << hakedis.projeNo << "," << hakedis.donem << "," << hakedis.urunNo << "," << hakedis.urunAdet << "," << hakedis.urunToplamFiyat << "\n";
					}

				}
			}
			else
			{
				cout << "Proje no'ya ait boyle bir hakedis donemi mevcut degil.\n";
			}
		}
		else
		{
			cout << "Proje no proje listesinde olup, hakedis listesinde olmadıgından silinecek hakedis bulunamadi.\n";
		}
	}
	Dosya.close();
	YeniDosya.close();
	//Kayit girildiyse eski dosya siliniyor ve gecici olarak olusturulan dosya eski dosyasının adını alıyor.
	if (kontrol == 1)
	{
		remove("hakedisler.txt");
		rename("hakedisleryeni.txt", "hakedisler.txt");
		cout << "Urun(ler) guncellendi.\n";
	}
	else
	{
		remove("hakedisleryeni.txt");
	}
	urunNolar.clear();
	urunAdetler.clear();
	urunToplamFiyatlar.clear();
}
//hakedisler.txt dosyasinda girilen proje no'ya ait tum donemlerin cekilerek kullanilan urunlerle beraber ekrana yazilmasini saglayan fonksiyon.
void HakedisKullanilanUrunListele(string projeNum)
{
	fstream Dosya;
	string satir;
	Dosya.open("hakedisler.txt", ios::in | ios::app);
	//Projeler dosyasinda girilen proje no'nun bulunup bulunmadigi sorgulaniyor.
	if (ProjeNo_Kontrol(projeNum) == 1)
	{
		//Hakedisler dosyasinda girilen proje no'nun olup olmadigi kontrolu yapiliyor. Ardindan tum satirlar taranarak girilen proje no'ya ait hakedislerde kullanilan urunler ekrana yazdiriliyor.
		if (HakedisProjeNo_Kontrol(projeNum) == 1)
		{
			cout << left << setw(12) << "ProjeNo" << setw(12) << "Donemi" << setw(35) << "Urun(ler)" << setw(20) << "Adet(ler)" << setw(20) << "Fiyat(lar)" << endl;
			cout << "--------------------------------------------------------------------------------------------------" << endl;
			while (getline(Dosya, satir))
			{
				stringstream ss(satir);
				getline(ss, hakedis.projeNo, ',');
				getline(ss, hakedis.donem, ',');
				getline(ss, hakedis.urunNo, ',');
				getline(ss, hakedis.urunAdet, ',');
				getline(ss, hakedis.urunToplamFiyat, ',');
				if (projeNum == hakedis.projeNo)
				{
					cout << left << setw(12) << hakedis.projeNo << setw(12) << hakedis.donem << setw(35) << hakedis.urunNo << setw(20) << hakedis.urunAdet << setw(20) << hakedis.urunToplamFiyat << "\n";
				}
			}
		}
		else
		{
			cout << "Hakedis listesinde bu proje no'ya ait hakedis mevcut degil.\n";
		}
	}
	else
	{
		cout << "Proje listesinde bu proje no mevcut degil.\n";
	}
	Dosya.close();
}
//hakedisler.txt dosyasinda girilen urun no'nun bulundugu tum hakedislerin ekrana yazdirilmasini saglayan fonksiyon.
void HakedisUrunlerdeAra(string urunNum)
{
	fstream Dosya;
	string satir;
	Dosya.open("hakedisler.txt", ios::in | ios::app);
	//Urunler dosyasinda girilen urun no'nun bulunup bulunmadigi sorgulaniyor.
	if (urunNo_Kontrol(urunNum) == 1)
	{
		/*Hakedisler dosyasinda girilen urun no'nun herhangi bir hakediste bulunup bulunmadigi sorgulaniyor. Bulunuyor ise tum satirlar taraniyor,
		girilen urun no'nun bulundugu satirlar ekrana yazdiriliyor.*/
		if (HakedisUrunNo_Kontrol(urunNum) == 1)
		{
			cout << left << setw(12) << "ProjeNo" << setw(12) << "Donemi" << setw(35) << "Urun(ler)" << setw(20) << "Adet(ler)" << setw(20) << "Fiyat(lar)" << endl;
			cout << "--------------------------------------------------------------------------------------------------" << endl;
			while (getline(Dosya, satir))
			{
				stringstream ss(satir);
				getline(ss, hakedis.projeNo, ',');
				getline(ss, hakedis.donem, ',');
				getline(ss, hakedis.urunNo, ',');
				getline(ss, hakedis.urunAdet, ',');
				getline(ss, hakedis.urunToplamFiyat, ',');
				if (hakedis.urunNo.find(urunNum + "-") != string::npos)
				{
					cout << left << setw(12) << hakedis.projeNo << setw(12) << hakedis.donem << setw(35) << hakedis.urunNo << setw(20) << hakedis.urunAdet << setw(20) << hakedis.urunToplamFiyat << "\n";
				}
			}
		}
		else
		{
			cout << "Hakedis listesinde bu urun no'nun bulundugu hakedis mevcut degil.\n";
		}
	}
	else
	{
		cout << "Urunler listesinde bu urun no mevcut degil.\n";
	}
	Dosya.close();
}
//hakedisler.txt dosyasinda girilen proje no'nun bulundugu tum hakedislerin ve bu hakedislerin toplam tutarlarinin ekrana yazdirilmasini saglayan fonksiyon.
void HakedisProjeNodanTotalTutarListele(string projeNum)
{
	vector<string> projeToplamFiyat;
	string satir;
	int genelToplam = 0;
	fstream Dosya;
	Dosya.open("hakedisler.txt", ios::in | ios::app);
	//Projeler dosyasinda girilen proje no'nun bulunup bulunmadigi sorgulaniyor.
	if (ProjeNo_Kontrol(projeNum) == 1)
	{
		//Hakedisler dosyasinda girilen proje no'nun olup olmadigi kontrolu yapiliyor. Var ise tum satirlar taraniyor.
		if (HakedisProjeNo_Kontrol(projeNum) == 1)
		{
			cout << left << setw(12) << "ProjeNo" << setw(12) << "Donemi" << setw(35) << "Urun(ler)" << setw(20) << "Adet(ler)" << setw(20) << "Fiyat(lar)" << endl;
			cout << "--------------------------------------------------------------------------------------------------" << endl;
			while (getline(Dosya, satir))
			{
				stringstream ss(satir);
				getline(ss, hakedis.projeNo, ',');
				getline(ss, hakedis.donem, ',');
				getline(ss, hakedis.urunNo, ',');
				getline(ss, hakedis.urunAdet, ',');
				getline(ss, hakedis.urunToplamFiyat, ',');
				/*Satirda proje no bulunur ise birden fazla veri girisi ihtimaline karsi "-" ile ayrilmis olan toplam fiyat kısmı -'lerden parcala fonksiyonu ile parcalanarak
				projeToplamFiyat vectorune kaydediliyor. Ardindan genelToplam'a vektördeki girdiler ekleniyor. Son olarak hakedisler ve genel toplam ekrana yazdiriliyor.*/
				if (hakedis.projeNo == projeNum)
				{
					cout << left << setw(12) << hakedis.projeNo << setw(12) << hakedis.donem << setw(35) << hakedis.urunNo << setw(20) << hakedis.urunAdet << setw(20) << hakedis.urunToplamFiyat << "\n";
					const char tire = '-';
					parcala(hakedis.urunToplamFiyat, tire, projeToplamFiyat);
					for (int i = 0; i < projeToplamFiyat.size(); i++)
					{
						genelToplam += stoi(projeToplamFiyat[i]);
					}
					projeToplamFiyat.clear();
				}
			}
			cout << "\nGirmis oldugunuz proje no'ya ait tum donem hakedislerin toplam tutari:\t" << genelToplam << "\n";
		}
		else
		{
			cout << "Hakedis listesinde bu proje no'nun bulundugu hakedis mevcut degil.\n";
		}
	}
	else
	{
		cout << "Projeler listesinde bu proje no mevcut degil.\n";
	}
	Dosya.close();
}
//hakedisler.txt dosyasinda girilen donemin bulundugu tum hakedislerin ve bu hakedislerin toplam tutarlarinin ekrana yazdirilmasini saglayan fonksiyon.
void HakedisDonemdenTotalTutarListele(string hakedisDonem)
{
	vector<string> donemToplamFiyat;
	string satir;
	int genelToplam = 0;
	fstream Dosya;
	Dosya.open("hakedisler.txt", ios::in | ios::app);
	//Hakedisler dosyasinda girilen donemin olup olmadigi kontrolu yapiliyor. Var ise tum satirlar taraniyor.
	if (HakedisDonem_Kontrol(hakedisDonem) == 1)
	{
		cout << left << setw(12) << "ProjeNo" << setw(12) << "Donemi" << setw(35) << "Urun(ler)" << setw(20) << "Adet(ler)" << setw(20) << "Fiyat(lar)" << endl;
		cout << "--------------------------------------------------------------------------------------------------" << endl;
		while (getline(Dosya, satir))
		{
			stringstream ss(satir);
			getline(ss, hakedis.projeNo, ',');
			getline(ss, hakedis.donem, ',');
			getline(ss, hakedis.urunNo, ',');
			getline(ss, hakedis.urunAdet, ',');
			getline(ss, hakedis.urunToplamFiyat, ',');
			/*Satirda dönem bulunur ise birden fazla veri girisi ihtimaline karsi "-" ile ayrilmis olan toplam fiyat kısmı -'lerden parcala fonksiyonu ile parcalanarak
			donemToplamFiyat vectorune kaydediliyor. Ardindan genelToplam'a vektördeki girdiler ekleniyor. Son olarak hakedisler ve genel toplam ekrana yazdiriliyor.*/
			if (hakedis.donem == hakedisDonem)
			{
				cout << left << setw(12) << hakedis.projeNo << setw(12) << hakedis.donem << setw(35) << hakedis.urunNo << setw(20) << hakedis.urunAdet << setw(20) << hakedis.urunToplamFiyat << "\n";
				const char tire = '-';
				parcala(hakedis.urunToplamFiyat, tire, donemToplamFiyat);
				for (int i = 0; i < donemToplamFiyat.size(); i++)
				{
					genelToplam += stoi(donemToplamFiyat[i]);
				}
				donemToplamFiyat.clear();
			}
		}
		cout << "\nGirmis oldugunuz doneme ait hakedislerin toplam tutari:\t" << genelToplam << "\n";
	}
	else
	{
		cout << "Hakedis listesinde girmis oldugunuz donemin bulundugu hakedis mevcut degil.\n";
	}
	donemToplamFiyat.clear();
	Dosya.close();
}
//hakedisler.txt dosyasinda hakedise eklenmis olan urunlerin silinebilmesini saglayan fonksiyon.
void HakedisUrunSil(string projeNum)
{
	string urunNum, donem, satir;
	fstream Dosya;
	fstream YeniDosya;
	vector<string>eskiUrunler;
	vector<string>eskiUrunToplamlari;
	vector<string>eskiUrunAdetleri;
	vector<string>yeniUrunler;
	vector<string>yeniUrunToplamlari;
	vector<string>yeniUrunAdetleri;
	char cevap = 'e';
	Dosya.open("hakedisler.txt", ios::in | ios::app);
	YeniDosya.open("hakedisleryeni.txt", ios::out | ios::app);
	bool kontrol = 0;
	//Projeler dosyasinda girilen proje no'nun bulunup bulunmadigi sorgulaniyor.
	if (ProjeNo_Kontrol(projeNum) == 0)
	{
		cout << "Proje no projeler listesinde mevcut degil.\n";
	}
	else
	{
		//Hakedisler dosyasinda girilen proje no'nun olup olmadigi kontrolu yapiliyor.
		if (HakedisProjeNo_Kontrol(projeNum) == 1)
		{
			cout << "Hakedis donemini giriniz.\n"; cin >> donem;
			//Proje no hakedisler dosyasinda da mevcut ise bu proje no'ya ait girilen boyle bir donem mevcut mu onun kontrolu yapiliyor. Mevcut ise tum satirlar taraniyor.
			if (HakedisteProjeNoveDonemVarMi(projeNum, donem) == 1)
			{
				while (getline(Dosya, satir))
				{
					stringstream ss(satir);
					getline(ss, hakedis.projeNo, ',');
					getline(ss, hakedis.donem, ',');
					getline(ss, hakedis.urunNo, ',');
					getline(ss, hakedis.urunAdet, ',');
					getline(ss, hakedis.urunToplamFiyat, ',');
					/*Hakedisler dosyasindan tum satirlar okunarak proje no ve donemin girdilere esit oldugu satirlar icin kosula giriyor ve true ise silinecek urun no bilgisi aliniyor.
					false ise o satir aynen yeniden yaziliyor.*/
					if (hakedis.projeNo == projeNum && hakedis.donem == donem)
					{
						cout << left << setw(12) << "ProjeNo" << setw(12) << "Donemi" << setw(35) << "Urun(ler)" << setw(20) << "Adet(ler)" << setw(20) << "Fiyat(lar)" << endl;
						cout << "--------------------------------------------------------------------------------------------------" << endl;
						cout << left << setw(12) << hakedis.projeNo << setw(12) << hakedis.donem << setw(35) << hakedis.urunNo << setw(20) << hakedis.urunAdet << setw(20) << hakedis.urunToplamFiyat << "\n";
						do
						{
							cout << "\nUrun No:"; cin >> urunNum;
							//Silinmesi istenen urunun, urunler dosyasinda bulunup bulunmadigi sorgulaniyor.
							if (urunNo_Kontrol(urunNum) == 0)
							{
								cout << "Urun no urun listesinde mevcut degil. Lutfen yeniden deneyiniz.\n";
							}
							else
							{
								/*Urun listesinde olup girilen proje ve doneme ait hakediste urunun bulunmama ihtimaline karsin bu hakediste urun no'da, girilen urun no'nun bulunup bulunmadigi
								sorgulaniyor. Girilen urun no bu hakediste mevcut ise parcala fonksiyonu ile urunNo, urunAdet, urunToplamFiyat'ta bulunan girdiler eski adi altindaki vectorlere
								aktariliyor.*/
								if (hakedis.urunNo.find(urunNum + "-") != string::npos)
								{
									const char tire = '-';
									parcala(hakedis.urunNo, tire, eskiUrunler);
									parcala(hakedis.urunToplamFiyat, tire, eskiUrunToplamlari);
									parcala(hakedis.urunAdet, tire, eskiUrunAdetleri);
									/*Bu hakediste yalnizca bir urun bulunuyor ise urunun silinebilmesi engelleniyor. Eger birden fazla urun bulunuyor ise eski adi altindaki vectorlerden
									girilen urun no'nun ait oldugu indis ve yine ayni indiste bulunan urun no'ya ait miktar, toplam fiyat bilgileri haric diger bilgiler aynen tasiniyor.*/
									if (eskiUrunler.size() > 1)
									{
										kontrol = 1;
										for (int i = 0; i < eskiUrunler.size(); i++)
										{
											if (eskiUrunler[i] != urunNum)
											{
												yeniUrunler.push_back(eskiUrunler[i]);
												yeniUrunToplamlari.push_back(eskiUrunToplamlari[i]);
												yeniUrunAdetleri.push_back(eskiUrunAdetleri[i]);
											}
										}
										hakedis.urunNo = "";
										hakedis.urunToplamFiyat = "";
										hakedis.urunAdet = "";
										for (int j = 0; j < yeniUrunler.size(); j++)
										{
											hakedis.urunNo += yeniUrunler[j] + "-";
											hakedis.urunToplamFiyat += yeniUrunToplamlari[j] + "-";
											hakedis.urunAdet += yeniUrunAdetleri[j] + "-";
										}
										cout << "Urun silindi.\n";						
									}
									else
									{
										cout << "Yalnizca 1 urun bulundugundan silme islemi yapamazsiniz.\n";
									}
									eskiUrunler.clear();
									eskiUrunToplamlari.clear();
									eskiUrunAdetleri.clear();
									yeniUrunler.clear();
									yeniUrunToplamlari.clear();
									yeniUrunAdetleri.clear();
								}
								else
								{
									cout << "Bu proje no ve doneme ait boyle bir urun kayitli degil.\n";
								}
							}
							cout << "\nBu proje no ve doneme ait baska bir urun silecek misiniz?(e/h)\n"; cin >> cevap;
						} while (!(cevap == 'h'));
						YeniDosya << hakedis.projeNo << "," << hakedis.donem << "," << hakedis.urunNo << "," << hakedis.urunAdet << "," << hakedis.urunToplamFiyat << "\n";
					}
					else
					{
						YeniDosya << hakedis.projeNo << "," << hakedis.donem << "," << hakedis.urunNo << "," << hakedis.urunAdet << "," << hakedis.urunToplamFiyat << "\n";
					}
				}
			}
			else
			{
				cout << "Proje no'ya ait boyle bir hakedis donemi mevcut degil.\n";
			}
		}
		else
		{
			cout << "Proje no hakedis listesinde olmadıgından islem yapilabilecek hakedis bulunamadi.\n";
		}
	}
	Dosya.close();
	YeniDosya.close();
	//Kayit girildiyse eski dosya siliniyor ve gecici olarak olusturulan dosya eski dosyasının adını alıyor.
	if (kontrol == 1)
	{
		remove("hakedisler.txt");
		rename("hakedisleryeni.txt", "hakedisler.txt");
		cout << "Urun(ler) silindi.\n";
	}
	else
	{
		remove("hakedisleryeni.txt");
	}
}
//Kullanicinin islemleri yapacagi ana menuye ait fonksiyon.
void AnaMenu()
{
	string urunNum, projeNum, donem;
	int secim;
	cout << "Ne islem yapmak istiyorsunuz?" << endl;
	cout << "1) Urun ekleme" << endl;
	cout << "2) Urun silme" << endl;
	cout << "3) Urun arama" << endl;
	cout << "4) Urunleri listeleme " << endl;
	cout << "5) Proje ekleme" << endl;
	cout << "6) Proje silme" << endl;
	cout << "7) Proje arama" << endl;
	cout << "8) Projeleri listeleme" << endl;
	cout << "9) Hakedis ekleme" << endl;
	cout << "10) Hakedis urun silme" << endl;
	cout << "11) Hakedis urun guncelleme" << endl;
	cout << "12) Hakedis kullanilan urun arama" << endl;
	cout << "13) Hakedis urunlerde arama" << endl;
	cout << "14) Proje no'ya göre hakedislerin total tutar goruntuleme" << endl;
	cout << "15) Doneme gore hakedis total tutari goruntuleme" << endl;
	cout << "16) Cikis" << endl;

	cin >> secim;
	switch (secim)
	{
	case 1:
		UrunEkle();
		break;
	case 2:
		cout << "Silmek istediginiz urun no yaziniz.\n"; cin >> urunNum;
		UrunSil(urunNum);
		break;
	case 3:
		cout << "Aramak istediginiz urun no yaziniz.\n"; cin >> urunNum;
		UrunAra(urunNum);
		break;
	case 4:
		UrunListele();
		break;
	case 5:
		ProjeEkle();
		break;
	case 6:
		cout << "Silmek istediginiz proje no yaziniz.\n"; cin >> projeNum;
		ProjeSil(projeNum);
		break;
	case 7:
		cout << "Aramak istediginiz proje no yaziniz.\n"; cin >> projeNum;
		ProjeAra(projeNum);
		break;
	case 8:
		ProjeListele();
		break;
	case 9:
		HakedisEkle();
		break;
	case 10:
		cout << "Proje no giriniz.\n"; cin >> projeNum;
		HakedisUrunSil(projeNum);
		break;
	case 11:
		cout << "Proje no giriniz.\n"; cin >> projeNum;
		HakedisUrunGuncelle(projeNum);
		break;
	case 12:
		cout << "Kullanilan urunleri gormek istediginiz proje no giriniz. (Proje no'ya ait eger birden fazla donem var ise tumu goruntulenecektir.)\n"; cin >> projeNum;
		HakedisKullanilanUrunListele(projeNum);
		break;
	case 13:
		cout << "Hakedislerde bulunan aramak istediginiz urun no giriniz.\n"; cin >> urunNum;
		HakedisUrunlerdeAra(urunNum);
		break;
	case 14:
		cout << "Total tutarı gormek istediginiz proje no giriniz.\n"; cin >> projeNum;
		HakedisProjeNodanTotalTutarListele(projeNum);
		break;
	case 15:
		cout << "Total tutarı gormek istediginiz donemi giriniz.\n"; cin >> donem;
		HakedisDonemdenTotalTutarListele(donem);
		break;
	case 16:
		exit(0);
		break;
	default:
		cout << "Hatali tuslama yaptiniz. Lutfen tekrar deneyiniz.\n";
		break;
	}
}
int main()
{
	setlocale(LC_ALL, "turkish");
	while (true)
	{
		system("cls");
		AnaMenu();
		cout << "\nAna menüye donmek icin herhangi bir tusuna basiniz.\n";
		system("pause");
	}
	return 0;
}