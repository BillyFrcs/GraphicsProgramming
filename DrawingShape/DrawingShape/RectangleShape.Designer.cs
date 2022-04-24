namespace DrawingShape
{
    partial class RectangleShape
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
            this.RectanglePanel = new System.Windows.Forms.Panel();
            this.ExitButton = new System.Windows.Forms.Button();
            this.RectanglePanel.SuspendLayout();
            this.SuspendLayout();
            // 
            // RectanglePanel
            // 
            this.RectanglePanel.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.RectanglePanel.Controls.Add(this.ExitButton);
            this.RectanglePanel.Location = new System.Drawing.Point(12, 12);
            this.RectanglePanel.Name = "RectanglePanel";
            this.RectanglePanel.Size = new System.Drawing.Size(441, 361);
            this.RectanglePanel.TabIndex = 0;
            this.RectanglePanel.Paint += new System.Windows.Forms.PaintEventHandler(this.RectanglePanelPaint);
            // 
            // ExitButton
            // 
            this.ExitButton.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.ExitButton.Location = new System.Drawing.Point(349, 324);
            this.ExitButton.Name = "ExitButton";
            this.ExitButton.Size = new System.Drawing.Size(89, 34);
            this.ExitButton.TabIndex = 0;
            this.ExitButton.Text = "Exit";
            this.ExitButton.UseVisualStyleBackColor = true;
            this.ExitButton.Click += new System.EventHandler(this.ExitButtonClick);
            // 
            // RectangleShape
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(465, 385);
            this.Controls.Add(this.RectanglePanel);
            this.Name = "RectangleShape";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Rectangle";
            this.RectanglePanel.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private Panel RectanglePanel;
        private Button ExitButton;
    }
}