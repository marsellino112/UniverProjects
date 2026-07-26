using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using calc;

namespace UnitTestProject1
{
    [TestClass]
    public class SimpleOperationsTests
    {
        private PolishCalculator calculator;

        [TestInitialize]
        public void Setup()
        {
            calculator = new PolishCalculator();
        }

        [TestMethod]
        public void GivenTwoNumbers_WhenAdding_ThenReturnsSum()
        {
            // Given
            string expression = "3 5 +";

            // When
            double result = calculator.Evaluate(expression);

            // Then
            Assert.AreEqual(8, result);
        }

        [TestMethod]
        public void GivenTwoNumbers_WhenSubtracting_ThenReturnsDifference()
        {
            string expression = "10 4 -";
            double result = calculator.Evaluate(expression);
            Assert.AreEqual(6, result);
        }

        [TestMethod]
        public void GivenTwoNumbers_WhenMultiplying_ThenReturnsProduct()
        {
            string expression = "7 6 *";
            double result = calculator.Evaluate(expression);
            Assert.AreEqual(42, result);
        }

        [TestMethod]
        public void GivenTwoNumbers_WhenDividing_ThenReturnsQuotient()
        {
            string expression = "20 5 /";
            double result = calculator.Evaluate(expression);
            Assert.AreEqual(4, result);
        }
        [TestMethod]
        public void GivenThreeNumbers_WhenAddingThenMultiplying_ThenReturnsCorrectResult()
        {
            // (3 + 5) * 2 = 16
            string expression = "3 5 + 2 *";

            double result = calculator.Evaluate(expression);

            Assert.AreEqual(16, result);
        }

        [TestMethod]
        public void GivenThreeNumbers_WhenMultiplyingThenAdding_ThenReturnsCorrectResult()
        {
            // 3 * 5 + 2 = 17
            string expression = "3 5 * 2 +";

            double result = calculator.Evaluate(expression);

            Assert.AreEqual(17, result);
        }

        [TestMethod]
        public void GivenThreeNumbers_WhenSubtractingThenDividing_ThenReturnsCorrectResult()
        {
            // (10 - 4) / 2 = 3
            string expression = "10 4 - 2 /";

            double result = calculator.Evaluate(expression);

            Assert.AreEqual(3, result);
        }

        [TestMethod]
        public void GivenThreeNumbers_WhenDividingThenSubtracting_ThenReturnsCorrectResult()
        {
            // 20 5 / 3 - => (20 / 5) - 3 = 1
            string expression = "20 5 / 3 -";

            double result = calculator.Evaluate(expression);

            Assert.AreEqual(1, result);
        }
        [TestMethod]
        public void GivenComplexExpressionWithParentheses_WhenEvaluated_ThenReturnsCorrectResult()
        {
            // (3 + 5) * (2 - 1) = 8 * 1 = 8
            string expression = "(3 + 5) * (2 - 1)";
            double result = calculator.EvaluateInfix(expression);
            Assert.AreEqual(8, result);
        }

        [TestMethod]
        public void GivenExpressionWithNestedParentheses_WhenEvaluated_ThenReturnsCorrectResult()
        {
            // ((2 + 3) * (7 - 4)) / (1 + 1) = (5 * 3) / 2 = 7.5
            string expression = "((2 + 3) * (7 - 4)) / (1 + 1)";
            double result = calculator.EvaluateInfix(expression);
            Assert.AreEqual(7.5, result);
        }

        [TestMethod]
        public void GivenExpressionWithoutParentheses_WhenEvaluated_ThenRespectsOperatorPrecedence()
        {
            // 3 + 4 * 2 = 3 + 8 = 11
            string expression = "3 + 4 * 2";
            double result = calculator.EvaluateInfix(expression);
            Assert.AreEqual(11, result);
        }
    }
}