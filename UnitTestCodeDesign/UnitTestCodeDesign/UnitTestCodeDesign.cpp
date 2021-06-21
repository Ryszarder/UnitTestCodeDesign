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

		TEST_METHOD(Add)
		{
			LinkedList<int> List;
			List.InsertStart(5);
			List.InsertStart(2);
			List.InsertStart(7);
			List.InsertStart(10);

			Assert::AreEqual(List.GetNode(0)->m_Data, 10);
			Assert::AreEqual(List.GetNode(1)->m_Data, 7);
			Assert::AreEqual(List.GetNode(2)->m_Data, 2);
			Assert::AreEqual(List.GetNode(3)->m_Data, 5);
		}

		TEST_METHOD(CountSize)
		{
			LinkedList<int> List;
			List.InsertStart(5);
			List.InsertStart(2);
			List.InsertStart(7);
			List.InsertStart(10);
			List.InsertStart(3);
			List.InsertStart(14);

			Assert::AreEqual(List.GetCount(), 6);
		}

		TEST_METHOD(Remove)
		{
			LinkedList<int> List;
			List.InsertEnd(5);
			List.InsertEnd(2);
			List.InsertEnd(7);
			List.InsertEnd(16);
			List.InsertEnd(10);
			List.InsertEnd(3);
			List.InsertEnd(14);

			List.RemoveStart();
			List.RemoveEnd();
			List.Remove(16);

			Assert::AreEqual(List.GetFirstNode()->m_Data, 2);
			Assert::AreEqual(List.GetLastNode()->m_Data, 3);
			Assert::AreEqual(List.GetNode(2)->m_Data, 10);
		}

		TEST_METHOD(Sort)
		{
			LinkedList<int> List;
			List.InsertEnd(25);
			List.InsertEnd(14);
			List.InsertEnd(7);
			List.InsertEnd(29);
			List.Sort();

			Assert::AreEqual(List.GetNode(0)->m_Data, 7);
			Assert::AreEqual(List.GetNode(1)->m_Data, 14);
			Assert::AreEqual(List.GetNode(2)->m_Data, 25);
			Assert::AreEqual(List.GetNode(3)->m_Data, 29);
		}

		TEST_METHOD(Empty)
		{
			LinkedList<int> List;

			Assert::IsTrue(List.Empty());
		}
	};
}
