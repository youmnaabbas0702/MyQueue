#pragma once
#include <iostream>
using namespace std;

template<class T> class clsDblLinkedList
{
protected:

	int _Size = 0;

public:
	class Node
	{
	public:
		T Value;
		Node* Next;
		Node* Prev;
	};

	Node* head = NULL;

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return _Size == 0;
	}

	void Clear()
	{
		while (head != NULL)
		{
			DeleteFirstNode();
		}
	}

	void PrintList()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->Value << endl;
			temp = temp->Next;
		}
	}

	void InsertAtBeginning(T value)
	{
		Node* newNode = new Node();
		newNode->Prev = NULL;
		newNode->Value = value;

		if (head == NULL)
		{
			newNode->Next = NULL;
			head = newNode;
			_Size++;
			return;
		}

		head->Prev = newNode;
		newNode->Next = head;
		head = newNode;
		_Size++;
	}

	Node* Find(T value)
	{
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->Value == value)
				return temp;
			temp = temp->Next;
		}
		return NULL;
	}

	void InsertAfter(Node* NodeAfter, T value)
	{
		if (NodeAfter == NULL)
		{
			cout << "The previous node cant be null\n";
			return;
		}
		Node* newNode = new Node();

		newNode->Value = value;

		newNode->Next = NodeAfter->Next;
		newNode->Prev = NodeAfter;

		if (NodeAfter->Next != NULL)
			NodeAfter->Next->Prev = newNode;

		NodeAfter->Next = newNode;
		_Size++;
	}

	void InsertAtEnd(T value)
	{
		Node* newNode = new Node();
		newNode->Value = value;
		newNode->Next = NULL;

		if (head == NULL)
		{
			newNode->Prev = NULL;
			head = newNode;
		}

		else
		{
			Node* searchNode = head;

			while (searchNode->Next != NULL)
			{
				searchNode = searchNode->Next;
			}

			newNode->Prev = searchNode;
			searchNode->Next = newNode;
		}
		_Size++;
	}

	void DeleteNode(Node*& NodeToDelete)
	{
		if (head == NULL || NodeToDelete == NULL) {
			return;
		}
		if (head == NodeToDelete) {
			head = NodeToDelete->Next;
		}
		if (NodeToDelete->Next != NULL) {
			NodeToDelete->Next->Prev = NodeToDelete->Prev;
		}
		if (NodeToDelete->Prev != NULL) {
			NodeToDelete->Prev->Next = NodeToDelete->Next;
		}
		delete NodeToDelete;
		_Size--;
	}

	void DeleteFirstNode()
	{
		//if list is empty return
		if (head == NULL)
			return;

		Node* Current = head;

		if (Current->Next != NULL)
			Current->Next->Prev = NULL;
		head = Current->Next;

		delete Current;
		_Size--;
	}

	void DeleteLastNode()
	{
		//if list is empty return
		if (head == NULL)
			return;

		Node* Current = head;
		Node* Prev = head;

		//if it is only one node
		if (Current->Next == NULL)
		{
			head = NULL;
			delete Current;
			return;
		}

		//till we find the last node
		while (Current != NULL && Current->Next != NULL)
		{
			Prev = Current;
			Current = Current->Next;
		}

		Prev->Next = NULL;
		delete Current;
		_Size--;
	}

	void Reverse()
	{
		if (head == NULL || head->Next == NULL)
			return;

		do
		{
			Node* temp = head->Next;
			head->Next = head->Prev;
			head->Prev = temp;

			if (head->Prev != NULL)
				head = head->Prev;

		} while (head->Prev != NULL);
	}

	/*void  Reverse()
	{
		Node* current = head;
		Node* temp = nullptr;
		while (current != nullptr) {
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}

		if (temp != nullptr) {
			head = temp->prev;
		}
	}*/

	Node* GetNode(int Index)
	{
		if (Index > _Size - 1 || Index < 0 || head == NULL)
			return NULL;

		Node* Current = head;
		int i = 0;
		while (i < Index && Current->Next != NULL)
		{
			Current = Current->Next;
			i++;
		}
		return Current;
	}

	T GetItem(int Index)
	{
		Node* node = GetNode(Index);
		if (node != NULL)
			return node->Value;
		return NULL;
	}

	bool UpdateItem(int Index, T newValue)
	{
		Node* node = GetNode(Index);
		if (node != NULL)
		{
			node->Value = newValue;
			return true;
		}
		else
			return false;
	}

	bool InsertAfter(int Index, T value)
	{
		Node* node = GetNode(Index);
		if (node != NULL)
		{
			InsertAfter(node, value);
			return true;
		}
		else
			return false;
	}
};


