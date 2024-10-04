#include "pch.h"
#include "CppUnitTest.h"
#include "../lab6.2(rec).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int n = 5;
			int r[n];
			int Low = 1;
			int High = 10;

			Create(r, n, Low, High, 0);

			for (int i = 0; i < n; i++) {
				Assert::IsTrue(r[i] >= Low && r[i] <= High);
			}

			int max = Max(r, n, 0, r[0]);
			bool foundMax = false;
			for (int i = 0; i < n; i++) {
				if (r[i] == max) {
					foundMax = true;
					break;
				}
			}
			Assert::IsTrue(foundMax);

			int indexOfMax = MaxIndex(r, n, max, 0);
			Assert::IsTrue(indexOfMax >= 0 && indexOfMax < n);
			Assert::AreEqual(r[indexOfMax], max);
		}
	};
}
