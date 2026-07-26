using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace calc
{
    public class PolishCalculator
    {
        /// <summary>
        /// Вычислить выражение в обратной польской нотации (ОПН).
        /// </summary>
        public double Evaluate(string expression)
        {
            if (string.IsNullOrWhiteSpace(expression))
                throw new ArgumentException("Выражение не должно быть пустым");

            var stack = new Stack<double>();
            string[] tokens = expression.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

            foreach (var token in tokens)
            {
                if (double.TryParse(token, NumberStyles.Any, CultureInfo.InvariantCulture, out double number))
                {
                    stack.Push(number);
                }
                else
                {
                    if (stack.Count < 2)
                        throw new InvalidOperationException("Недостаточно операндов для операции");

                    double b = stack.Pop();
                    double a = stack.Pop();

                    switch (token)
                    {
                        case "+": stack.Push(a + b); break;
                        case "-": stack.Push(a - b); break;
                        case "*": stack.Push(a * b); break;
                        case "/":
                            if (b == 0)
                                throw new DivideByZeroException("Деление на ноль");
                            stack.Push(a / b);
                            break;
                        default:
                            throw new InvalidOperationException($"Неизвестный оператор '{token}'");
                    }
                }
            }

            if (stack.Count != 1)
                throw new InvalidOperationException("Некорректное выражение");

            return stack.Pop();
        }

        /// <summary>
        /// Вычислить инфиксное выражение с поддержкой скобок.
        /// </summary>
        public double EvaluateInfix(string expression)
        {
            string rpn = InfixToRPN(expression);
            return Evaluate(rpn);
        }

        /// <summary>
        /// Преобразование инфиксного выражения в обратную польскую нотацию (ОПН)
        /// Алгоритм сортировочной станции (Dijkstra)
        /// </summary>
        private string InfixToRPN(string infix)
        {
            if (string.IsNullOrWhiteSpace(infix))
                throw new ArgumentException("Выражение не должно быть пустым");

            var output = new List<string>();
            var operators = new Stack<char>();

            int pos = 0;

            while (pos < infix.Length)
            {
                char c = infix[pos];

                if (char.IsWhiteSpace(c))
                {
                    pos++;
                    continue;
                }

                // Число — может включать цифры, точку
                if (char.IsDigit(c) || c == '.')
                {
                    int start = pos;
                    while (pos < infix.Length && (char.IsDigit(infix[pos]) || infix[pos] == '.'))
                        pos++;
                    string number = infix.Substring(start, pos - start);
                    output.Add(number);
                    continue;
                }

                // Открывающая скобка
                if (c == '(')
                {
                    operators.Push(c);
                    pos++;
                    continue;
                }

                // Закрывающая скобка
                if (c == ')')
                {
                    bool foundLeftParenthesis = false;
                    while (operators.Count > 0)
                    {
                        char op = operators.Pop();
                        if (op == '(')
                        {
                            foundLeftParenthesis = true;
                            break;
                        }
                        output.Add(op.ToString());
                    }
                    if (!foundLeftParenthesis)
                        throw new InvalidOperationException("Несбалансированные скобки");
                    pos++;
                    continue;
                }

                // Операторы
                if (IsOperator(c))
                {
                    while (operators.Count > 0 && operators.Peek() != '(' &&
                           GetPrecedence(operators.Peek()) >= GetPrecedence(c))
                    {
                        output.Add(operators.Pop().ToString());
                    }
                    operators.Push(c);
                    pos++;
                    continue;
                }

                throw new InvalidOperationException($"Недопустимый символ '{c}' в выражении");
            }

            // Выталкиваем оставшиеся операторы
            while (operators.Count > 0)
            {
                char op = operators.Pop();
                if (op == '(' || op == ')')
                    throw new InvalidOperationException("Несбалансированные скобки");
                output.Add(op.ToString());
            }

            return string.Join(" ", output);
        }

        private bool IsOperator(char c)
        {
            return c == '+' || c == '-' || c == '*' || c == '/';
        }

        private int GetPrecedence(char op)
        {
            switch (op)
            {
                case '+':
                case '-':
                    return 1;
                case '*':
                case '/':
                    return 2;
                default:
                    throw new ArgumentException($"Неизвестный оператор '{op}'");
            }
        }
    }
}
