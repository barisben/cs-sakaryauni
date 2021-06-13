namespace Odev2
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
            this.arkadasMiBtn = new System.Windows.Forms.Button();
            this.sonBtn = new System.Windows.Forms.Button();
            this.xLabel = new System.Windows.Forms.Label();
            this.yLabel = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // arkadasMiBtn
            // 
            this.arkadasMiBtn.Location = new System.Drawing.Point(21, 116);
            this.arkadasMiBtn.Name = "arkadasMiBtn";
            this.arkadasMiBtn.Size = new System.Drawing.Size(101, 23);
            this.arkadasMiBtn.TabIndex = 0;
            this.arkadasMiBtn.Text = "ARKADAS MI?";
            this.arkadasMiBtn.UseVisualStyleBackColor = true;
            this.arkadasMiBtn.Click += new System.EventHandler(this.arkadasMiBtn_Click);
            // 
            // sonBtn
            // 
            this.sonBtn.Location = new System.Drawing.Point(154, 116);
            this.sonBtn.Name = "sonBtn";
            this.sonBtn.Size = new System.Drawing.Size(75, 23);
            this.sonBtn.TabIndex = 1;
            this.sonBtn.Text = "SON";
            this.sonBtn.UseVisualStyleBackColor = true;
            this.sonBtn.Click += new System.EventHandler(this.sonBtn_Click);
            // 
            // xLabel
            // 
            this.xLabel.AutoSize = true;
            this.xLabel.Location = new System.Drawing.Point(36, 24);
            this.xLabel.Name = "xLabel";
            this.xLabel.Size = new System.Drawing.Size(14, 13);
            this.xLabel.TabIndex = 2;
            this.xLabel.Text = "X";
            // 
            // yLabel
            // 
            this.yLabel.AutoSize = true;
            this.yLabel.Location = new System.Drawing.Point(36, 60);
            this.yLabel.Name = "yLabel";
            this.yLabel.Size = new System.Drawing.Size(14, 13);
            this.yLabel.TabIndex = 3;
            this.yLabel.Text = "Y";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(83, 21);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 20);
            this.textBox1.TabIndex = 4;
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(83, 57);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(100, 20);
            this.textBox2.TabIndex = 5;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(269, 162);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.yLabel);
            this.Controls.Add(this.xLabel);
            this.Controls.Add(this.sonBtn);
            this.Controls.Add(this.arkadasMiBtn);
            this.Name = "Form1";
            this.Text = "ARKADAŞ SAYILAR";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button arkadasMiBtn;
        private System.Windows.Forms.Button sonBtn;
        private System.Windows.Forms.Label xLabel;
        private System.Windows.Forms.Label yLabel;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox2;
    }
}

