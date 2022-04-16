using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DrawingShape
{
    public partial class Shape : Form
    {
        private readonly float _x;
        private readonly float _y;
        private readonly float _width;
        private readonly float _height;

        public Shape()
        {
            // Initialize
            _x = 20f;
            _y = 20f;
            _width = 100f;
            _height = 100f;

            InitializeComponent();
        }

        private void DrawingShapePanelPaint(object sender, PaintEventArgs paintEvent)
        {
            Graphics graphics = paintEvent.Graphics;

            graphics.SmoothingMode = SmoothingMode.AntiAlias;

            Rectangle rectangle = new Rectangle((int)_x, (int)_y, (int)_width, (int)_height);

            const int penWidth = 1;

            Pen colorPen = new Pen(Color.Orange, penWidth);
            Pen line = new Pen(Color.Black, penWidth);

            SolidBrush solidColorBrush = new SolidBrush(Color.DarkMagenta);

            graphics.DrawRectangle(colorPen, rectangle);
            graphics.FillEllipse(solidColorBrush, rectangle);
            graphics.DrawLine(line, 0, 250, this.Width, 250);

            DrawCircle(graphics);
        }

        /// <summary>
        /// Draw simple circle with color
        /// </summary>
        /// <param name="graphics">Graphics</param>
        private void DrawCircle(Graphics graphics)
        {
            graphics.FillEllipse(Brushes.Blue, 70, 220, 30, 30);
            graphics.FillEllipse(Brushes.SkyBlue, 100, 210, 40, 40);
            graphics.FillEllipse(Brushes.PaleGreen, 140, 200, 50, 50);
            graphics.FillEllipse(Brushes.Yellow, 190, 190, 60, 60);
            graphics.FillEllipse(Brushes.Violet, 250, 180, 70, 70);
            graphics.FillEllipse(Brushes.Brown, 320, 170, 80, 80);
        }

        private void ExitButtonClick(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}