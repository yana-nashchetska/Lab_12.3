#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.3/Lab_12.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest123
{
	TEST_CLASS(UnitTest123)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL;
			Elem* last = NULL;

			int rez_expected = 3;
			int num = 0;
			for (int i = 0; i < 6; i++)
			{
				num++;
				enqueue(first, last, num);
			}
			int rez = odd_numbers(first);
			Assert::AreEqual(rez, rez_expected);

			dequeue(first, last);

		}
	};
}
