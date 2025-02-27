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
};

