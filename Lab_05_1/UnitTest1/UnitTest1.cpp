#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_05_1/Lab_05_1.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double result = f(1,2,3);
			double expected = (1 + 2 + 3) / (sin(1 * 2) * sin(1 * 2) + 3 * 3);
			Assert::AreEqual(result, expected);
		}
	}; 
}
