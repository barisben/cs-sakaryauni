/****************************************************************************
**					     SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				   NESNEYE DAYALI PROGRAMLAMA DERSİ
**					   2019-2020 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........: 3
**				ÖĞRENCİ ADI............: BARIŞ YILMAZ
**				ÖĞRENCİ NUMARASI.......: G191210303
**              DERSİN ALINDIĞI GRUP...: 2/A
****************************************************************************/

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Http.Headers;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Odev3
{
    public partial class Form1 : Form
    {
        class Urun
        {
            public string Ad { get; set; }
            public string Marka { get; set; }
            public string Model { get; set; }
            public string Ozellik { get; set; }
            public int StokAdedi { get; set; }
            public int HamFiyat { get; set; }
            public int SecilenAdet { get; set; }
            public static Random rndStokAdedi = new Random();
            public Urun(string _ad, string _marka, string _model, string _ozellik, int _hamFiyat, int _secilenAdet)
            {
                Ad = _ad;
                Marka = _marka;
                Model = _model;
                Ozellik = _ozellik;
                HamFiyat = _hamFiyat;
                SecilenAdet = _secilenAdet;
            }
            public virtual double KdvUygula()
            {
                return 0;
            }
        }
        class LedTv : Urun
        {
            public double EkranBoyutu { get; set; }
            public string EkranCozunurlugu { get; set; }
            public LedTv(double _ekranBoyutu, string _ekranCozunurlugu, string _ad, string _marka, string _model, string _ozellik, int _hamFiyat, int _secilenAdet)
                : base(_ad, _marka, _model, _ozellik, _hamFiyat, _secilenAdet)
            {
                EkranBoyutu = _ekranBoyutu;
                EkranCozunurlugu = _ekranCozunurlugu;
                StokAdedi = rndStokAdedi.Next(1, 100);
            }
            public override double KdvUygula()
            {
                return Math.Round(HamFiyat * SecilenAdet * 1.18);
            }
        }
        class Buzdolabi : Urun
        {
            public string EnerjiSinifi { get; set; }
            public int IcHacim { get; set; }
            public Buzdolabi(string _enerjiSinifi, int _icHacim, string _ad, string _marka, string _model, string _ozellik, int _hamFiyat, int _secilenAdet)
                : base(_ad, _marka, _model, _ozellik, _hamFiyat, _secilenAdet)
            {
                EnerjiSinifi = _enerjiSinifi;
                IcHacim = _icHacim;
                StokAdedi = rndStokAdedi.Next(1, 100);
            }
            public override double KdvUygula()
            {
                return Math.Round(HamFiyat * SecilenAdet * 1.05);
            }
        }
        class Laptop : Urun
        {
            public int DahiliHafiza { get; set; }
            public int RamKapasitesi { get; set; }
            public int PilGucu { get; set; }
            public double EkranBoyutu { get; set; }
            public string EkranCozunurlugu { get; set; }
            public Laptop(double _ekranBoyutu, string _ekranCozunurlugu, int _dahiliHafiza, int _ramKapasitesi, int _pilGucu, string _ad, string _marka, string _model, string _ozellik, int _hamFiyat, int _secilenAdet)
                : base(_ad, _marka, _model, _ozellik, _hamFiyat, _secilenAdet)
            {
                EkranBoyutu = _ekranBoyutu;
                EkranCozunurlugu = _ekranCozunurlugu;
                DahiliHafiza = _dahiliHafiza;
                RamKapasitesi = _ramKapasitesi;
                PilGucu = _pilGucu;
                StokAdedi = rndStokAdedi.Next(1, 100);
            }
            public override double KdvUygula()
            {
                return Math.Round(HamFiyat * SecilenAdet * 1.15);
            }
        }
        class CepTel : Urun
        {
            public int DahiliHafiza { get; set; }
            public int RamKapasitesi { get; set; }
            public int PilGucu { get; set; }
            public CepTel(int _dahiliHafiza, int _ramKapasitesi, int _pilGucu, string _ad, string _marka, string _model, string _ozellik, int _hamFiyat, int _secilenAdet)
                : base(_ad, _marka, _model, _ozellik, _hamFiyat, _secilenAdet)
            {
                DahiliHafiza = _dahiliHafiza;
                RamKapasitesi = _ramKapasitesi;
                PilGucu = _pilGucu;
                StokAdedi = rndStokAdedi.Next(1, 100);
            }
            public override double KdvUygula()
            {
                return Math.Round(HamFiyat * SecilenAdet * 1.20);
            }
        }
        class Sepet
        {
            //Eklenen ürünler "urunler" isimli listeye aktarılıyor ve toplam ürüne kdv uygulandıktan sonra toplam fiyata ekleniyor.
            public List<Urun> urunler = new List<Urun>();
            public double toplamFiyat = 0.0;
            public void SepeteUrunEkle(Urun urun)
            {
                urunler.Add(urun);
                toplamFiyat += urun.KdvUygula();
            }
        }
        private void UrunuKaldir(string urun)
        {
            //Ürün sepette ekliyken yeniden ekleme işlemi yapılacaksa öncelikle bulunduğu sıra döngü ile bulunuyor.
            for (var i = 0; i < listBox2.Items.Count; i++)
            {
                //Verilen string değerin satırı bulununca koşul sağlanıyor. Adet, kdv'li fiyat bilgileri listeden çıkartılıyor, KDV'li tutarın da toplam tutardan eksiltilmesi işlemi yapılıyor.
                if (listBox2.Items[i].ToString() == urun)
                {
                    double urunEskiFiyat = Convert.ToDouble(listBox3.Items[i]);
                    sepet.toplamFiyat -= urunEskiFiyat;
                    listBox1.Items.RemoveAt(i);
                    listBox2.Items.RemoveAt(i);
                    listBox3.Items.RemoveAt(i);
                    sepet.urunler.RemoveAt(i);
                }
            }
        }
        Sepet sepet = new Sepet();
        Urun ledTv = new LedTv(0, "", "", "", "", "", 4000, 0);
        Urun cepTel = new CepTel(1, 1, 1, "", "", "", "", 2500, 0);
        Urun buzdolabi = new Buzdolabi("", 1, "", "", "", "", 3500, 0);
        Urun laptop = new Laptop(1.0, "", 1, 1, 1, "", "", "", "", 6000, 0);
        //Ürünleri Sepete Ekle butonuna tıklandığında öncelikle gerekli kontroller yapılıyor, KDV'li Toplam fiyat hesaplanarak ekranda gösteriliyor.
        private void SepeteEkleBtn_Click(object sender, EventArgs e)
        {
            //Eğer Led TV'nin adedi 0'dan büyük seçilip sepete ekle butonuna basarsa koşul sağlanıyor.
            if ((ledTv.SecilenAdet = (int)numericUpDown1.Value) > 0)
            {
                //Halihazırda sepette Led Tv ürünü bulunuyorsa öncelikle sepetten çıkartılıyor, ardından yeni veriler giriliyor ve stok güncellenerek ekrana da yazılıyor.
                if (listBox2.Items.Contains("Led TV"))
                {
                    UrunuKaldir("Led TV");
                    listBox1.Items.Add(numericUpDown1.Value);
                    listBox2.Items.Add("Led TV");
                    listBox3.Items.Add(ledTv.KdvUygula());
                    sepet.SepeteUrunEkle(ledTv);
                    labelLedTvStok.Text = (ledTv.StokAdedi - ledTv.SecilenAdet).ToString();
                }
                /*Sepete ilk kez bu ürün eklendiği durumda ürünün sepete eklenmesi ve stoktan eksiltilmesi işlemi yapılıyor. Aynı zamanda minimum adet seçimi 1 olarak güncelleniyor,
                kullanıcı sepeti temizlemeden ürünü sepetten tamamen silemiyor.*/
                else
                {
                    listBox1.Items.Add(numericUpDown1.Value);
                    listBox2.Items.Add("Led TV");
                    listBox3.Items.Add(ledTv.KdvUygula());
                    labelLedTvStok.Text = (ledTv.StokAdedi - ledTv.SecilenAdet).ToString();
                    sepet.SepeteUrunEkle(ledTv);
                    numericUpDown1.Minimum = 1;
                }
            }
            //Eğer Cep Telefonu'nun adedi 0'dan büyük seçilip sepete ekle butonuna basarsa koşul sağlanıyor.
            if ((cepTel.SecilenAdet = (int)numericUpDown4.Value) > 0)
            {
                //Halihazırda sepette Cep Telefonu ürünü bulunuyorsa öncelikle sepetten çıkartılıyor, ardından yeni veriler giriliyor ve stok güncellenerek ekrana da yazılıyor.
                if (listBox2.Items.Contains("Cep Telefonu"))
                {
                    UrunuKaldir("Cep Telefonu");
                    listBox1.Items.Add(numericUpDown4.Value);
                    listBox2.Items.Add("Cep Telefonu");
                    listBox3.Items.Add(cepTel.KdvUygula());
                    sepet.SepeteUrunEkle(cepTel);
                    labelCepTelStok.Text = (cepTel.StokAdedi - cepTel.SecilenAdet).ToString();
                }
                /*Sepete ilk kez bu ürün eklendiği durumda ürünün sepete eklenmesi ve stoktan eksiltilmesi işlemi yapılıyor. Aynı zamanda minimum adet seçimi 1 olarak güncelleniyor,
                kullanıcı sepeti temizlemeden ürünü sepetten tamamen silemiyor.*/
                else
                {
                    listBox1.Items.Add(numericUpDown4.Value);
                    listBox2.Items.Add("Cep Telefonu");
                    listBox3.Items.Add(cepTel.KdvUygula());
                    labelCepTelStok.Text = (cepTel.StokAdedi - cepTel.SecilenAdet).ToString();
                    sepet.SepeteUrunEkle(cepTel);
                    numericUpDown4.Minimum = 1;
                }
            }
            //Eğer Laptop'un adedi 0'dan büyük seçilip sepete ekle butonuna basarsa koşul sağlanıyor.
            if ((laptop.SecilenAdet = (int)numericUpDown3.Value) > 0)
            {
                //Halihazırda sepette Laptop ürünü bulunuyorsa öncelikle sepetten çıkartılıyor, ardından yeni veriler giriliyor ve stok güncellenerek ekrana da yazılıyor.
                if (listBox2.Items.Contains("Laptop"))
                {
                    UrunuKaldir("Laptop");
                    listBox1.Items.Add(numericUpDown3.Value);
                    listBox2.Items.Add("Laptop");
                    listBox3.Items.Add(laptop.KdvUygula());
                    sepet.SepeteUrunEkle(laptop);
                    labelLaptopStok.Text = (laptop.StokAdedi - laptop.SecilenAdet).ToString();
                }
                /*Sepete ilk kez bu ürün eklendiği durumda ürünün sepete eklenmesi ve stoktan eksiltilmesi işlemi yapılıyor. Aynı zamanda minimum adet seçimi 1 olarak güncelleniyor,
                kullanıcı sepeti temizlemeden ürünü sepetten tamamen silemiyor.*/
                else
                {
                    listBox1.Items.Add(numericUpDown3.Value);
                    listBox2.Items.Add("Laptop");
                    listBox3.Items.Add(laptop.KdvUygula());
                    labelLaptopStok.Text = (laptop.StokAdedi - laptop.SecilenAdet).ToString();
                    sepet.SepeteUrunEkle(laptop);
                    numericUpDown3.Minimum = 1;
                }
            }
            //Eğer Buzdolabı'nın adedi 0'dan büyük seçilip sepete ekle butonuna basarsa koşul sağlanıyor.
            if ((buzdolabi.SecilenAdet = (int)numericUpDown2.Value) > 0)
            {
                //Halihazırda sepette Buzdolabı ürünü bulunuyorsa öncelikle sepetten çıkartılıyor, ardından yeni veriler giriliyor ve stok güncellenerek ekrana da yazılıyor.
                if (listBox2.Items.Contains("Buzdolabi"))
                {
                    UrunuKaldir("Buzdolabi");
                    listBox1.Items.Add(numericUpDown2.Value);
                    listBox2.Items.Add("Buzdolabi");
                    listBox3.Items.Add(buzdolabi.KdvUygula());
                    sepet.SepeteUrunEkle(buzdolabi);
                    labelBuzdolabiStok.Text = (buzdolabi.StokAdedi - buzdolabi.SecilenAdet).ToString();
                }
                /*Sepete ilk kez bu ürün eklendiği durumda ürünün sepete eklenmesi ve stoktan eksiltilmesi işlemi yapılıyor. Aynı zamanda minimum adet seçimi 1 olarak güncelleniyor,
                kullanıcı sepeti temizlemeden ürünü sepetten tamamen silemiyor.*/
                else
                {
                    listBox1.Items.Add(numericUpDown2.Value);
                    listBox2.Items.Add("Buzdolabi");
                    listBox3.Items.Add(buzdolabi.KdvUygula());
                    labelBuzdolabiStok.Text = (buzdolabi.StokAdedi - buzdolabi.SecilenAdet).ToString();
                    sepet.SepeteUrunEkle(buzdolabi);
                    numericUpDown2.Minimum = 1;
                }
            }
            labelToplamFiyat.Text = sepet.toplamFiyat.ToString() + " TL";
        }
        /*Sepeti Temizle butonuna tıklandığında ürünler sepetten çıkartılıyor, listeler temizleniyor, KDV'li toplam fiyat 0'lanıyor, program açıldığında random gelmiş olan stok adetleri tekrar yazdırılıyor
        ve numericupdown'lar minimum 0 olarak ayarlanarak adetlerin de 0'dan başlatılması sağlanıyor.*/
        private void SepetiTemizleBtn_Click(object sender, EventArgs e)
        {
            sepet.urunler.Clear();
            listBox1.Items.Clear();
            listBox2.Items.Clear();
            listBox3.Items.Clear();
            sepet.toplamFiyat = 0;
            labelToplamFiyat.Text = "-";
            numericUpDown1.Minimum = 0;
            numericUpDown2.Minimum = 0;
            numericUpDown3.Minimum = 0;
            numericUpDown4.Minimum = 0;
            numericUpDown1.Value = 0;
            numericUpDown2.Value = 0;
            numericUpDown3.Value = 0;
            numericUpDown4.Value = 0;
            labelLedTvStok.Text = ledTv.StokAdedi.ToString();
            labelCepTelStok.Text = cepTel.StokAdedi.ToString();
            labelBuzdolabiStok.Text = buzdolabi.StokAdedi.ToString();
            labelLaptopStok.Text = laptop.StokAdedi.ToString();
        }
        //Program başlatıldığında adet seçimi yaparken seçilecek adedin maksimum atanan random sayısı kadar olması ve stok adedi sayısının görünmesi sağlanıyor.
        public Form1()
        {
            InitializeComponent();
            labelLedTvStok.Text = ledTv.StokAdedi.ToString();
            labelCepTelStok.Text = cepTel.StokAdedi.ToString();
            labelBuzdolabiStok.Text = buzdolabi.StokAdedi.ToString();
            labelLaptopStok.Text = laptop.StokAdedi.ToString();
            numericUpDown1.Maximum = ledTv.StokAdedi;
            numericUpDown2.Maximum = buzdolabi.StokAdedi;
            numericUpDown3.Maximum = laptop.StokAdedi;
            numericUpDown4.Maximum = cepTel.StokAdedi;
        }
    }
}