/** @file StackInterface.h */

#ifndef _STACK_INTERFACE
#define _STACK_INTERFACE

#include "Node.h"

template <class ItemType>

class Stack
{
public:
	// Adds a new entry to the top of this stack
	virtual bool push(const ItemType & newEntry) = 0;
	// Removes the top of this stack
	virtual bool pop() = 0;
	//Returns the top of this stack.
	virtual ItemType peek() const = 0;
};

#endif