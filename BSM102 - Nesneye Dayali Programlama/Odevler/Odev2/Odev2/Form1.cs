/****************************************************************************
**					     SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				   NESNEYE DAYALI PROGRAMLAMA DERSİ
**					   2019-2020 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........: 2
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
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Odev2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        //arkadasMiBtn (ARKADAS MI?) tıklandığında 2. fotoğraftaki görünümün oluşması için gerekli oluşturmalar yapılıyor. Bu sayede birden fazla tıklama sonucu tekrarlar engelleniyor.
        private Label x = new Label();
        private Label y = new Label();
        private ListBox listBox1 = new ListBox();
        private ListBox listBox2 = new ListBox();
        private Label toplamlar = new Label();
        private TextBox toplamlarXBox = new TextBox();
        private TextBox toplamlarYBox = new TextBox();
        private Label sonuc = new Label();
        private TextBox sonucBox = new TextBox();

        private void arkadasMiBtn_Click(object sender, EventArgs e)
        {
            //Her tıklandığında önce temizlenerek çalışmaları sağlanıyor.
            listBox1.Items.Clear();
            listBox2.Items.Clear();
            toplamlarXBox.Clear();
            toplamlarYBox.Clear();
            sonucBox.Clear();

            Size = new Size(590, 290);
            
            //Oluşturulanların pencerede konumlarına yerleştirilmesi, boyutlandırılması, isimlendirilmesi işlemleri yapılıyor.
            x.Text = "X";
            x.Location = new Point(377, 6);
            x.AutoSize = true;
            listBox1.Size = new Size(79, 160);
            listBox1.Location = new Point(346, 25);
            
            y.Text = "Y";
            y.Location = new Point(505, 6);
            y.AutoSize = true;
            listBox2.Location = new Point(474, 25);
            listBox2.Size = new Size(79, 160);
 
            toplamlar.Text = "TOPLAMLAR";
            toplamlar.AutoSize = true;
            toplamlar.Location = new Point(255, 209);
            
            toplamlarXBox.Location = new Point(346, 206);
            toplamlarXBox.Size = new Size(79, 20);
            toplamlarYBox.Location = new Point(474, 206);
            toplamlarYBox.Size = new Size(79, 20);
            
            sonuc.Text = "SONUC:";
            sonuc.AutoSize = true;
            sonuc.Location = new Point(27, 209);

            sonucBox.Location = new Point(81, 206);
            sonucBox.Size = new Size(139, 20);

            int xDegeri, yDegeri;
            int carpanlarToplamiX = 0, carpanlarToplamiY = 0;
            xDegeri = int.Parse(textBox1.Text);
            yDegeri = int.Parse(textBox2.Text);

            int carpanXSayac = 1;
            //X'in değerinden kücük tüm pozitif tamsayılarla karşılaştırılma yapılarak çarpanlarının bulunması işlemi yapılıyor.
            while (carpanXSayac < xDegeri)
            {
                //Eğer eldeki sayı X ile kalansız bölünür ise listeye yazılması ve toplam kısmı için de bu sayının toplanması sağlanıyor.
                if (xDegeri % carpanXSayac == 0)
                {
                    carpanlarToplamiX += carpanXSayac;
                    listBox1.Items.Add(carpanXSayac);
                }
                carpanXSayac++;
            }

            int carpanYSayac = 1;

            //Y'nin değerinden kücük tüm pozitif tamsayılarla karşılaştırılma yapılarak çarpanlarının bulunması işlemi yapılıyor.
            while (carpanYSayac < yDegeri)
            {
                //Eğer eldeki sayı Y ile kalansız bölünür ise listeye yazılması ve toplam kısmı için de bu sayının toplanması sağlanıyor.
                if (yDegeri % carpanYSayac == 0)
                {
                    carpanlarToplamiY += carpanYSayac;
                    listBox2.Items.Add(carpanYSayac);
                }
                carpanYSayac++;
            }

            //Arkadaş sayı olup olmadıklarının kontrolü yapılıyor, duruma göre Sonuç kısmına arkadaş olup olmadıkları yazdırılıyor.
            if (carpanlarToplamiX == yDegeri && carpanlarToplamiY == xDegeri)
            {
                sonucBox.Text = "Arkadas sayilardir.";
            }
            else
            {
                sonucBox.Text = "Arkadas sayi degiller.";
            }

            toplamlarXBox.Text = Convert.ToString(carpanlarToplamiX);
            toplamlarYBox.Text = Convert.ToString(carpanlarToplamiY);

            //Pencerede gözükmeleri sağlanıyor.
            Controls.Add(x);
            Controls.Add(y);
            Controls.Add(sonuc);
            Controls.Add(sonucBox);
            Controls.Add(toplamlar);
            Controls.Add(toplamlarXBox);
            Controls.Add(toplamlarYBox);
            Controls.Add(listBox1);
            Controls.Add(listBox2);
        }

        //Son butonuna basıldığı durumda uygulamanın kapatılması sağlanıyor.
        private void sonBtn_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
