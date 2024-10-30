#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_8.1_rec/8.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const char* testStr = "++--==+";

			// Змінні для зберігання підрахунків символів
			int plusCount = 0, minusCount = 0, equalCount = 0;

			// Викликаємо функцію CountSymbols
			CountSymbols(testStr, plusCount, minusCount, equalCount);

			// Перевірка результатів
			Assert::AreEqual(3, plusCount, L"Кількість '+' неправильна");
			Assert::AreEqual(2, minusCount, L"Кількість '-' неправильна");
			Assert::AreEqual(2, equalCount, L"Кількість '=' неправильна");
		}
	};
}
