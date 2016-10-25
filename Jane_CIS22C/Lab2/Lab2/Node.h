/** @file Node.h */

#ifndef _NODE
#define _NODE

#include<iostream>

template<class ItemType>

class Node
{
private:
	ItemType item;        // data value
	Node<ItemType>* next;  // point to next node
	Node<ItemType>* prev;   // point to previous node
public:
	// dafault constructor
	Node() :
		next(nullptr),
		prev(nullptr)
	{}

	// constructor with one argument
	Node(const ItemType& myItem) :
		item(myItem),
		next(nullptr),
		prev(nullptr)
	{}

	// constructor with three argument
	Node(const ItemType& myItem, Node<ItemType>* nextPtr, Node<ItemType>* prevPtr) :
		item(myItem),
		next(nextPtr),
		prev(prevPtr)
	{}
	
	void setItem(const ItemType& myItem)
	{ 
		item = myItem;
	}

	void setNext(Node<ItemType>* nextPtr)
	{
		next = nextPtr;
	}

	void setPrev(Node<ItemType>* prevPtr)
	{
		prev = prevPtr;
	}

	ItemType getItem() const
	{
		return item;
	}

	Node<ItemType>* getNext() const
	{
		return next;
	}

	Node<ItemType>* getPrev() const
	{
		return prev;
	}

	void print() const
	{
		std::cout << item << std::endl;
	}
};

#endif
