/** @file ToyBox.h */
#ifndef _TOY_BOX
#define _TOY_BOX
#include "PlainBox.h"

enum Color
{
	BLACK, RED, BLUE, GREEN, YELLOW, WHITE
};

template < class ItemType > class ToyBox :public PlainBox < ItemType >
{
private:
	Color boxColor;

public:
	ToyBox()
	{
		PlainBox < ItemType >();
		boxColor = BLACK;
	}   // end default constructor

	ToyBox(const Color & theColor)
	{
		PlainBox < ItemType >();
		boxColor = theColor;
	}   // end constructor

	ToyBox(const ItemType & theItem, const Color & theColor)
	{
		PlainBox < ItemType >::setItem(theItem);
		boxColor = theColor;
	}   // end constructor

	Color getColor() const
	{
		return boxColor;
	}   // end getColor

};  // end ToyBox

#endif

