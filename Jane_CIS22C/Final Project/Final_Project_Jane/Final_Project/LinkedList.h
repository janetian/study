/** @file LinkedList.h */

#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "Node.h"

template <class ItemType> 

class LinkedList
{
private:
	Node<ItemType>* headPtr;   // point to head
	int numOfNode;     
public:
	// default constructor
	LinkedList() : 
		headPtr(nullptr), 
		numOfNode(0)
	{}

	// destructor
	~LinkedList()
	{
		clear();
	}

	void setHeadPtr(Node<ItemType>* head)
	{
		headPtr = head;
	}

	Node<ItemType>* getHeadPtr() const
	{
		return headPtr;
	}

	// check whether this list is empty
	bool isEmpty() const
	{
		return (numOfNode == 0);
	}

	// Gets the current number of entries in this list.
	int getLength() const
	{
		return numOfNode;
	}

	// Inserts an entry into this list at a given position.
	bool insert(int position, Node<ItemType>* newNodePtr)
	{
		if ((position >= 0) && (position <= getLength()))  // check the position is valid
		{
			if (position == 0)
			{
				// insert the new node at the beginnig
				newNodePtr->setNext(headPtr);
				headPtr = newNodePtr;
			}
			else
			{
				// find the node that before the new node, whose index is position - 1
				Node<ItemType>* prePtr = headPtr;
				for (int i = 0; i < position-1; i++)
				{
					prePtr = prePtr->getNext();
				}
				// insert the new node
				newNodePtr->setNext(prePtr->getNext());
				prePtr->setNext(newNodePtr);
			}
			numOfNode++;
		}
		return true;
	}


	// Removes the entry at a given position from this list.
	bool remove(int position)
	{                             
		if (!isEmpty() && position >= 0 && position <= getLength())  // make sure the list is not empty and the postion is valid
		{
			Node<ItemType>* curPtr = nullptr;
			if (position == 0)   // remove the first nood
			{
				curPtr = headPtr;
				headPtr = headPtr->getNext();
			}
			else
			{
				// find the node that before the one to be deleted
				Node<ItemType>* prePtr = headPtr;
				for (int i = 0; i < position-1; i++)
				{
					prePtr = prePtr->getNext();
				}
				// save the point to be deleted 
				curPtr = prePtr->getNext();
				// connect previous node to the one after
				prePtr->setNext(curPtr->getNext());
			}
			delete curPtr;
			numOfNode--;
		}
		return true;
	}

	// Gets the entry at the given position in this list.
	Node<ItemType>* getEntry(int position) const
	{ 
		Node<ItemType>* curPtr = headPtr;
		if ( (position >= 0) && (position <= getLength()) ) // check the position is valid
		{
			for (int i = 0; i < position; i++)
			{
				curPtr = curPtr->getNext();
			}
		}
		return curPtr;
	}
	
	// Removes all entries from this list.
	void clear()
	{
		while (headPtr != nullptr)
		{
			Node<ItemType>* nodeToDeletePtr = headPtr;
			headPtr = headPtr->getNext();
			delete nodeToDeletePtr;
		} 
		numOfNode = 0;
	}

	// print the value of the node
	void print() const
	{
		Node<ItemType>* nodePtr = headPtr;
		while (nodePtr)
		{
			nodePtr->print();
			nodePtr = nodePtr->getNext();
		}
	}
}; 

#endif