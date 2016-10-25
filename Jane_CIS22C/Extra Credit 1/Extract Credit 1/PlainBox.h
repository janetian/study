/** @file PlainBox.h */
#ifndef _PLAIN_BOX
#define _PLAIN_BOX

#include "BoxInterface.h"

// Declaration for the class PlainBox

template < class ItemType > class PlainBox : public BoxInterface < ItemType >
{
private:
	// Data field
	ItemType item;

public:
	// Default constructor
	PlainBox()
	{}

	// Parameterized constructor
	PlainBox(const ItemType & theItem)
	{
		item = theItem;
	}   // end constructor}

	// Mutator method that can change the value of the data field
	void setItem(const ItemType & theItem)
	{
		item = theItem;
	}   // end setItem

	// Accessor method to get the value of the data field
	ItemType getItem() const
	{
		return item;
	}   // end getItem

};  // end PlainBox

#endif