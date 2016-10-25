/** @file Node.h */

#ifndef _NODE
#define _NODE

#include<iostream>

template<class ItemType>

class Node
{
private:
	ItemType item;        
	Node<ItemType>* next; 
	Node<ItemType>* left;  
	Node<ItemType>* right;
public:
	// dafault constructor
	Node() :
		next(nullptr),
		left(nullptr),
		right(nullptr)
	{}

	// constructor with one argument
	Node(const ItemType& myItem) :
		item(myItem),
		next(nullptr),
		left(nullptr),
		right(nullptr)
	{}

	Node(const ItemType& myItem, Node<ItemType>* nextPtr, Node<ItemType>* leftPtr, Node<ItemType>* rightPtr) :
		item(myItem),
		next(nextPtr),
		left(prevPtr),
		right(nullptr)
	{}
	
	void setItem(const ItemType& myItem)
	{ 
		item = myItem;
	}

	void setNext(Node<ItemType>* nextPtr)
	{
		next = nextPtr;
	}

	void setLeft(Node<ItemType>* leftPtr)
	{
		left = leftPtr;
	}

	void setRight(Node<ItemType>* rightPtr)
	{
		right = rightPtr;
	}

	ItemType getItem() const
	{
		return item;
	}

	Node<ItemType>* getNext() const
	{
		return next;
	}

	Node<ItemType>* getLeft() const
	{
		return left;
	}

	Node<ItemType>* getRight() const
	{
		return right;
	}

	void print() const
	{
		std::cout << item << std::endl;
	}
};

#endif
