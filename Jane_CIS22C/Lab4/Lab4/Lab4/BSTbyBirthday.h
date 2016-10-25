/** @file BSTbyBirthday.h */

#ifndef _BSTbyBirthday
#define _BSTbyBirthday

#include<iostream>
#include "BST.h"

template<class ItemType>

class BSTbyBirthday : public BST<ItemType>
{
public:
	BSTbyBirthday()
	{
	}

	virtual ~BSTbyBirthday()
	{
	}

	// insert a new item
	bool insert(const ItemType& newItem)
	{
		BSTNode<ItemType>* newNodePtr = new BSTNode<ItemType>();
		newNodePtr->setItem(newItem);
		BSTNode<ItemType>* parentNode = nullptr;
		BSTNode<ItemType>* pos = root;
		while (pos != nullptr)
		{
			parentNode = pos;
			if (newNodePtr->getItem().getBirthday() < pos->getItem().getBirthday())
			{
				pos = pos->getLeft();
			}
			else
			{
				pos = pos->getRight();
			}
		}

		if (parentNode == nullptr)
		{
			root = newNodePtr;
		}
		else if (newNodePtr->getItem().getBirthday() < parentNode->getItem().getBirthday())
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
		while (pos != nullptr && pos->getItem().getBirthday() != item)
		{
			if (item < pos->getItem().getBirthday())
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
		if (pos->getRight() != nullptr)
		{
			return findMinimum(pos->getRight());
		}
		BSTNode<ItemType>* parentNode = parent(pos);
		while (parentNode != nullptr && pos == parentNode->getRight())
		{
			pos = parentNode;
			parentNode = parent(parentNode);
		}
		return parentNode;
	}

	// return a pointer to the given node's parent node.
	BSTNode<ItemType>* parent(BSTNode<ItemType>* child)
	{
		if (child == root)
		{
			return nullptr;
		}
		BSTNode<ItemType>* pos = root;
		while (pos != nullptr && pos->getLeft() != child && pos->getRight() != child)
		{
			if (child->getItem().getBirthday() < pos->getItem().getBirthday())
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

	bool remove(string item)
	{
		BSTNode<ItemType>* pos = find(item);
		BSTNode<ItemType>* node2Delete;
		if (pos->getLeft() == nullptr || pos->getRight() == nullptr)  // the node do not has child
		{
			node2Delete = pos;
		}

		else
		{
			node2Delete = nextInOrder(pos);
		}

		BSTNode<ItemType>* child;
		if (node2Delete->getLeft() != nullptr)
		{
			child = node2Delete->getLeft();
		}
		else
		{
			child = node2Delete->getRight();
		}

		if (parent(node2Delete) == nullptr)
		{
			root = child;
		}

		else if (node2Delete == parent(node2Delete)->getLeft())
		{
			parent(node2Delete)->setLeft(child);
		}
		else
		{
			parent(node2Delete)->setRight(child);
		}

		if (node2Delete != pos)
		{
			pos->getItem() = node2Delete->getItem();
		}
		delete node2Delete;
		return true;
	}
};

#endif
