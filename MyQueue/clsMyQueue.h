#pragma once
#include "clsDblLinkedList.h"

template <class T> class clsMyQueue
{
	clsDblLinkedList<T> _List;

public:
	void push(T value)
	{
		_List.InsertAtEnd(value);
	}

	void print()
	{
		_List.PrintList();
	}

	void pop()
	{
		_List.DeleteFirstNode();
	}

	int size()
	{
		return _List.Size();
	}

	T front()
	{
		return _List.GetItem(0);
	}

	T back()
	{
		return _List.GetItem(size() - 1);
	}

	T GetItem(int Index)
	{
		return _List.GetItem(Index);
	}

	void Reverse()
	{
		_List.Reverse();
	}

	void UpdateItem(int Index, T newValue)
	{
		_List.UpdateItem(Index, newValue);
	}

	bool InsertAfter(int Index, T value)
	{
		return _List.InsertAfter(Index, value);
	}

	void InsertAtFront(T value)
	{
		_List.InsertAtBeginning(value);
	}

	void InsertAtBack(T value)
	{
		_List.InsertAtEnd(value);
	}

	void Clear()
	{
		_List.Clear();
	}
};

