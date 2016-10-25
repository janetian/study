/** @file Wallet.h */

#ifndef _Wallet
#define _Wallet

#include "BagInterface.h"

#define BAG_INTERFACE_MAX_CURRENCIES_NUM 10

class Wallet : public BagInterface
{
public:
	Currency* tenCurrencies[BAG_INTERFACE_MAX_CURRENCIES_NUM];
	int numOfCurrencies;
public:
	Wallet();
	virtual ~Wallet();

	// get the current number of currencies in the wallet
	int getCurrentSize() const;
	
	// check whether the wallet is empty
	bool isEmpty() const;
	
	// add a new currency to the wallet 
	bool add(Currency* newEntry, CurrencyName currencyName);
	
	// remove a currency from the wallet
	bool remove(Currency* newEntry, CurrencyName currencyName);
	
	// remove all currencyies in the wallet
	void clear();

	// check whether the wallet already has a given currency
	bool contains(Currency* newEntry, CurrencyName currencyName);

	// print out the currencies in the wallet
	void print();
	
};

#endif