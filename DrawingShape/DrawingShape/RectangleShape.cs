using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DrawingShape
{
    public partial class RectangleShape : Form
    {
        private Graphics _Graphics;

        private Pen _PenColor = new(Color.Blue, 5f);

        public RectangleShape()
        {
            InitializeComponent();
        }

        ~RectangleShape()
        {
            this._PenColor.Dispose();
            this._Graphics.Dispose();
        }

        private void RectanglePanelPaint(object sender, PaintEventArgs e)
        {
            this._Graphics = e.Graphics;

            RectangleF[] rectangleF =
            {
                new RectangleF(90f, 30f, 250f, 250f),

                // new RectangleF(120f, 60f, 190f, 190f),
            };

            var brush1 = new SolidBrush(Color.Orange);
            var brush2 = new SolidBrush(Color.GreenYellow);

            this._Graphics.DrawRectangles(this._PenColor, rectangleF);

            const int x = 110;
            const int y = 50;

            // DrawEllipse(x, y, 120, h120, brush1, brush2);

            DrawRectangle(x, y, 130, 130, ref brush1, ref brush2);
        }

        /// <summary>
        /// Draw Circles
        /// </summary>
        /// <param name="x">X position</param>
        /// <param name="y">Y position</param>
        /// <param name="width">Width of circle</param>
        /// <param name="height">Height of circle</param>
        /// <param name="brush1">Solid color 1</param>
        /// <param name="brush2">Solid color 2</param>
        private void DrawEllipse(in int x, in int y, in int width, in int height, in SolidBrush brush1, in SolidBrush brush2)
        {
            Rectangle rectangle1 = new(x, y, width, height);
            Rectangle rectangle2 = new(190, 150, width, height);

            this._Graphics.FillEllipse(brush1, rectangle1);
            this._Graphics.FillEllipse(brush2, rectangle2);
        }

        /// <summary>
        /// Draw rectangle
        /// </summary>
        /// <param name="x">X position</param>
        /// <param name="y">Y position</param>
        /// <param name="width">Width of rectangle</param>
        /// <param name="height">Height of rectangle</param>
        /// <param name="brush1">Solid color 1</param>
        /// <param name="brush2">Solid color 2</param>
        private void DrawRectangle(in int x, in int y, in int width, in int height, ref SolidBrush brush1, ref SolidBrush brush2)
        {
            Rectangle[] rectangle1 =
            { 
                new(x, y, width, height)
            };

            Rectangle[] rectangle2 =
            {
                new(190, 140, width, height)
            };
            
            _Graphics.FillRectangles(brush1, rectangle1);
            _Graphics.FillRectangles(brush2, rectangle2);
        }

        private void ExitButtonClick(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}