namespace Game2
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.picHero = new System.Windows.Forms.PictureBox();
            this.picEnemy1 = new System.Windows.Forms.PictureBox();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.picEnemy2 = new System.Windows.Forms.PictureBox();
            this.picEnemy3 = new System.Windows.Forms.PictureBox();
            this.MyScore = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.picHero)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picEnemy1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picEnemy2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picEnemy3)).BeginInit();
            this.SuspendLayout();
            // 
            // picHero
            // 
            this.picHero.BackColor = System.Drawing.Color.Transparent;
            this.picHero.Image = global::Game2.Properties.Resources.halloween_avatar_25_512;
            this.picHero.Location = new System.Drawing.Point(299, 422);
            this.picHero.Name = "picHero";
            this.picHero.Size = new System.Drawing.Size(81, 86);
            this.picHero.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.picHero.TabIndex = 0;
            this.picHero.TabStop = false;
            // 
            // picEnemy1
            // 
            this.picEnemy1.BackColor = System.Drawing.Color.Transparent;
            this.picEnemy1.Image = global::Game2.Properties.Resources.Picture1;
            this.picEnemy1.Location = new System.Drawing.Point(660, 178);
            this.picEnemy1.Name = "picEnemy1";
            this.picEnemy1.Size = new System.Drawing.Size(154, 159);
            this.picEnemy1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.picEnemy1.TabIndex = 1;
            this.picEnemy1.TabStop = false;
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // picEnemy2
            // 
            this.picEnemy2.BackColor = System.Drawing.Color.Transparent;
            this.picEnemy2.Image = global::Game2.Properties.Resources.Picture1;
            this.picEnemy2.Location = new System.Drawing.Point(444, 513);
            this.picEnemy2.Name = "picEnemy2";
            this.picEnemy2.Size = new System.Drawing.Size(183, 198);
            this.picEnemy2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.picEnemy2.TabIndex = 2;
            this.picEnemy2.TabStop = false;
            // 
            // picEnemy3
            // 
            this.picEnemy3.BackColor = System.Drawing.Color.Transparent;
            this.picEnemy3.Image = global::Game2.Properties.Resources.Picture1;
            this.picEnemy3.Location = new System.Drawing.Point(1203, 362);
            this.picEnemy3.Name = "picEnemy3";
            this.picEnemy3.Size = new System.Drawing.Size(164, 177);
            this.picEnemy3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.picEnemy3.TabIndex = 3;
            this.picEnemy3.TabStop = false;
            // 
            // MyScore
            // 
            this.MyScore.AutoSize = true;
            this.MyScore.BackColor = System.Drawing.Color.Transparent;
            this.MyScore.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.MyScore.Location = new System.Drawing.Point(42, 24);
            this.MyScore.Name = "MyScore";
            this.MyScore.Size = new System.Drawing.Size(35, 13);
            this.MyScore.TabIndex = 4;
            this.MyScore.Text = "label1";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::Game2.Properties.Resources._37_affinity_game_background_600;
            this.ClientSize = new System.Drawing.Size(1463, 843);
            this.Controls.Add(this.MyScore);
            this.Controls.Add(this.picEnemy3);
            this.Controls.Add(this.picEnemy2);
            this.Controls.Add(this.picEnemy1);
            this.Controls.Add(this.picHero);
            this.DoubleBuffered = true;
            this.Name = "Form1";
            this.Text = "Form1";
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown);
            ((System.ComponentModel.ISupportInitialize)(this.picHero)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picEnemy1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picEnemy2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picEnemy3)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox picHero;
        private System.Windows.Forms.PictureBox picEnemy1;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.PictureBox picEnemy2;
        private System.Windows.Forms.PictureBox picEnemy3;
        private System.Windows.Forms.Label MyScore;
    }
}

