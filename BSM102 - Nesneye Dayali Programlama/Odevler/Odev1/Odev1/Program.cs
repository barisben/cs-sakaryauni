/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				   NESNEYE DAYALI PROGRAMLAMA DERSİ
**					2018-2019 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........:1
**				ÖĞRENCİ ADI............:BARIŞ YILMAZ
**				ÖĞRENCİ NUMARASI.......:G191210303
**              DERSİN ALINDIĞI GRUP...:
****************************************************************************/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Odev1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] isimler = new string[] { "Servet", "Çilem", "Recep", "Emre", "Ayberk", "Hacer", "Ercüment", "Sarper", "Berker", "İclal", "Lemis", "Polat", "Kerem", "Raşit", "Ecem", "Nüket", "Senem", "Ayşen", "Pekcan", "Bedirhan", "Semina", "Eda", "Müyesser", "Bahar", "Özlem", "Kutlu", "Nesibe", "Ömer", "Buğra", "Mazlum", "Tuğçe", "Ahmet", "Yaşar", "Utku", "Anıl", "Rana", "Fethullah", "Burak", "Merve", "Ece", "Dilay", "Begüm", "Büşra", "Gül", "Hikmet", "Nazlı", "İsmail", "Umut", "İlkay", "Ramazan", "İlyas", "Halim", "Şükrü", "Deniz", "İzlem", "Şeyda", "Zeki", "Yiğithan", "Şerife", "Mustafa", "Burhan", "Hayrunnisa", "Hanife", "Duygu", "Sevtap", "Gökçen", "Çisem", "Sabiha", "Elvan", "Edip", "Almina", "Saime", "Kaan", "Muharrem", "Murat", "Sinan", "Ateş", "Zeynep", "Nihan", "Hami", "Güneş", "Feyza", "Uğur", "Ali", "Yasin", "Adem", "Sera", "Cansın", "Mehmet", "Mercan", "Gökay", "Özgün", "Özgen", "Gülser", "Yüksel", "Ecren", "Muhammet", "Sakıp", "Kazım", "Enes" };
            string[] soyisimler = new string[] { "Akçagunay", "Akçay", "Akdoğan", "Akfırat", "Akıllı", "Akıncılar", "Akış", "Akkiray", "Akkoyun", "Akküt", "Aklar", "Akman", "Akoğuz", "Akova", "Aksan", "Aksevim", "Aksoy", "Aksöz", "Akşamoğlu", "Aktuna", "Akyıldız", "Akyildirim", "Al", "Albaş", "Aldağ", "Beyoğlu", "Alkan", "Alparslan", "Alpuğan", "Altan", "Altaş", "Altay", "Altın", "Altınoklu", "Altıntaş", "Altıok", "Altıparmak", "Altinkaya", "Altunbaş", "Altunbulak", "Altundal", "Aluç", "Alver", "Anık", "Ankara", "Ansen", "Apul", "Aral", "Arap", "Arat", "Ardıç", "Arıcan", "Arınç", "Arif", "Arikan", "Armutcu", "Arpacı", "Aruca", "Asil", "Askın", "Aslantürk", "Aşcı", "Aşveren", "Ata", "Atan", "Ateş", "Ateşcan", "Atlı", "Atmaca", "Atok", "Atol", "Attila", "Avcı Özsoy", "Avıandı", "Avşar", "Ay", "Ayanoglu", "Ayaz", "Aycı", "Aydınlıoğlu", "Yozgat", "Aydoğdu", "Aygen", "Aykan", "Ayrım", "Aysal", "Aysan", "Ayvacık", "Azbay", "Babacan", "Babadostu", "Bad", "Bağcı", "Bağçivan", "Bağış", "Bahçeli", "Bahtıyar", "Baka", "Baki", "Bal" };
            Random rastgele = new Random();
            int ogrNo, isimlerIndexNo, soyisimlerIndexNo;
            double odevNot1, odevNot2, vizeNot, finalNot;
            double odev1Yuzde = 10;
            double odev2Yuzde = 10;
            double vizeYuzde = 30;  
            double finalYuzde = 50;
            List<int> ogrNoTekrarEngelleme = new List<int>();
            List<int> isimlerTekrarEngelleme = new List<int>();
            List<int> soyisimlerTekrarEngelleme = new List<int>();           
            string dosyaYolu = @"ogrenciBilgileri.txt";
            using (StreamWriter ogrenciBilgileri = new StreamWriter(@"ogrenciBilgileri.txt"))
            {
                ogrenciBilgileri.WriteLine(String.Format("{0,-11} {1,-11} {2,-11} {3,-11}", odev1Yuzde, odev2Yuzde, vizeYuzde, finalYuzde));
                ogrenciBilgileri.WriteLine();
                for (int i = 0; i < 100; i++)
                {
                    odevNot1 = rastgele.Next(101);
                    odevNot2 = rastgele.Next(101);
                    vizeNot = rastgele.Next(101);
                    finalNot = rastgele.Next(101);

                    do
                    {
                        ogrNo = rastgele.Next(1000, 1100);

                        if (ogrNoTekrarEngelleme.Contains(ogrNo) == false)
                        {
                            ogrNoTekrarEngelleme.Add(ogrNo);
                            break;
                        }
                    } while (true);

                    do
                    {
                        isimlerIndexNo = rastgele.Next(isimler.Length);

                        if (isimlerTekrarEngelleme.Contains(isimlerIndexNo) == false)
                        {
                            isimlerTekrarEngelleme.Add(isimlerIndexNo);
                            break;
                        }

                    } while (true);

                    do
                    {
                        soyisimlerIndexNo = rastgele.Next(soyisimler.Length);

                        if (soyisimlerTekrarEngelleme.Contains(soyisimlerIndexNo) == false)
                        {
                            soyisimlerTekrarEngelleme.Add(soyisimlerIndexNo);
                            break;
                        }
                    } while (true);

                    ogrenciBilgileri.WriteLine(String.Format("{0,-11} {1,-11} {2,-11} {3,-11} {4,-11} {5,-11} {6,-11}", isimler[isimlerIndexNo], soyisimler[soyisimlerIndexNo], ogrNo, odevNot1, odevNot2, vizeNot, finalNot));
                }
            }
            Console.WriteLine("Ogrenci ortalamalarini hesaplamak istiyor musunuz? Istiyorsaniz 'E' tusuna basiniz. ");
            char secim = Convert.ToChar(Console.ReadLine());
            if (secim == 'E' || secim == 'e')
            {
                List<double> notAA = new List<double>();
                List<double> notBA = new List<double>();
                List<double> notBB = new List<double>();
                List<double> notCB = new List<double>();
                List<double> notCC = new List<double>();
                List<double> notDC = new List<double>();
                List<double> notDD = new List<double>();
                List<double> notFD = new List<double>();
                List<double> notFF = new List<double>();
                double odev1NotOku, odev1NotOrt, odev2NotOku, odev2NotOrt, vizeNotOku, vizeNotOrt, finalNotOku, finalNotOrt, notOrtToplam;
                var satirlar = File.ReadAllLines(dosyaYolu);
                for (int i = 2; i < 102; i++)
                {
                    odev1NotOku = Convert.ToDouble(satirlar[i].Substring(36, 2));
                    odev1NotOrt = (odev1NotOku * (Convert.ToDouble(satirlar[0].Substring(0, 2)))) / 100;
                    odev2NotOku = Convert.ToDouble(satirlar[i].Substring(48, 2));
                    odev2NotOrt = (odev2NotOku * (Convert.ToDouble(satirlar[0].Substring(12, 2)))) / 100;
                    vizeNotOku = Convert.ToDouble(satirlar[i].Substring(60, 2));
                    vizeNotOrt = (vizeNotOku * (Convert.ToDouble(satirlar[0].Substring(24, 2)))) / 100;
                    finalNotOku = Convert.ToDouble(satirlar[i].Substring(72, 2));
                    finalNotOrt = (finalNotOku * (Convert.ToDouble(satirlar[0].Substring(36, 2)))) / 100;

                    notOrtToplam = odev1NotOrt + odev2NotOrt + vizeNotOrt + finalNotOrt;

                    if (notOrtToplam >= 90.00 && notOrtToplam <= 100.00)
                        notAA.Add(notOrtToplam);
                    else if (notOrtToplam >= 85.00 && notOrtToplam <= 89.99)
                        notBA.Add(notOrtToplam);
                    else if (notOrtToplam >= 80.00 && notOrtToplam <= 84.99)
                        notBB.Add(notOrtToplam);
                    else if (notOrtToplam >= 75.00 && notOrtToplam <= 79.99)
                        notCB.Add(notOrtToplam);
                    else if (notOrtToplam >= 65.00 && notOrtToplam <= 74.99)
                        notCC.Add(notOrtToplam);
                    else if (notOrtToplam >= 58.00 && notOrtToplam <= 64.99)
                        notDC.Add(notOrtToplam);
                    else if (notOrtToplam >= 50.00 && notOrtToplam <= 57.99)
                        notDD.Add(notOrtToplam);
                    else if (notOrtToplam >= 40.00 && notOrtToplam <= 49.99)
                        notFD.Add(notOrtToplam);
                    else
                        notFF.Add(notOrtToplam);
                }
                double notAAYuzde = (notAA.Count / Convert.ToDouble(isimler.Length)) * 100;
                double notBAYuzde = (notBA.Count / Convert.ToDouble(isimler.Length)) * 100;
                double notBBYuzde = (notBB.Count / Convert.ToDouble(isimler.Length)) * 100;
                double notCBYuzde = (notCB.Count / Convert.ToDouble(isimler.Length)) * 100;
                double notCCYuzde = (notCC.Count / Convert.ToDouble(isimler.Length)) * 100;
                double notDCYuzde = (notDC.Count / Convert.ToDouble(isimler.Length)) * 100;
                double notDDYuzde = (notDD.Count / Convert.ToDouble(isimler.Length)) * 100;
                double notFDYuzde = (notFD.Count / Convert.ToDouble(isimler.Length)) * 100;
                double notFFYuzde = (notFF.Count / Convert.ToDouble(isimler.Length)) * 100;
                int gecenOgrenciSayisi = notAA.Count + notBA.Count + notBB.Count + notCB.Count + notCC.Count + notDC.Count + notDD.Count;
                int kalanOgrenciSayisi = notFD.Count + notFF.Count;

                
                using (StreamWriter sonucBilgileri = new StreamWriter(@"sonuc.txt"))
                {
                    sonucBilgileri.WriteLine(String.Format("{0,-11} {1,-11} {2,-11}", "AA", notAA.Count, "%" + notAAYuzde));
                    sonucBilgileri.WriteLine(String.Format("{0,-11} {1,-11} {2,-11}", "BA", notBA.Count, "%" + notBAYuzde));
                    sonucBilgileri.WriteLine(String.Format("{0,-11} {1,-11} {2,-11}", "BB", notBB.Count, "%" + notBBYuzde));
                    sonucBilgileri.WriteLine(String.Format("{0,-11} {1,-11} {2,-11}", "CB", notCB.Count, "%" + notCBYuzde));
                    sonucBilgileri.WriteLine(String.Format("{0,-11} {1,-11} {2,-11}", "CC", notCC.Count, "%" + notCCYuzde));
                    sonucBilgileri.WriteLine(String.Format("{0,-11} {1,-11} {2,-11}", "DC", notDC.Count, "%" + notDCYuzde));
                    sonucBilgileri.WriteLine(String.Format("{0,-11} {1,-11} {2,-11}", "DD", notDD.Count, "%" + notDDYuzde));
                    sonucBilgileri.WriteLine(String.Format("{0,-11} {1,-11} {2,-11}", "FD", notFD.Count, "%" + notFDYuzde));
                    sonucBilgileri.WriteLine(String.Format("{0,-11} {1,-11} {2,-11}", "FF", notFF.Count, "%" + notFFYuzde));
                    sonucBilgileri.WriteLine("Gecen ogrenci sayisi: " + gecenOgrenciSayisi);
                    sonucBilgileri.WriteLine("Kalan ogrenci sayisi: " + kalanOgrenciSayisi);
                }
                Console.WriteLine("Istatistikler sonuc.txt dosyasina islenmistir.");
            }
            else
            {
                Console.WriteLine("Herhangi bir tusa bastiginizde program sona erecektir.");
            }
            Console.ReadKey();
        }
    }
}
