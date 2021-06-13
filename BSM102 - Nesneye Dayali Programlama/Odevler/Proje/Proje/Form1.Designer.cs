namespace Proje
{
    partial class Form1
    {
        /// <summary>
        ///Gerekli tasarımcı değişkeni.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///Kullanılan tüm kaynakları temizleyin.
        /// </summary>
        ///<param name="disposing">yönetilen kaynaklar dispose edilmeliyse doğru; aksi halde yanlış.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer üretilen kod

        /// <summary>
        /// Tasarımcı desteği için gerekli metot - bu metodun 
        ///içeriğini kod düzenleyici ile değiştirmeyin.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.panel1 = new System.Windows.Forms.Panel();
            this.atikPictureBox = new System.Windows.Forms.PictureBox();
            this.panel2 = new System.Windows.Forms.Panel();
            this.puanPanel = new System.Windows.Forms.Panel();
            this.puanLabel = new System.Windows.Forms.Label();
            this.timerPanel = new System.Windows.Forms.Panel();
            this.sureLabel = new System.Windows.Forms.Label();
            this.panel6 = new System.Windows.Forms.Panel();
            this.label3 = new System.Windows.Forms.Label();
            this.panel4 = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.CikisBtn = new System.Windows.Forms.Button();
            this.YeniOyunBtn = new System.Windows.Forms.Button();
            this.panel3 = new System.Windows.Forms.Panel();
            this.label5 = new System.Windows.Forms.Label();
            this.panel8 = new System.Windows.Forms.Panel();
            this.OrganikAtikBosaltBtn = new System.Windows.Forms.Button();
            this.organikAtikBar = new System.Windows.Forms.ProgressBar();
            this.organikAtikListBox = new System.Windows.Forms.ListBox();
            this.OrganikAtikEkleBtn = new System.Windows.Forms.Button();
            this.panel9 = new System.Windows.Forms.Panel();
            this.KagitAtikBosaltBtn = new System.Windows.Forms.Button();
            this.kagitAtikBar = new System.Windows.Forms.ProgressBar();
            this.kagitAtikListBox = new System.Windows.Forms.ListBox();
            this.KagitAtikEkleBtn = new System.Windows.Forms.Button();
            this.panel10 = new System.Windows.Forms.Panel();
            this.CamAtikBosaltBtn = new System.Windows.Forms.Button();
            this.camAtikBar = new System.Windows.Forms.ProgressBar();
            this.camAtikListBox = new System.Windows.Forms.ListBox();
            this.CamAtikEkleBtn = new System.Windows.Forms.Button();
            this.panel11 = new System.Windows.Forms.Panel();
            this.MetalAtikBosaltBtn = new System.Windows.Forms.Button();
            this.metalAtikBar = new System.Windows.Forms.ProgressBar();
            this.metalAtikListBox = new System.Windows.Forms.ListBox();
            this.MetalAtikEkleBtn = new System.Windows.Forms.Button();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.atikPictureBox)).BeginInit();
            this.panel2.SuspendLayout();
            this.puanPanel.SuspendLayout();
            this.timerPanel.SuspendLayout();
            this.panel6.SuspendLayout();
            this.panel4.SuspendLayout();
            this.panel3.SuspendLayout();
            this.panel8.SuspendLayout();
            this.panel9.SuspendLayout();
            this.panel10.SuspendLayout();
            this.panel11.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.Linen;
            this.panel1.Controls.Add(this.atikPictureBox);
            this.panel1.Location = new System.Drawing.Point(12, 12);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(253, 235);
            this.panel1.TabIndex = 0;
            // 
            // atikPictureBox
            // 
            this.atikPictureBox.BackColor = System.Drawing.Color.Silver;
            this.atikPictureBox.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.atikPictureBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.atikPictureBox.Location = new System.Drawing.Point(18, 15);
            this.atikPictureBox.Name = "atikPictureBox";
            this.atikPictureBox.Size = new System.Drawing.Size(216, 203);
            this.atikPictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.atikPictureBox.TabIndex = 0;
            this.atikPictureBox.TabStop = false;
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.Color.Linen;
            this.panel2.Controls.Add(this.puanPanel);
            this.panel2.Controls.Add(this.timerPanel);
            this.panel2.Controls.Add(this.panel6);
            this.panel2.Controls.Add(this.panel4);
            this.panel2.Controls.Add(this.CikisBtn);
            this.panel2.Controls.Add(this.YeniOyunBtn);
            this.panel2.Location = new System.Drawing.Point(12, 265);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(253, 432);
            this.panel2.TabIndex = 1;
            // 
            // puanPanel
            // 
            this.puanPanel.BackColor = System.Drawing.Color.MintCream;
            this.puanPanel.Controls.Add(this.puanLabel);
            this.puanPanel.Location = new System.Drawing.Point(18, 268);
            this.puanPanel.Name = "puanPanel";
            this.puanPanel.Size = new System.Drawing.Size(216, 63);
            this.puanPanel.TabIndex = 2;
            // 
            // puanLabel
            // 
            this.puanLabel.AutoSize = true;
            this.puanLabel.Font = new System.Drawing.Font("Tahoma", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.puanLabel.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.puanLabel.Location = new System.Drawing.Point(97, 10);
            this.puanLabel.Name = "puanLabel";
            this.puanLabel.Size = new System.Drawing.Size(31, 35);
            this.puanLabel.TabIndex = 0;
            this.puanLabel.Text = "0";
            // 
            // timerPanel
            // 
            this.timerPanel.BackColor = System.Drawing.Color.MintCream;
            this.timerPanel.Controls.Add(this.sureLabel);
            this.timerPanel.Location = new System.Drawing.Point(18, 156);
            this.timerPanel.Name = "timerPanel";
            this.timerPanel.Size = new System.Drawing.Size(216, 63);
            this.timerPanel.TabIndex = 2;
            // 
            // sureLabel
            // 
            this.sureLabel.AutoSize = true;
            this.sureLabel.Font = new System.Drawing.Font("Tahoma", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.sureLabel.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.sureLabel.Location = new System.Drawing.Point(88, 9);
            this.sureLabel.Name = "sureLabel";
            this.sureLabel.Size = new System.Drawing.Size(47, 35);
            this.sureLabel.TabIndex = 0;
            this.sureLabel.Text = "60";
            // 
            // panel6
            // 
            this.panel6.BackColor = System.Drawing.Color.Teal;
            this.panel6.Controls.Add(this.label3);
            this.panel6.Location = new System.Drawing.Point(18, 235);
            this.panel6.Name = "panel6";
            this.panel6.Size = new System.Drawing.Size(216, 36);
            this.panel6.TabIndex = 1;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Tahoma", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label3.ForeColor = System.Drawing.Color.White;
            this.label3.Location = new System.Drawing.Point(80, 5);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(65, 25);
            this.label3.TabIndex = 0;
            this.label3.Text = "PUAN";
            // 
            // panel4
            // 
            this.panel4.BackColor = System.Drawing.Color.Teal;
            this.panel4.Controls.Add(this.label1);
            this.panel4.Location = new System.Drawing.Point(18, 123);
            this.panel4.Name = "panel4";
            this.panel4.Size = new System.Drawing.Size(216, 39);
            this.panel4.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Tahoma", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label1.ForeColor = System.Drawing.Color.White;
            this.label1.Location = new System.Drawing.Point(80, 5);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(63, 25);
            this.label1.TabIndex = 0;
            this.label1.Text = "SÜRE";
            // 
            // CikisBtn
            // 
            this.CikisBtn.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.CikisBtn.Font = new System.Drawing.Font("Tahoma", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.CikisBtn.ForeColor = System.Drawing.Color.White;
            this.CikisBtn.Location = new System.Drawing.Point(18, 358);
            this.CikisBtn.Name = "CikisBtn";
            this.CikisBtn.Size = new System.Drawing.Size(216, 51);
            this.CikisBtn.TabIndex = 0;
            this.CikisBtn.Text = "ÇIKIŞ";
            this.CikisBtn.UseVisualStyleBackColor = false;
            this.CikisBtn.Click += new System.EventHandler(this.CikisBtn_Click);
            // 
            // YeniOyunBtn
            // 
            this.YeniOyunBtn.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.YeniOyunBtn.Font = new System.Drawing.Font("Tahoma", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.YeniOyunBtn.ForeColor = System.Drawing.Color.White;
            this.YeniOyunBtn.Location = new System.Drawing.Point(18, 18);
            this.YeniOyunBtn.Name = "YeniOyunBtn";
            this.YeniOyunBtn.Size = new System.Drawing.Size(216, 79);
            this.YeniOyunBtn.TabIndex = 0;
            this.YeniOyunBtn.Text = "YENİ OYUN";
            this.YeniOyunBtn.UseVisualStyleBackColor = false;
            this.YeniOyunBtn.Click += new System.EventHandler(this.YeniOyunBtn_Click);
            // 
            // panel3
            // 
            this.panel3.BackColor = System.Drawing.Color.Linen;
            this.panel3.Controls.Add(this.label5);
            this.panel3.Location = new System.Drawing.Point(281, 12);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(322, 37);
            this.panel3.TabIndex = 2;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Tahoma", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label5.Location = new System.Drawing.Point(71, 3);
            this.label5.Name = "label5";
            this.label5.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.label5.Size = new System.Drawing.Size(182, 29);
            this.label5.TabIndex = 0;
            this.label5.Text = "ATIK KUTULARI";
            // 
            // panel8
            // 
            this.panel8.BackColor = System.Drawing.Color.Teal;
            this.panel8.Controls.Add(this.OrganikAtikBosaltBtn);
            this.panel8.Controls.Add(this.organikAtikBar);
            this.panel8.Controls.Add(this.organikAtikListBox);
            this.panel8.Controls.Add(this.OrganikAtikEkleBtn);
            this.panel8.Location = new System.Drawing.Point(281, 69);
            this.panel8.Name = "panel8";
            this.panel8.Size = new System.Drawing.Size(148, 309);
            this.panel8.TabIndex = 3;
            // 
            // OrganikAtikBosaltBtn
            // 
            this.OrganikAtikBosaltBtn.Font = new System.Drawing.Font("Arial Narrow", 9.75F);
            this.OrganikAtikBosaltBtn.Location = new System.Drawing.Point(16, 270);
            this.OrganikAtikBosaltBtn.Name = "OrganikAtikBosaltBtn";
            this.OrganikAtikBosaltBtn.Size = new System.Drawing.Size(114, 29);
            this.OrganikAtikBosaltBtn.TabIndex = 3;
            this.OrganikAtikBosaltBtn.Text = "BOŞALT";
            this.OrganikAtikBosaltBtn.UseVisualStyleBackColor = true;
            this.OrganikAtikBosaltBtn.Click += new System.EventHandler(this.OrganikAtikBosaltBtn_Click);
            // 
            // organikAtikBar
            // 
            this.organikAtikBar.Location = new System.Drawing.Point(16, 239);
            this.organikAtikBar.Name = "organikAtikBar";
            this.organikAtikBar.Size = new System.Drawing.Size(114, 23);
            this.organikAtikBar.TabIndex = 2;
            // 
            // organikAtikListBox
            // 
            this.organikAtikListBox.BackColor = System.Drawing.Color.Linen;
            this.organikAtikListBox.FormattingEnabled = true;
            this.organikAtikListBox.Location = new System.Drawing.Point(16, 47);
            this.organikAtikListBox.Name = "organikAtikListBox";
            this.organikAtikListBox.Size = new System.Drawing.Size(114, 186);
            this.organikAtikListBox.TabIndex = 1;
            // 
            // OrganikAtikEkleBtn
            // 
            this.OrganikAtikEkleBtn.Font = new System.Drawing.Font("Arial Narrow", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.OrganikAtikEkleBtn.Location = new System.Drawing.Point(16, 16);
            this.OrganikAtikEkleBtn.Name = "OrganikAtikEkleBtn";
            this.OrganikAtikEkleBtn.Size = new System.Drawing.Size(114, 27);
            this.OrganikAtikEkleBtn.TabIndex = 0;
            this.OrganikAtikEkleBtn.Text = "ORGANİK ATIK";
            this.OrganikAtikEkleBtn.UseVisualStyleBackColor = true;
            this.OrganikAtikEkleBtn.Click += new System.EventHandler(this.OrganikAtikEkleBtn_Click);
            // 
            // panel9
            // 
            this.panel9.BackColor = System.Drawing.Color.Teal;
            this.panel9.Controls.Add(this.KagitAtikBosaltBtn);
            this.panel9.Controls.Add(this.kagitAtikBar);
            this.panel9.Controls.Add(this.kagitAtikListBox);
            this.panel9.Controls.Add(this.KagitAtikEkleBtn);
            this.panel9.Location = new System.Drawing.Point(455, 69);
            this.panel9.Name = "panel9";
            this.panel9.Size = new System.Drawing.Size(148, 309);
            this.panel9.TabIndex = 3;
            // 
            // KagitAtikBosaltBtn
            // 
            this.KagitAtikBosaltBtn.Font = new System.Drawing.Font("Arial Narrow", 9.75F);
            this.KagitAtikBosaltBtn.Location = new System.Drawing.Point(16, 270);
            this.KagitAtikBosaltBtn.Name = "KagitAtikBosaltBtn";
            this.KagitAtikBosaltBtn.Size = new System.Drawing.Size(114, 29);
            this.KagitAtikBosaltBtn.TabIndex = 3;
            this.KagitAtikBosaltBtn.Text = "BOŞALT";
            this.KagitAtikBosaltBtn.UseVisualStyleBackColor = true;
            this.KagitAtikBosaltBtn.Click += new System.EventHandler(this.KagitAtikBosaltBtn_Click);
            // 
            // kagitAtikBar
            // 
            this.kagitAtikBar.Location = new System.Drawing.Point(16, 239);
            this.kagitAtikBar.Name = "kagitAtikBar";
            this.kagitAtikBar.Size = new System.Drawing.Size(114, 23);
            this.kagitAtikBar.TabIndex = 2;
            // 
            // kagitAtikListBox
            // 
            this.kagitAtikListBox.BackColor = System.Drawing.Color.Linen;
            this.kagitAtikListBox.FormattingEnabled = true;
            this.kagitAtikListBox.Location = new System.Drawing.Point(16, 47);
            this.kagitAtikListBox.Name = "kagitAtikListBox";
            this.kagitAtikListBox.Size = new System.Drawing.Size(114, 186);
            this.kagitAtikListBox.TabIndex = 1;
            // 
            // KagitAtikEkleBtn
            // 
            this.KagitAtikEkleBtn.Font = new System.Drawing.Font("Arial Narrow", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.KagitAtikEkleBtn.Location = new System.Drawing.Point(16, 16);
            this.KagitAtikEkleBtn.Name = "KagitAtikEkleBtn";
            this.KagitAtikEkleBtn.Size = new System.Drawing.Size(114, 27);
            this.KagitAtikEkleBtn.TabIndex = 0;
            this.KagitAtikEkleBtn.Text = "KAĞIT";
            this.KagitAtikEkleBtn.UseVisualStyleBackColor = true;
            this.KagitAtikEkleBtn.Click += new System.EventHandler(this.KagitAtikEkleBtn_Click);
            // 
            // panel10
            // 
            this.panel10.BackColor = System.Drawing.Color.Teal;
            this.panel10.Controls.Add(this.CamAtikBosaltBtn);
            this.panel10.Controls.Add(this.camAtikBar);
            this.panel10.Controls.Add(this.camAtikListBox);
            this.panel10.Controls.Add(this.CamAtikEkleBtn);
            this.panel10.Location = new System.Drawing.Point(281, 388);
            this.panel10.Name = "panel10";
            this.panel10.Size = new System.Drawing.Size(148, 309);
            this.panel10.TabIndex = 3;
            // 
            // CamAtikBosaltBtn
            // 
            this.CamAtikBosaltBtn.Font = new System.Drawing.Font("Arial Narrow", 9.75F);
            this.CamAtikBosaltBtn.Location = new System.Drawing.Point(16, 270);
            this.CamAtikBosaltBtn.Name = "CamAtikBosaltBtn";
            this.CamAtikBosaltBtn.Size = new System.Drawing.Size(114, 29);
            this.CamAtikBosaltBtn.TabIndex = 3;
            this.CamAtikBosaltBtn.Text = "BOŞALT";
            this.CamAtikBosaltBtn.UseVisualStyleBackColor = true;
            this.CamAtikBosaltBtn.Click += new System.EventHandler(this.CamAtikBosaltBtn_Click);
            // 
            // camAtikBar
            // 
            this.camAtikBar.Location = new System.Drawing.Point(16, 239);
            this.camAtikBar.Name = "camAtikBar";
            this.camAtikBar.Size = new System.Drawing.Size(114, 23);
            this.camAtikBar.TabIndex = 2;
            // 
            // camAtikListBox
            // 
            this.camAtikListBox.BackColor = System.Drawing.Color.Linen;
            this.camAtikListBox.FormattingEnabled = true;
            this.camAtikListBox.Location = new System.Drawing.Point(16, 47);
            this.camAtikListBox.Name = "camAtikListBox";
            this.camAtikListBox.Size = new System.Drawing.Size(114, 186);
            this.camAtikListBox.TabIndex = 1;
            // 
            // CamAtikEkleBtn
            // 
            this.CamAtikEkleBtn.Font = new System.Drawing.Font("Arial Narrow", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.CamAtikEkleBtn.Location = new System.Drawing.Point(16, 16);
            this.CamAtikEkleBtn.Name = "CamAtikEkleBtn";
            this.CamAtikEkleBtn.Size = new System.Drawing.Size(114, 27);
            this.CamAtikEkleBtn.TabIndex = 0;
            this.CamAtikEkleBtn.Text = "CAM";
            this.CamAtikEkleBtn.UseVisualStyleBackColor = true;
            this.CamAtikEkleBtn.Click += new System.EventHandler(this.CamAtikEkleBtn_Click);
            // 
            // panel11
            // 
            this.panel11.BackColor = System.Drawing.Color.Teal;
            this.panel11.Controls.Add(this.MetalAtikBosaltBtn);
            this.panel11.Controls.Add(this.metalAtikBar);
            this.panel11.Controls.Add(this.metalAtikListBox);
            this.panel11.Controls.Add(this.MetalAtikEkleBtn);
            this.panel11.Location = new System.Drawing.Point(455, 388);
            this.panel11.Name = "panel11";
            this.panel11.Size = new System.Drawing.Size(148, 309);
            this.panel11.TabIndex = 3;
            // 
            // MetalAtikBosaltBtn
            // 
            this.MetalAtikBosaltBtn.Font = new System.Drawing.Font("Arial Narrow", 9.75F);
            this.MetalAtikBosaltBtn.Location = new System.Drawing.Point(16, 270);
            this.MetalAtikBosaltBtn.Name = "MetalAtikBosaltBtn";
            this.MetalAtikBosaltBtn.Size = new System.Drawing.Size(114, 29);
            this.MetalAtikBosaltBtn.TabIndex = 3;
            this.MetalAtikBosaltBtn.Text = "BOŞALT";
            this.MetalAtikBosaltBtn.UseVisualStyleBackColor = true;
            this.MetalAtikBosaltBtn.Click += new System.EventHandler(this.MetalAtikBosaltBtn_Click);
            // 
            // metalAtikBar
            // 
            this.metalAtikBar.Location = new System.Drawing.Point(16, 239);
            this.metalAtikBar.Name = "metalAtikBar";
            this.metalAtikBar.Size = new System.Drawing.Size(114, 23);
            this.metalAtikBar.TabIndex = 2;
            // 
            // metalAtikListBox
            // 
            this.metalAtikListBox.BackColor = System.Drawing.Color.Linen;
            this.metalAtikListBox.FormattingEnabled = true;
            this.metalAtikListBox.Location = new System.Drawing.Point(16, 47);
            this.metalAtikListBox.Name = "metalAtikListBox";
            this.metalAtikListBox.Size = new System.Drawing.Size(114, 186);
            this.metalAtikListBox.TabIndex = 1;
            // 
            // MetalAtikEkleBtn
            // 
            this.MetalAtikEkleBtn.Font = new System.Drawing.Font("Arial Narrow", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.MetalAtikEkleBtn.Location = new System.Drawing.Point(16, 16);
            this.MetalAtikEkleBtn.Name = "MetalAtikEkleBtn";
            this.MetalAtikEkleBtn.Size = new System.Drawing.Size(114, 27);
            this.MetalAtikEkleBtn.TabIndex = 0;
            this.MetalAtikEkleBtn.Text = "METAL";
            this.MetalAtikEkleBtn.UseVisualStyleBackColor = true;
            this.MetalAtikEkleBtn.Click += new System.EventHandler(this.MetalAtikEkleBtn_Click);
            // 
            // timer1
            // 
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.Timer1_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.ClientSize = new System.Drawing.Size(615, 707);
            this.Controls.Add(this.panel10);
            this.Controls.Add(this.panel11);
            this.Controls.Add(this.panel9);
            this.Controls.Add(this.panel8);
            this.Controls.Add(this.panel3);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "ATIK TOPLAMA";
            this.panel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.atikPictureBox)).EndInit();
            this.panel2.ResumeLayout(false);
            this.puanPanel.ResumeLayout(false);
            this.puanPanel.PerformLayout();
            this.timerPanel.ResumeLayout(false);
            this.timerPanel.PerformLayout();
            this.panel6.ResumeLayout(false);
            this.panel6.PerformLayout();
            this.panel4.ResumeLayout(false);
            this.panel4.PerformLayout();
            this.panel3.ResumeLayout(false);
            this.panel3.PerformLayout();
            this.panel8.ResumeLayout(false);
            this.panel9.ResumeLayout(false);
            this.panel10.ResumeLayout(false);
            this.panel11.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.PictureBox atikPictureBox;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.Panel timerPanel;
        private System.Windows.Forms.Label sureLabel;
        private System.Windows.Forms.Panel panel4;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button YeniOyunBtn;
        private System.Windows.Forms.Panel puanPanel;
        private System.Windows.Forms.Panel panel6;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button CikisBtn;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Panel panel8;
        private System.Windows.Forms.Button OrganikAtikBosaltBtn;
        private System.Windows.Forms.ProgressBar organikAtikBar;
        private System.Windows.Forms.ListBox organikAtikListBox;
        private System.Windows.Forms.Button OrganikAtikEkleBtn;
        private System.Windows.Forms.Panel panel9;
        private System.Windows.Forms.Button KagitAtikBosaltBtn;
        private System.Windows.Forms.ProgressBar kagitAtikBar;
        private System.Windows.Forms.ListBox kagitAtikListBox;
        private System.Windows.Forms.Button KagitAtikEkleBtn;
        private System.Windows.Forms.Panel panel10;
        private System.Windows.Forms.Button CamAtikBosaltBtn;
        private System.Windows.Forms.ProgressBar camAtikBar;
        private System.Windows.Forms.ListBox camAtikListBox;
        private System.Windows.Forms.Button CamAtikEkleBtn;
        private System.Windows.Forms.Panel panel11;
        private System.Windows.Forms.Button MetalAtikBosaltBtn;
        private System.Windows.Forms.ProgressBar metalAtikBar;
        private System.Windows.Forms.ListBox metalAtikListBox;
        private System.Windows.Forms.Button MetalAtikEkleBtn;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Label puanLabel;
    }
}

