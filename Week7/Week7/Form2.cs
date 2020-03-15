using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Week6;

namespace Week7
{
    public partial class Form2 : Form
    {
        public static Form2 form2;
        public uint i;
        public string str1;
        public string str2;
        

        public Form2()
        {
            InitializeComponent();
            form2 = this;
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            
        }

        private void label1_Click(object sender, EventArgs e)
        {
            
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void label3_Click(object sender, EventArgs e)
        {
           
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string innerStr1 = textBox1.Text;
            i = Convert.ToUInt32(innerStr1);
            str1 = textBox2.Text;
            str2 = textBox3.Text;

            Customer customer1 = new Customer(1,"Customer1");
            textBox1.DataBindings.Add("Text", customer1,"Number");
            
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
