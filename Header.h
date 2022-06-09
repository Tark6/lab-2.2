#include <windows.h>
#include <iostream>

using namespace std;

class LIST
{
private:
	class Node
	{
	public:
		int data;
		Node* pNext;
		Node* pPrev;

		Node(int data)
		{
			this->data = data;
			pNext = nullptr;
			pPrev = nullptr;
		}
	};
	Node* head;
	Node* tail;
	int size;

public:

	LIST()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	LIST(int* arr, int n)
	{
		size = 0;
		head = nullptr;
		tail = nullptr;

		for (int i = 0; i < n; i++)
		{
			push_back(arr[i]);
		}
	}

	~LIST()
	{
		int size = this->size;
		for (int i = 0; i < size; i++)
		{
			pop_back();
		}
	}

	void push_front(int data)
	{
		if (head == nullptr)
		{
			head = new Node(data);
			tail = head;
		}
		else
		{
			Node* current = head;
			current->pPrev = new Node(data);
			head = current->pPrev;
			head->pNext = current;
		}
		size++;
	}

	void push_back(int data)
	{
		if (tail == nullptr)
		{
			tail = new Node(data);
			head = tail;
		}
		else
		{
			Node* current = tail;
			current->pNext = new Node(data);
			tail = current->pNext;
			tail->pPrev = current;
		}
		size++;
	}

	void pop_front()
	{
		if (head != nullptr)
		{
			Node* temp = head;
			head = temp->pNext;
			delete temp;
			size--;
		}
	}

	void pop_back()
	{
		if (tail != nullptr)
		{
			Node* temp = tail;
			tail = temp->pPrev;
			delete temp;
			size--;
		}
	}

	void MAKENULL()
	{
		int size = this->size;
		for (int i = 0; i < size; i++)
		{
			pop_front();
		}
		head = nullptr;
		tail = nullptr;
	}

	Node* END()
	{
		return tail;
	}

	Node* FIRST()
	{
		return head;
	}

	void INSERT(int data, int index)
	{
		if (index <= size && index >= 0)
		{
			int counter = 0;

			Node* current = head;

			while (counter != index)
			{
				current = current->pNext;
				counter++;
			}

			if (index == 0)
			{
				push_front(data);
			}
			else if (index == size)
			{
				push_back(data);
			}
			else
			{
				current->pNext->pPrev = new Node(data);
				current->pNext = current->pNext->pPrev;
				current->pNext->pPrev = current;
			}
		}
	}

	void Delete(int index)
	{
		if (head != nullptr)
		{
			if (index < size && index>0)
			{
				int counter = 0;
				Node* temp = head;

				while (counter != index)
				{
					temp = temp->pNext;
					counter++;
				}

				temp->pPrev->pNext = temp->pNext;
				temp->pNext->pPrev = temp->pPrev;

				delete temp;
			}
			else if (index == 0)
			{
				pop_front();
			}
			else if (index == size)
			{
				pop_back();
			}
		}
	}

	int LOCATE(int data)
	{
		Node* current = head;

		int counter = 0;

		while (current != nullptr)
		{
			if (current->data == data)
			{
				return counter;
			}
			current = current->pNext;
			counter++;
		}
	}

	int RETRIVE(int index)
	{
		Node* current = head;

		int counter = 0;

		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pNext;
			counter++;
		}
	}

	Node* PREVIOUS(int index)
	{
		Node* current = head;

		int counter = 0;

		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->pPrev;
			}
			current = current->pNext;
			counter++;
		}
	}

	Node* NEXT(int index)
	{
		Node* current = head;

		int counter = 0;

		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->pNext;
			}
			current = current->pNext;
			counter++;
		}
	}

	void PRINTLIST()
	{
		for (int i = 0; i < size; i++)
		{
			cout << RETRIVE(i) << endl;
		}
	}


};
