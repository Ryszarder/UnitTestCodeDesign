#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCodeDesign
{
	TEST_CLASS(DoubleLinkedListTest)
	{
	public:
		
		TEST_METHOD(Create)
		{
			LinkedList<int>* List = new LinkedList<int>;
			Assert::IsNotNull(List);
		}
	};
}
