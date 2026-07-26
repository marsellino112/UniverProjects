using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace calc
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                var calculator = new PolishCalculator();

                // Получаем выражение из textBox1
                string expression = textBox1.Text;

                // Вычисляем, поддерживаем инфикс (со скобками)
                double result = calculator.EvaluateInfix(expression);

                // Выводим результат в textBox2
                textBox2.Text = result.ToString();
            }
            catch (Exception ex)
            {
                // Если ошибка — показываем сообщение об ошибке в textBox2
                textBox2.Text = $"Ошибка: {ex.Message}";
            }
        }
    }
}
