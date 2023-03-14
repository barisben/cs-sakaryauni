/****************************************************************************
**					     SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				   NESNEYE DAYALI PROGRAMLAMA DERSİ
**					   2019-2020 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........: Proje
**				ÖĞRENCİ ADI............: BARIŞ YILMAZ
**				ÖĞRENCİ NUMARASI.......: G191210303
**              DERSİN ALINDIĞI GRUP...: 2/A
****************************************************************************/

using Proje.Classes;
using System;
using System.Drawing;
using System.Windows.Forms;

namespace Proje
{
    public partial class Form1 : Form
    {
        private readonly OrganikAtikKutusu organikAtikKutusu = new OrganikAtikKutusu();
        private readonly KagitAtikKutusu kagitAtikKutusu = new KagitAtikKutusu();
        private readonly CamAtikKutusu camAtikKutusu = new CamAtikKutusu();
        private readonly MetalAtikKutusu metalAtikKutusu = new MetalAtikKutusu();
        private readonly Atik camSise = new Atik(600, Image.FromFile("camsise.jpg"));
        private readonly Atik bardak = new Atik(250, Image.FromFile("bardak.jpg"));
        private readonly Atik gazete = new Atik(250, Image.FromFile("gazete.jpg"));
        private readonly Atik dergi = new Atik(200, Image.FromFile("dergi.jpg"));
        private readonly Atik domates = new Atik(150, Image.FromFile("domates.jpg"));
        private readonly Atik salatalik = new Atik(120, Image.FromFile("salatalik.jpg"));
        private readonly Atik kolaKutusu = new Atik(350, Image.FromFile("kolakutusu.jpg"));
        private readonly Atik salcaKutusu = new Atik(550, Image.FromFile("salcakutusu.jpg"));
        //Uygulama başlatıldığında progress barların maksimum değerleri atık kutularının kapasiteleri kadar olacak şekilde ayarlanıyor.
        public Form1()
        {
            InitializeComponent();
            organikAtikBar.Maximum = organikAtikKutusu.Kapasite;
            kagitAtikBar.Maximum = kagitAtikKutusu.Kapasite;
            camAtikBar.Maximum = camAtikKutusu.Kapasite;
            metalAtikBar.Maximum = metalAtikKutusu.Kapasite;
            ButonlariDeaktifEt();
        }
        //Atık kutularının ekleme, boşaltma butonları ve listeleri deaktif ediliyor.
        public void ButonlariDeaktifEt()
        {
            OrganikAtikBosaltBtn.Enabled = false;
            KagitAtikBosaltBtn.Enabled = false;
            CamAtikBosaltBtn.Enabled = false;
            MetalAtikBosaltBtn.Enabled = false;
            OrganikAtikEkleBtn.Enabled = false;
            KagitAtikEkleBtn.Enabled = false;
            CamAtikEkleBtn.Enabled = false;
            MetalAtikEkleBtn.Enabled = false;
            organikAtikListBox.Enabled = false;
            kagitAtikListBox.Enabled = false;
            camAtikListBox.Enabled = false;
            metalAtikListBox.Enabled = false;
        }

        readonly Random rastgeleAtik = new Random();
        //Imagebox'a yeni ve rastgele bir atık getirilmesini daha öncesinde tanımlanan image yolları bir diziye atanarak sağlayan metot.
        private void YeniAtikImageEkle()
        {
            Image[] images = new Image[] { camSise.Image, bardak.Image, gazete.Image, dergi.Image, domates.Image, salatalik.Image, kolaKutusu.Image, salcaKutusu.Image };
            int atiklar = rastgeleAtik.Next(images.Length);
            atikPictureBox.Image = images[atiklar];
        }
        private void YeniOyunBtn_Click(object sender, EventArgs e)
        {
            OyunBaslat();
        }
        /*Disable olan işlevler aktif hale, yeni oyun butonu deaktif hale getiriliyor, atık kutularının progress bar değerleri ve puan sıfırlanıyor.
        Atık kutularının listeleri temizleniyor, dolu hacimleri sıfırlanıyor. Görsellik açısından panel ve label renkleri değişiyor. Labelların yeniden konumlandırılıyor.
        Süre başlatılıyor ve yeni atık fotoğrafı picturebox'a gönderiliyor.*/
        private void OyunBaslat()
        {
            OrganikAtikBosaltBtn.Enabled = true;
            KagitAtikBosaltBtn.Enabled = true;
            CamAtikBosaltBtn.Enabled = true;
            MetalAtikBosaltBtn.Enabled = true;
            OrganikAtikEkleBtn.Enabled = true;
            KagitAtikEkleBtn.Enabled = true;
            CamAtikEkleBtn.Enabled = true;
            MetalAtikEkleBtn.Enabled = true;
            organikAtikListBox.Enabled = true;
            kagitAtikListBox.Enabled = true;
            camAtikListBox.Enabled = true;
            metalAtikListBox.Enabled = true;
            YeniOyunBtn.Enabled = false;
            organikAtikBar.Value = 0;
            kagitAtikBar.Value = 0;
            camAtikBar.Value = 0;
            metalAtikBar.Value = 0;
            atikPuanToplami = 0;
            puanLabel.Text = Convert.ToString(atikPuanToplami);
            organikAtikListBox.Items.Clear();
            kagitAtikListBox.Items.Clear();
            camAtikListBox.Items.Clear();
            metalAtikListBox.Items.Clear();
            organikAtikKutusu.DoluHacim = 0;
            kagitAtikKutusu.DoluHacim = 0;
            camAtikKutusu.DoluHacim = 0;
            metalAtikKutusu.DoluHacim = 0;
            sureLabel.ForeColor = Color.White;
            timerPanel.BackColor = Color.MediumTurquoise;
            puanLabel.ForeColor = Color.White;
            puanPanel.BackColor = Color.MediumTurquoise;
            sureLabel.Text = Convert.ToString(saniyeSure);
            sureLabel.Location = new Point(88, 9);
            puanLabel.Location = new Point(97, 10);
            timer1.Start();
            YeniAtikImageEkle();
        }
        //Atık kutularına ekleme veya atık kutularını boşaltım yapıldığında güncel atık puanını tutabilmek adına atikPuanToplami oluşturuluyor.
        int atikPuanToplami = 0;
        int saniyeSure = 60;
        private void Timer1_Tick(object sender, EventArgs e)
        {
            //Timer'ın belirlenen saniyeden her saniye 1 eksiltilerek ekrana yazdırılması işlemi yapılıyor.
            saniyeSure--;
            sureLabel.Text = Convert.ToString(saniyeSure);
            //Saniye tek haneye düştüğünde görsellik açısından uygulamadaki konumu yeniden ayarlanıyor.
            if (saniyeSure < 10)
            {
                sureLabel.Location = new Point(97, 9);
            }
            /*Saniye 0 olduğunda butonlar deaktif ediliyor, timer duruyor, yeni oyun butonu yeniden aktif hale geliyor, 
            saniye yeniden sabit olan 60'a çekiliyor ve görsellik açısından oyun başlatıldığında değişen panel ve label renkleri eski haline getiriliyor.*/
            if (saniyeSure == 0)
            {
                ButonlariDeaktifEt();
                timer1.Stop();
                YeniOyunBtn.Enabled = true;
                sureLabel.ForeColor = Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
                timerPanel.BackColor = Color.MintCream;
                puanLabel.ForeColor = Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
                puanPanel.BackColor = Color.MintCream;
                saniyeSure = 60;
            }
        }
        //Puan labelının olası 3,4 ve 5 haneli sayılara geçtiğinde gerekli kontrolünü yaparak görsellik olarak yeniden konumlandıracak metot.
        private void PuanLabelKoordinatAyarla()
        {
            if (atikPuanToplami > 9999)
            {
                puanLabel.Location = new Point(66, 10);
            }
            else if (atikPuanToplami > 999)
            {
                puanLabel.Location = new Point(74, 10);
            }
            else if (atikPuanToplami > 99)
            {
                puanLabel.Location = new Point(81, 10);
            }
        }
        /*ORGANİK ATIK butonuna tıklandığında atığı alacak kadar boş yer varsa ve pictureboxtaki image o atık ise ekleme işlemi yapılır.
        Atık domates veya salatalık ise atık kutusunun listesine eklenir, hacmi kadar puan eklemesi yapılır ve ekranda güncellemesi yapılır.
        Hacmi kadar kutuya doluluk eklenir, progress barın değeri dolu hacmi olacak şekilde güncellemesi yapılır.
        Görsellik açısından labelların konum kontrolünü yapan ve atık değiştirilme metotları çağırılır.*/
        private void OrganikAtikEkleBtn_Click(object sender, EventArgs e)
        {
            if (organikAtikKutusu.Ekle(domates) == true && atikPictureBox.Image == domates.Image)
            {
                organikAtikListBox.Items.Add("Domates ("+domates.Hacim+")");
                atikPuanToplami += domates.Hacim;
                puanLabel.Text = Convert.ToString(atikPuanToplami);
                organikAtikKutusu.DoluHacim += domates.Hacim;
                organikAtikBar.Value = organikAtikKutusu.DoluHacim;
                PuanLabelKoordinatAyarla();
                YeniAtikImageEkle();
            }
            else if (organikAtikKutusu.Ekle(salatalik) == true && atikPictureBox.Image == salatalik.Image)
            {
                organikAtikListBox.Items.Add("Salatalık ("+salatalik.Hacim+")");
                atikPuanToplami += salatalik.Hacim;
                puanLabel.Text = Convert.ToString(atikPuanToplami);
                organikAtikKutusu.DoluHacim += salatalik.Hacim;
                organikAtikBar.Value = organikAtikKutusu.DoluHacim;
                PuanLabelKoordinatAyarla();
                YeniAtikImageEkle();
            }
        }
        /*KAĞIT atık butonuna tıklandığında atığı alacak kadar boş yer varsa ve pictureboxtaki image o atık ise ekleme işlemi yapılır.
        Atık gazete veya dergi ise atık kutusunun listesine eklenir, hacmi kadar puan eklemesi yapılır ve ekranda güncellemesi yapılır.
        Hacmi kadar kutuya doluluk eklenir, progress barın değeri dolu hacmi olacak şekilde güncellemesi yapılır.
        Görsellik açısından labelların konum kontrolünü yapan ve atık değiştirilme metotları çağırılır.*/
        private void KagitAtikEkleBtn_Click(object sender, EventArgs e)
        {
            if (kagitAtikKutusu.Ekle(gazete) == true && atikPictureBox.Image == gazete.Image)
            {
                kagitAtikListBox.Items.Add("Gazete ("+gazete.Hacim+")");
                atikPuanToplami += gazete.Hacim;
                puanLabel.Text = Convert.ToString(atikPuanToplami);
                kagitAtikKutusu.DoluHacim += gazete.Hacim;
                kagitAtikBar.Value = kagitAtikKutusu.DoluHacim;
                PuanLabelKoordinatAyarla();
                YeniAtikImageEkle();
            }
            else if (kagitAtikKutusu.Ekle(dergi) == true && atikPictureBox.Image == dergi.Image)
            {
                kagitAtikListBox.Items.Add("Dergi ("+dergi.Hacim+")");
                atikPuanToplami += dergi.Hacim;
                puanLabel.Text = Convert.ToString(atikPuanToplami);
                kagitAtikKutusu.DoluHacim += dergi.Hacim;
                kagitAtikBar.Value = kagitAtikKutusu.DoluHacim;
                PuanLabelKoordinatAyarla();
                YeniAtikImageEkle();
            }
        }
        /*CAM atık butonuna tıklandığında atığı alacak kadar boş yer varsa ve pictureboxtaki image o atık ise ekleme işlemi yapılır.
        Atık bardak veya cam şişe ise atık kutusunun listesine eklenir, hacmi kadar puan eklemesi yapılır ve ekranda güncellemesi yapılır.
        Hacmi kadar kutuya doluluk eklenir, progress barın değeri dolu hacmi olacak şekilde güncellemesi yapılır.
        Görsellik açısından labelların konum kontrolünü yapan ve atık değiştirilme metotları çağırılır.*/
        private void CamAtikEkleBtn_Click(object sender, EventArgs e)
        {
            if (camAtikKutusu.Ekle(bardak) == true && atikPictureBox.Image == bardak.Image)
            {
                camAtikListBox.Items.Add("Bardak ("+bardak.Hacim+")");
                atikPuanToplami += bardak.Hacim;
                puanLabel.Text = Convert.ToString(atikPuanToplami);
                camAtikKutusu.DoluHacim += bardak.Hacim;
                camAtikBar.Value = camAtikKutusu.DoluHacim;
                PuanLabelKoordinatAyarla();
                YeniAtikImageEkle();
            }
            else if (camAtikKutusu.Ekle(camSise) == true && atikPictureBox.Image == camSise.Image)
            {
                camAtikListBox.Items.Add("Cam Şişe ("+camSise.Hacim+")");
                atikPuanToplami += camSise.Hacim;
                puanLabel.Text = Convert.ToString(atikPuanToplami);
                camAtikKutusu.DoluHacim += camSise.Hacim;
                camAtikBar.Value = camAtikKutusu.DoluHacim;
                PuanLabelKoordinatAyarla();
                YeniAtikImageEkle();
            }
        }
        /*METAL atık butonuna tıklandığında atığı alacak kadar boş yer varsa ve pictureboxtaki image o atık ise ekleme işlemi yapılır.
        Atık salça kutusu veya kola kutusu ise atık kutusunun listesine eklenir, hacmi kadar puan eklemesi yapılır ve ekranda güncellemesi yapılır.
        Hacmi kadar kutuya doluluk eklenir, progress barın değeri dolu hacmi olacak şekilde güncellemesi yapılır.
        Görsellik açısından puan labelının konum kontrolünü yapan ve atık değiştirilme metotları çağırılır.*/
        private void MetalAtikEkleBtn_Click(object sender, EventArgs e)
        {
            if (metalAtikKutusu.Ekle(salcaKutusu) == true && atikPictureBox.Image == salcaKutusu.Image)
            {
                metalAtikListBox.Items.Add("Salça Kutusu ("+salcaKutusu.Hacim+")");
                atikPuanToplami += salcaKutusu.Hacim;
                puanLabel.Text = Convert.ToString(atikPuanToplami);
                metalAtikKutusu.DoluHacim += salcaKutusu.Hacim;
                metalAtikBar.Value = metalAtikKutusu.DoluHacim;
                PuanLabelKoordinatAyarla();
                YeniAtikImageEkle();
            }
            else if (metalAtikKutusu.Ekle(kolaKutusu) == true && atikPictureBox.Image == kolaKutusu.Image)
            {
                metalAtikListBox.Items.Add("Kola Kutusu ("+kolaKutusu.Hacim+")");
                atikPuanToplami += kolaKutusu.Hacim;
                puanLabel.Text = Convert.ToString(atikPuanToplami);
                metalAtikKutusu.DoluHacim += kolaKutusu.Hacim;
                metalAtikBar.Value = metalAtikKutusu.DoluHacim;
                PuanLabelKoordinatAyarla();
                YeniAtikImageEkle();
            }
        }
        /*Organik atığın boşalt butonuna tıklandığında kutunun doluluk oranı %75'den fazla ise süreye 3 saniye,
        puana boşaltma puanı kadar puan eklenir ve ekranda güncellenir. Progress barının değeri ve dolu hacmi sıfırlanır.
        Organik atık kutusunun listesi temizlenir ve görsellik açısından puan labelının konum kontrolünü yapan metot çağırılır. */
        private void OrganikAtikBosaltBtn_Click(object sender, EventArgs e)
        {
            if (organikAtikKutusu.Bosalt() == true)
            {
                saniyeSure += 3;
                atikPuanToplami += organikAtikKutusu.BosaltmaPuani;
                puanLabel.Text = Convert.ToString(atikPuanToplami);
                organikAtikBar.Value = 0;
                organikAtikKutusu.DoluHacim = 0;
                organikAtikListBox.Items.Clear();
                PuanLabelKoordinatAyarla();
            }
        }
        /*Kağıt atığın boşalt butonuna tıklandığında kutunun doluluk oranı %75'den fazla ise süreye 3 saniye,
        puana boşaltma puanı kadar puan eklenir ve ekranda güncellenir. Progress barının değeri ve dolu hacmi sıfırlanır.
        Kağıt atık kutusunun listesi temizlenir ve görsellik açısından puan labelının konum kontrolünü yapan metot çağırılır. */
        private void KagitAtikBosaltBtn_Click(object sender, EventArgs e)
        {
            if (kagitAtikKutusu.Bosalt() == true)
            {
                saniyeSure += 3;
                atikPuanToplami += kagitAtikKutusu.BosaltmaPuani;
                puanLabel.Text = Convert.ToString(atikPuanToplami);
                kagitAtikBar.Value = 0;
                kagitAtikKutusu.DoluHacim = 0;
                kagitAtikListBox.Items.Clear();
                PuanLabelKoordinatAyarla();
            }
        }
        /*Cam atığın boşalt butonuna tıklandığında kutunun doluluk oranı %75'den fazla ise süreye 3 saniye,
        puana boşaltma puanı kadar puan eklenir ve ekranda güncellenir. Progress barının değeri ve dolu hacmi sıfırlanır.
        Cam atık kutusunun listesi temizlenir ve görsellik açısından puan labelının konum kontrolünü yapan metot çağırılır. */
        private void CamAtikBosaltBtn_Click(object sender, EventArgs e)
        {
            if (camAtikKutusu.Bosalt() == true)
            {
                saniyeSure += 3;
                atikPuanToplami += camAtikKutusu.BosaltmaPuani;
                puanLabel.Text = Convert.ToString(atikPuanToplami);
                camAtikBar.Value = 0;
                camAtikKutusu.DoluHacim = 0;
                camAtikListBox.Items.Clear();
                PuanLabelKoordinatAyarla();
            }
        }
        /*Metal atığın boşalt butonuna tıklandığında kutunun doluluk oranı %75'den fazla ise süreye 3 saniye,
        puana boşaltma puanı kadar puan eklenir ve ekranda güncellenir. Progress barının değeri ve dolu hacmi sıfırlanır.
        Metal atık kutusunun listesi temizlenir ve görsellik açısından puan labelının konum kontrolünü yapan metot çağırılır. */
        private void MetalAtikBosaltBtn_Click(object sender, EventArgs e)
        {
            if (metalAtikKutusu.Bosalt() == true)
            {
                saniyeSure += 3;
                atikPuanToplami += metalAtikKutusu.BosaltmaPuani;
                puanLabel.Text = Convert.ToString(atikPuanToplami);
                metalAtikBar.Value = 0;
                metalAtikKutusu.DoluHacim = 0;
                metalAtikListBox.Items.Clear();
                PuanLabelKoordinatAyarla();
            }
        }
        //Çıkış butonuna basıldığında uygulamanın kapatılması işlemi yapılır.
        private void CikisBtn_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}