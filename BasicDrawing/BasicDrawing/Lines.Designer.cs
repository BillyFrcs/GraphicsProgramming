namespace BasicDrawing
{
    partial class Lines
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
            this.PanelLines = new System.Windows.Forms.Panel();
            this.SuspendLayout();
            // 
            // PanelLines
            // 
            this.PanelLines.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.PanelLines.Location = new System.Drawing.Point(12, 12);
            this.PanelLines.Name = "PanelLines";
            this.PanelLines.Size = new System.Drawing.Size(476, 385);
            this.PanelLines.TabIndex = 0;
            this.PanelLines.Paint += new System.Windows.Forms.PaintEventHandler(this.PanelLinesPaint);
            // 
            // Lines
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(500, 400);
            this.Controls.Add(this.PanelLines);
            this.Name = "Lines";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Lines";
            this.ResumeLayout(false);

        }

        #endregion

        private Panel PanelLines;
    }
}