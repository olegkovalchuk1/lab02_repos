#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_05_5.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestPowerPositiveExponent)
        {
            Level = 0;
            Depth = 0;
            double result = power(2.0, 3);
            Assert::AreEqual(8.0, result, 1e-6);
        }
    };
}
