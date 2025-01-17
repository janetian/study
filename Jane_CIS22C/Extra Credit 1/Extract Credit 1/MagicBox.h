/** @file MagicBox.h */
#ifndef _MAGIC_BOX
#define _MAGIC_BOX
#include "PlainBox.h"
template < class ItemType > class MagicBox :public PlainBox < ItemType >
{
private:
	bool firstItemStored;

public:
	MagicBox()
	{
		PlainBox < ItemType >();
		firstItemStored = false;	// Box has no magic initially
	}   // end default constructor

	MagicBox(const ItemType & theItem)
	{
		firstItemStored = false;	// Box has no magic initially

		setItem(theItem);
		// Box has magic now
	}   // end constructor

	void setItem(const ItemType & theItem)
	{
		if (!firstItemStored)
		{
			PlainBox < ItemType >::setItem(theItem);
			firstItemStored = true;	// Box now has magic
		}	// end if
	}   // end setItem

};  // end MagicBox

#endif