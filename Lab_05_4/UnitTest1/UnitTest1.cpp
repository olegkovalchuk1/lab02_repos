#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_05_4.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int N = 2;

			
			double expected = 1.0;
			for (int i = N; i <= 16; i++)
				expected *= (1.0 * i * N) / (i * i + N * N);

			
			double actual = S1(N, N);

			
			Assert::AreEqual(expected, actual, 1e-12);
		}
	};
}
