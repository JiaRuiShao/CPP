using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Game2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Up)
            {
                picHero.Top -= 25;
            }
            else if (e.KeyCode ==Keys.Down)
            {
                picHero.Top += 25;
            }
            if (picHero.Top <0)
            {
                picHero.Top = 0;
            }
            else if (picHero.Top + picHero.Height > this.Height)
            {
                picHero.Top = this.Height - picHero.Height;
            }
        }

        private Random r = new Random();
        private int Score = 0;
        private void timer1_Tick(object sender, EventArgs e)
        {
            PictureBox[] enemies = new PictureBox[] { picEnemy1, picEnemy2, picEnemy3 };

            for (int i = 0; i < 3; i++)
            {
                //change the location of the enemies
                enemies[i].Left -= 15 + (i*10);
                if (enemies[i].Left < 0)
                {
                    Score += 10;
                    MyScore.Text = "Score: " + Score.ToString();
                    enemies[i].Left = this.Width;
                    enemies[i].Top = (int)(r.NextDouble() * (this.Height - picEnemy1.Height));
                }

                if (enemies[i].Left < picHero.Right)
                {
                    if ((enemies[i].Top >= picHero.Top && enemies[i].Top <= picHero.Bottom) || (enemies[i].Bottom >= picHero.Top && enemies[i].Bottom <= picHero.Bottom))
                    {
                        //hit and lose the game
                        
                        Score -= 50;
                        if (Score < 0)
                        {
                            MessageBox.Show("Game Over!");
                            timer1.Enabled = false; // to stop the game: 
                        }
                    }

                }
            }

            if (Score >= 210)
            {
                timer1.Enabled = false;
                MessageBox.Show("You win!"); //+ Score.ToString())
            }
        }


    }
}
