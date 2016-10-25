/** @file BSTbyName.h */

#ifndef _BSTbyName
#define _BSTbyName

#include<iostream>
#include "BST.h"

template<class ItemType>

class BSTbyName : public BST<ItemType>
{
public:
	BSTbyName()
	{
	}

	virtual ~BSTbyName()
	{
	}

	// insert a new item
	bool insert(const ItemType& newItem)
	{
		BSTNode<ItemType>* newNodePtr = new BSTNode<ItemType>();
		newNodePtr->setItem(newItem);
		BSTNode<ItemType>* parentNode = nullptr ;
		BSTNode<ItemType>* pos = root;
		while (pos != nullptr)
		{
			parentNode = pos;
			if (newNodePtr->getItem().getName() < pos->getItem().getName())   // pos trace for the new value until find 
			{                                                                    // the pos to add
				pos = pos->getLeft();
			}
			else
			{
				pos = pos->getRight();
			}
		}

		if (parentNode == nullptr)     // root is empty
		{
			root = newNodePtr;
		}
		else if (newNodePtr->getItem().getName() < parentNode->getItem().getName())    // set the new node
		{
			parentNode->setLeft(newNodePtr);
		}
		else
		{
			parentNode->setRight(newNodePtr);
		}
		return true;
	}

	// return a pointer to the node with given vaule
	BSTNode<ItemType>* find(string item)
	{
		BSTNode<ItemType>* pos = root;
		while (pos != nullptr && pos->getItem().getName() != item)
		{
			if (item < pos->getItem().getName())
			{
				pos = pos->getLeft();
			}
			else
			{
				pos = pos->getLeft();
			}
		}
		return pos;
	}

	// return a pointer to the minimm value in the subtree
	BSTNode<ItemType>* findMinimum(BSTNode<ItemType>* rootNode)
	{
		while (rootNode->getLeft() != nullptr)
		{
			rootNode = rootNode->getLeft();
		}
		return rootNode;
	}

	// return a pointer to the node whose value comes immediately after the given node
	BSTNode<ItemType>* nextInOrder(BSTNode<ItemType>* pos)
	{
		if (pos->getRight() != nullptr)    // The right subtree is not empty
		{
			return findMinimum(pos->getRight());
		}
		BSTNode<ItemType>* parentNode = parent(pos);
		while (parentNode != nullptr && pos == parentNode->getRight())  // The right subtree is empty
		{
			pos = parentNode;
			parentNode = parent(parentNode);
		}
		return parentNode;
	}

	// return a pointer to the given node's parent node.
	BSTNode<ItemType>* parent(BSTNode<ItemType>* child)
	{
		if (child == root)     // node is the rootq
		{
			return nullptr;
		}
		BSTNode<ItemType>* pos = root;
		while (pos != nullptr && pos->getLeft() != child && pos->getRight() != child)
		{
			if (child->getItem().getName() < pos->getItem().getName())
			{
				pos = pos->getLeft();
			}
			else
			{
				pos = pos->getRight();
			}
		}
		return pos;
	}

	// remove a node
	bool remove(string item)
	{
		BSTNode<ItemType>* pos = find(item);  // find the pointer of the given item
		BSTNode<ItemType>* node2Delete;
		if (pos->getLeft() == nullptr || pos->getRight() == nullptr)  // the node has 0 or 1 child
		{
			node2Delete = pos;
		}
			
		else                                   // the node has 2 children            
		{
			node2Delete = nextInOrder(pos);       
		}
		// find the child of the node to be deleted
		BSTNode<ItemType>* child;
		if (node2Delete->getLeft() != nullptr)    
		{
			child = node2Delete->getLeft();
		}	
		else
		{
			child = node2Delete->getRight();
		}	

		if (parent(node2Delete) == nullptr)     // check if delete the root
		{
			root = child;
		}
		else if (node2Delete == parent(node2Delete)->getLeft())    // splice out node2delete by making its parent point to child
		{
			parent(node2Delete)->setLeft(child);
		}
		else
		{
			parent(node2Delete)->setRight(child);        
		}

		if (node2Delete != pos)                      // copy over the date in node2delete
		{
			pos->getItem() = node2Delete->getItem();
		}
		delete node2Delete;
		return true;
	}
};

#endif
