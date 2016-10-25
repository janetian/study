/** @file BSTNode.h */

#ifndef _BSTNODE
#define _BSTNODE

#include<iostream>

template<class ItemType>

class BSTNode
{
private:
	ItemType item;        // data value
	BSTNode<ItemType>* left;  // point to left node
	BSTNode<ItemType>* right;   // point to right node
public:
	// dafault constructor
	BSTNode() :
		left(nullptr),
		right(nullptr)
	{}

	// constructor with one argument
	BSTNode(const ItemType& myItem) :
		item(myItem),
		left(nullptr),
		right(nullptr)
	{}

	// constructor with three argument
	BSTNode(const ItemType& myItem, BSTNode<ItemType>* leftPtr, BSTNode<ItemType>* rightPtr) :
		item(myItem),
		left(leftPtr),
		right(rightPtr)
	{}

	void setItem(const ItemType& myItem)
	{
		item = myItem;
	}

	void setLeft(BSTNode<ItemType>* leftPtr)
	{
		left = leftPtr;
	}

	void setRight(BSTNode<ItemType>* rightPtr)
	{
		right = rightPtr;
	}

	ItemType getItem() const
	{
		return item;
	}

	BSTNode<ItemType>* getLeft() const
	{
		return left;
	}

	BSTNode<ItemType>* getRight() const
	{
		return right;
	}

	void print() const
	{
		std::cout << item << std::endl;
	}

};

#endif

