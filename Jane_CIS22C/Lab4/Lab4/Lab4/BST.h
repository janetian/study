/** @file BST.h */

#ifndef _BST
#define _BST

#include<iostream>
#include "BSTNode.h"
#include "Record.h"

template<class ItemType>

class BST
{
protected:
	BSTNode<ItemType>* root;
	// destroyTree
	void destroyTree(BSTNode<ItemType>* subTreePtr)
	{
		if (subTreePtr != nullptr)
		{
			destroyTree(subTreePtr->getLeft());
			destroyTree(subTreePtr->getRight());
			delete subTreePtr;
		}
	}

public:
	// constructors
	BST() 
	{
		root = nullptr;
	}
	BST(const ItemType& rootItem) 
	{
		root = new BSTNode<ItemType>(rootItem, nullptr, nullptr);
	}
	// destructor
	virtual ~BST()
	{
		destroyTree(root);
		root = nullptr;
	}
	// insert a item
	virtual bool insert(const ItemType& newItem) = 0;
	// find a item
	virtual BSTNode<ItemType>* find(string item) = 0;
	// remove a item
	virtual bool remove(string item) = 0;
	// postorder traversal
	void postorderTraversal(BSTNode<ItemType>* rootPtr, ofstream& output)
	{
		if (rootPtr != NULL)
		{
			postorderTraversal(rootPtr->getLeft(), output);
			postorderTraversal(rootPtr->getRight(), output);
			cout << (rootPtr->getItem()) << endl;
			output << (rootPtr->getItem()) << endl;
		}
	}
	// print in post order
	void printPostorder(ofstream& output)
	{
		postorderTraversal(root, output);
	}
	// preorder traversal
	void breadthfirstTraversal(BSTNode<ItemType>* rootPtr, ofstream& output)
	{
		if (rootPtr != NULL)
		{
			cout << (rootPtr->getItem()) << endl;
			output << (rootPtr->getItem()) << endl;
			breadthfirstTraversal(rootPtr->getLeft(), output);
			breadthfirstTraversal(rootPtr->getRight(), output);
		}
	}
	//print in pre order
	void printBredth(ofstream& output)
	{
		breadthfirstTraversal(root, output);
	}

};


#endif
