#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_05_2.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestArthSeriesAccuracy)
		{
			double x = 0.5;
			double eps = 1e-8;
			int n = 0;
			double s = 0;

			
			S(x, eps, n, s);

			
			double expected = 0.5 * log((1 + x) / (1 - x));

			
			Assert::AreEqual(expected, s, 1e-7);
		}
	};
}
