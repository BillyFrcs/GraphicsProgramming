using System.Reflection;

namespace BasicDrawing
{
    public partial class Drawing : Form
    {
        private Graphics _graphics;
        private readonly Brush _Brush = PickRandomBrush();

        private int X { get; set; }
        private int Y { get; set; }

        private int Width { get; set; }
        private int Height { get; set; }

        public Drawing()
        {
            InitializeComponent();
        }

        private void DrawingLoad(object sender, EventArgs e)
        {
            _graphics = PanelDrawing.CreateGraphics();
        }

        private void DrawButtonClick(object sender, EventArgs e)
        {
            if ((XTextBox.Text != string.Empty && YTextBox.Text != string.Empty) && (WidthTextBox.Text != string.Empty && HeightTextBox.Text != string.Empty))
            {
                X = int.Parse(XTextBox.Text);
                Y = Convert.ToInt32(YTextBox.Text);

                Width = int.Parse(WidthTextBox.Text);
                Height = Convert.ToInt32(HeightTextBox.Text);
            }
            else
            {
                MessageBox.Show("Please input the form!", "Warning", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }

            Draw();
        }

        /// <summary>
        /// Draw rectangles
        /// </summary>
        private void Draw()
        {
            _graphics.FillRectangle(_Brush, X, Y, Width, Height);
        }

        private void ClearButtonClick(object sender, EventArgs e)
        {
            XTextBox.Text = null;
            YTextBox.Text = null;
            WidthTextBox.Text = null;
            HeightTextBox.Text = null;

            PanelDrawing.Refresh();
        }

        private void ExitButtonClick(object sender, EventArgs e)
        {
            DialogResult exitApp = MessageBox.Show("Are you sure want to exit?", "Message", MessageBoxButtons.YesNo, MessageBoxIcon.Question);

            switch (exitApp)
            {
                case DialogResult.Yes:
                    Application.Exit();
                    break;

                default:
                    break;
            }
        }

        /// <summary>
        /// Generate random color of Brushes
        /// </summary>
        /// <returns>Random brush color</returns>
        private static Brush PickRandomBrush()
        {
           var result = Brushes.Transparent;

           Type brushesType = typeof(Brushes);

           PropertyInfo[] properties = brushesType.GetProperties();

           if (result != null)
           {
               result = (Brush)properties[new Random().Next(properties.Length)].GetValue(null, null);
           }

           return result;
        }
    }
}