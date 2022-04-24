namespace DrawingShape
{
    partial class Shape
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
            this.DrawingShapePanel = new System.Windows.Forms.Panel();
            this.ExitButton = new System.Windows.Forms.Button();
            this.DrawingShapePanel.SuspendLayout();
            this.SuspendLayout();
            // 
            // DrawingShapePanel
            // 
            this.DrawingShapePanel.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.DrawingShapePanel.Controls.Add(this.ExitButton);
            this.DrawingShapePanel.Location = new System.Drawing.Point(-1, 0);
            this.DrawingShapePanel.Name = "DrawingShapePanel";
            this.DrawingShapePanel.Size = new System.Drawing.Size(465, 385);
            this.DrawingShapePanel.TabIndex = 0;
            this.DrawingShapePanel.Paint += new System.Windows.Forms.PaintEventHandler(this.DrawingShapePanelPaint);
            // 
            // ExitButton
            // 
            this.ExitButton.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.ExitButton.Location = new System.Drawing.Point(369, 343);
            this.ExitButton.Name = "ExitButton";
            this.ExitButton.Size = new System.Drawing.Size(82, 29);
            this.ExitButton.TabIndex = 0;
            this.ExitButton.Text = "Exit";
            this.ExitButton.UseVisualStyleBackColor = true;
            this.ExitButton.Click += new System.EventHandler(this.ExitButtonClick);
            // 
            // Shape
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(462, 384);
            this.Controls.Add(this.DrawingShapePanel);
            this.Name = "Shape";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Shape";
            this.DrawingShapePanel.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private Panel DrawingShapePanel;
        private Button ExitButton;
    }
}