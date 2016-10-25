/** @file Wallet.cpp */

#include "Wallet.h"

Wallet::Wallet() : numOfCurrencies(0)
{
	for (int i = 0; i < BAG_INTERFACE_MAX_CURRENCIES_NUM; ++i)
	{
		tenCurrencies[i] = NULL;
	}
}

Wallet::~Wallet()
{
	clear();
}

// get the current number of currencies in the wallet
int Wallet::getCurrentSize() const
{
	return numOfCurrencies;
}

// check whether the wallet is empty
bool Wallet::isEmpty() const
{
	return (numOfCurrencies == 0);
}

// add a new currency to the wallet 
bool Wallet::add(Currency* newEntry, CurrencyName currencyName)
{
	if (contains(newEntry, currencyName))    // currency exist
	{
		*(tenCurrencies[currencyName]) = *(tenCurrencies[currencyName]) + *newEntry;
		std::cout << "Add existing currency:" << std::endl << *newEntry << std::endl;
	}
	else       // currency not exist
	{
		switch (currencyName)
		{
		case CurrencyName::EnumUSDollar:
			tenCurrencies[currencyName] = new USDollar(newEntry->wholeParts, newEntry->fractParts);
			std::cout << "Add currency:" << std::endl << *newEntry << std::endl;
			break;
		case CurrencyName::EnumPound:
			tenCurrencies[currencyName] = new UKPound(newEntry->wholeParts, newEntry->fractParts);
			std::cout << "Add currency:" << std::endl << *newEntry << std::endl;
			break;
		case CurrencyName::EnumEuro:
			tenCurrencies[currencyName] = new Euro(newEntry->wholeParts, newEntry->fractParts);
			std::cout << "Add currency:" << std::endl << *newEntry << std::endl;
			break;
		case CurrencyName::EnumAUSDollar:
			tenCurrencies[currencyName] = new AUDollar(newEntry->wholeParts, newEntry->fractParts);
			std::cout << "Add currency:" << std::endl << *newEntry << std::endl;
			break;
		case CurrencyName::EnumYuan:
			tenCurrencies[currencyName] = new ChinaYuan(newEntry->wholeParts, newEntry->fractParts);
			std::cout << "Add currency:" << std::endl << *newEntry << std::endl;
			break;
		case CurrencyName::EnumRupee:
			tenCurrencies[currencyName] = new IndiaRupee(newEntry->wholeParts, newEntry->fractParts);
			std::cout << "Add currency:" << std::endl << *newEntry << std::endl;
			break;
		case CurrencyName::EnumYen:
			tenCurrencies[currencyName] = new JapaneseYen(newEntry->wholeParts, newEntry->fractParts);
			std::cout << "Add currency:" << std::endl << *newEntry << std::endl;
			break;
		case CurrencyName::EnumPeso:
			tenCurrencies[currencyName] = new MexicaPeso(newEntry->wholeParts, newEntry->fractParts);
			std::cout << "Add currency:" << std::endl << *newEntry << std::endl;
			break;
		case CurrencyName::EnumRuble:
			tenCurrencies[currencyName] = new RussiaRuble(newEntry->wholeParts, newEntry->fractParts);
			std::cout << "Add currency:" << std::endl << *newEntry << std::endl;
			break;
		case CurrencyName::EnumBaht:
			tenCurrencies[currencyName] = new ThaiBaht(newEntry->wholeParts, newEntry->fractParts);
			std::cout << "Add currency:" << std::endl << *newEntry << std::endl;
			break; 
		default:
			return false;
		}
		numOfCurrencies++;
		if (numOfCurrencies == 10)
		{
			std::cout << "There are 10 currenies in the wallet now. Cannot add more." << std::endl << std::endl;;
		}
	}
	return true;
}

// remove a currency from the wallet
bool Wallet::remove(Currency* newEntry, CurrencyName currencyName)
{
	if (!isEmpty())   // There are currencies in the wallet
	{
		if (contains(newEntry, currencyName))   // currency exist
		{
			*(tenCurrencies[currencyName]) = *(tenCurrencies[currencyName]) - *newEntry;
			std::cout << "Remove existing currency:" << std::endl << *newEntry << std::endl;
			if (tenCurrencies[currencyName]->wholeParts == 0)
			{
				std::cout << "Not enough money in the wallet, remove all money." << std::endl << std::endl;
			}
			return true;
		}
		else  
		{
			std::cout << "The currency does not exist." << std::endl;
			return false;
		}
	}
	else   // wallet is empty
	{
		std::cout << "Remove currency: " << std::endl;
		std::cout << "The wallet is empty. No money to remove." << std::endl << std::endl;
	}
}
	
// remove all currencyies in the wallet
void Wallet::clear()
{
	for (int i = 0; i < BAG_INTERFACE_MAX_CURRENCIES_NUM; ++i)
	{
		if (tenCurrencies[i])
		{
			delete tenCurrencies[i];
			tenCurrencies[i] = NULL;
			numOfCurrencies = 0;
		}
	}
	std::cout << std::endl << "Remove all currencies in the wallet." << std::endl;
	std::cout << "The wallet is empty now." << std::endl;
}

// check whether the wallet already has a given currency
bool Wallet::contains(Currency* newEntry, CurrencyName currencyName)
{
	return (tenCurrencies[currencyName] != NULL);
}

// print out the currencies in the wallet
void Wallet::print()
{
	for (int i = 0; i < BAG_INTERFACE_MAX_CURRENCIES_NUM; i++)
	{
		if (tenCurrencies[i] != NULL)
		{
			std::cout << *(tenCurrencies[i]);
		}
	}
}
