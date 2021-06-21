#pragma once
//Will generate a copy of functions and replace any T with correct data types
template <typename T>
class LinkedList
{
	//Public allows other files with the LinkedList.h to use call the functions
public:
	//Variables that are need put in a struct
	struct Node
	{
		//Creates the variables
		T m_Data;
		Node* m_pNext;
		Node* m_pPrev;
	};

	//Default constructor
	LinkedList()
	{
		//These 6 line of code make it so there are a node at the start and end
		//set to nullptr so the list can't call a prev or next node that doesn't exist
		m_pStart = new Node();
		m_pEnd = new Node();

		//Sets the start node next poniter to end node
		m_pStart->m_pNext = m_pEnd;
		//Sets the start node prev pointer to nullptr
		m_pStart->m_pPrev = nullptr;

		//Sets the end node next pointer to nullptr
		m_pEnd->m_pNext = nullptr;
		//Sets the end node prev poniter to start node
		m_pEnd->m_pPrev = m_pStart;

		//initialize the count to 0
		count = 0;
	}
	
	//Destructor
	~LinkedList()
	{
		//Deletes the variable m_pstart and m_pEnd When called
		delete m_pStart;
		delete m_pEnd;
	}

	//Adds in a new node to the back of the list
	void AddBack(T value)
	{
		//Creates a new node
		Node* pNewNode = new Node();
		//Sets new node value to the value put in the parameters
		pNewNode->m_Data = value;

		//Moves the pointers around to allow pNewNode into the back of the list
		//pNewNode Next pointer equals m_pEnd
		pNewNode->m_pNext = m_pEnd;
		//pNewNode prev pointer equals m_pEnd prev pointer
		pNewNode->m_pPrev = m_pEnd->m_pPrev;

		//m_pEnd prev pointer node next pointer equals to pNewNode
		m_pEnd->m_pPrev->m_pNext = pNewNode;
		//m_pEnd prev pointer equals pNewNode
		m_pEnd->m_pPrev = pNewNode;

		//Increase count by 1
		count++;
	}

	//Adds a Node to the location after a specific node
	void Insert(T search, T value)
	{
		//Creates a node that equals the value from the search function
		Node* itter = Find(search);

		//Creates a new node called pNewNode
		Node* pNewNode = new Node();
		//Sets pNewNode to the value in the parameters
		pNewNode->m_Data = value;

		pNewNode->m_pNext = itter->m_pNext;
		pNewNode->m_pPrev = itter;

		itter->m_pNext->m_pPrev = pNewNode;
		itter->m_pNext = pNewNode;

		count++;
	}

	//Adds a node to the start of the list
	void InsertStart(T value)
	{
		Node* itter = m_pStart;

		Node* pNewNode = new Node();
		pNewNode->m_Data = value;

		pNewNode->m_pNext = itter->m_pNext;
		pNewNode->m_pPrev = itter;

		itter->m_pNext->m_pPrev = pNewNode;
		itter->m_pNext = pNewNode;

		count++;
	}

	//Adds a node to the back of the list
	void InsertEnd(T value)
	{
		Node* itter = m_pEnd;

		Node* pNewNode = new Node();
		pNewNode->m_Data = value;

		pNewNode->m_pPrev = itter->m_pPrev;
		pNewNode->m_pNext = itter;

		itter->m_pPrev->m_pNext = pNewNode;
		itter->m_pPrev = pNewNode;

		count++;
	}

	//Removes a specific node
	void Remove(T value)
	{
		Node* pNodeToRemove = Find(value);

		Node* pPrev = pNodeToRemove->m_pPrev;
		Node* pNext = pNodeToRemove->m_pNext;

		pPrev->m_pNext = pNext;
		pNext->m_pPrev = pPrev;

		delete pNodeToRemove;

		--count;
	}

	//Removes the node at the start of the list
	void RemoveStart()
	{
		Node* pNodeStart = m_pStart->m_pNext;

		Node* pPrev = pNodeStart->m_pPrev;
		Node* pNext = pNodeStart->m_pNext;

		pPrev->m_pNext = pNext;
		pNext->m_pPrev = pPrev;

		delete pNodeStart;

		--count;
	}

	//Removes the node at the end of the list
	void RemoveEnd()
	{
		Node* pNodeEnd = m_pEnd->m_pPrev;

		Node* pPrev = pNodeEnd->m_pPrev;
		Node* pNext = pNodeEnd->m_pNext;

		pPrev->m_pNext = pNext;
		pNext->m_pPrev = pPrev;

		delete pNodeEnd;

		--count;
	}

	//Finds the node that equals the value and returns the that node
	Node* Find(T value)
	{
		Node* pCurrent = m_pStart->m_pNext;
		while (pCurrent != m_pEnd)
		{
			if (pCurrent->m_Data == value)
			{
				return pCurrent;
			}
			pCurrent = pCurrent->m_pNext;
		}
		return nullptr;
	}

	//Finds the node by order of position and returns that node
	Node* GetNode(T nIndex)
	{
		Node* pCurrent = m_pStart->m_pNext;
		for (int i = 0; i < nIndex; i++)
		{
			if (i == nIndex)
				return pCurrent;

			pCurrent = pCurrent->m_pNext;
		}
		return pCurrent;
	}

	//Gets the first node value in the list
	Node* GetFirstNode()
	{
		return m_pStart->m_pNext;
	}

	//Gets the last node value in the list
	Node* GetLastNode()
	{
		return m_pEnd->m_pPrev;
	}

	//Gets the size of the list
	int GetCount()
	{
		return count;
	}

	//Check if the list has no nodes in it
	bool Empty()
	{
		return (count == 0);
	}

	//Swaps the two values position that are put in the function
	void Swap(Node* B, Node* C)
	{
		//A -> B -> C -> D
		Node* A = B->m_pPrev;
		Node* D = C->m_pNext;

		A->m_pNext = C;
		C->m_pPrev = A;

		C->m_pNext = B;
		B->m_pPrev = C;

		B->m_pNext = D;
		D->m_pPrev = B;
	}

	//Sort through the List of nodes in ascending order
	void Sort()
	{
		Node* key;
		Node* comp;
		int j;

		for (int i = 1; i < count; ++i)
		{
			key = GetNode(i);
			j = i - 1;
			comp = GetNode(j);
			while (j >= 0 && key->m_Data < comp->m_Data)
			{
				Swap(GetNode(j), GetNode(j + 1));
				j = j - 1;
				comp = GetNode(j);
			}
		}
	}

	//Print out the nodes value 
	void Print()
	{
		Node* n = m_pStart->m_pNext;
		while (n != m_pEnd)
		{
			std::cout << (n->m_Data) << std::endl;
			n = n->m_pNext;
		}
	}

	//Private allows only this file can access the code
private:
	Node* m_pStart;
	Node* m_pEnd;

	int count;
};
