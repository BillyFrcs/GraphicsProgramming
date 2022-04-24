using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BasicDrawing
{
    public partial class Lines : Form
    {
        public Lines()
        {
            InitializeComponent();
        }

        private void PanelLinesPaint(object sender, PaintEventArgs eventPaint)
        {
            Graphics graphics = eventPaint.Graphics;

            Point point = new Point(500 / 5, 400 / 5);

            Point newPoint = Point.Empty;

            newPoint.X = 100;
            newPoint.Y = 300;

            Pen pen = new Pen(Color.DeepPink, 5);

            graphics.DrawLine(pen, point, newPoint);

            graphics.DrawLine(new Pen(Color.YellowGreen, 5), new Point(200, 200), new Point(200, 350));

            graphics.DrawLine(new Pen(Color.Tomato, 5), new Point(300, 300), new Point(300, 600));

            // Clean up
            graphics.Dispose();
            pen.Dispose();
        }
    }
}
