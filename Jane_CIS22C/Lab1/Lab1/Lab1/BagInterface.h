/** @file BagInterface.h */

# ifndef _BAG_INTERFACE
# define _BAG_INTERFACE

#include <iostream>
#include "Currency.h"


class BagInterface
{
public:
	// get the current number of currencies in the wallet
	virtual int getCurrentSize() const = 0;

	// check whether the wallet is empty
	virtual bool isEmpty() const = 0;

	// add a new currency to the wallet 
	virtual bool add(Currency* newEntry, CurrencyName currencyName) = 0;

	// remove a currency from the wallet
	virtual bool remove(Currency* newEntry, CurrencyName currencyName) = 0;

	// remove all currencyies in the wallet
	virtual void clear() = 0;

	// check whether the wallet already has a given currency
	virtual bool contains(Currency* newEntry, CurrencyName currencyName) = 0;

	// print out the currencies in the wallet
	virtual void print() = 0;
};  

#endif