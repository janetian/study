/** @file LinkedListInterface.h */

# ifndef _LINKED_LIST_INTERFACE
# define _LINKED_LIST_INTERFACE


#include "Node.h"

template <class ItemType>

class LinkedList
{
public:
	// check whether this list is empty
	virtual bool isEmpty() const = 0;
	// Gets the current number of entries in this list.
	virtual int getLength() const = 0;
	// Inserts an entry into this list at a given position.
	virtual bool insert(int newPosition, const ItemType & newEntry) = 0;
	// Removes the entry at a given position from this list.
	virtual bool remove(int position) = 0;
	// Removes all entries from this list.
	virtual void clear() = 0;

};

#endif