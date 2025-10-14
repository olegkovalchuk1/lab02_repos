#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_05_3.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestYFunctionAccuracy)
		{
			double x = 0.5;

			
			double S = 1;
			double a = 1;
			for (int j = 1; j <= 8; j++)
			{
				double R = (-1) * x * x / ((2 * j) * (2 * j - 1));
				a *= R;
				S += a;
			}
			double expected = S;

			
			double actual = y(x);

			
			Assert::AreEqual(expected, actual, 1e-10);
		}
	};
}
