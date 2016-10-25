/** @file Stack.h */

#ifndef _STACK
#define _STACK

#include "LinkedList.h"

template <class ItemType> 

class Stack
{
private:
	LinkedList<ItemType> linkedList;
public:
	// default constuctor
	Stack() :
		linkedList()
	{}

	// check whether this stack is empty
	bool isEmpty() const
	{
		return linkedList.isEmpty();
	}

	// Adds a new entry to the top of this stack
	bool push(const ItemType& newItem)
	{
		Node<ItemType>* newNodePtr = new Node<ItemType>();
		newNodePtr->setItem(newItem);
		return linkedList.insert(0, newNodePtr);
	}

	// Removes the top of this stack
	bool pop()
	{
		if (!isEmpty())
		{
			linkedList.remove(0);
		}
		return true;
	}

	//Returns the top of this stack.
	ItemType peek() const
	{
		if (!isEmpty())
		{
			return linkedList.getEntry(0)->getItem();
		}
	}

	// print the value of the node
	void print() const
	{
		linkedList.print();
	}

	// destructor
	~Stack()
	{
		// keep pop until the stack is empty
		while (!isEmpty()) 
		{
			pop();
		}
	}
};	

#endif