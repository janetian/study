/** @file Main.cpp */

/*
CIS 22C
Lab1 Let the user to add currencies into a wallet
Pre :
Post:
Return:
Jie Tian and Xiaojing Liu
*/


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "BagInterface.h"
#include "Currency.h"
#include "Wallet.h"


int main()
{
	// create instacne of wallet for user to add currencies
	BagInterface* myWallet = new Wallet();

	// random generator number to add or remove currency 
	unsigned seed = time(0);
	srand(seed);

	// remove a currency
	int RUBLEwholePart1 = rand() % 100;
	int RUBLEfractPart1 = rand() % 100;
	Currency* my_russia_ruble1 = new RussiaRuble(RUBLEwholePart1, RUBLEfractPart1);
	myWallet->remove(my_russia_ruble1, CurrencyName::EnumRuble);

	// add 1st currency
	int USwholePart = rand() % 100;
	int USfractPart = rand() % 100;
	Currency* my_us_dollar = new USDollar(USwholePart, USfractPart);
	myWallet->add(my_us_dollar, CurrencyName::EnumUSDollar);
	
	// add 2nd currency
	int UKwholePart = rand() % 100;
	int UKfractPart = rand() % 100;
	Currency* my_uk_pound = new UKPound(UKwholePart, UKfractPart);
	myWallet->add(my_uk_pound, CurrencyName::EnumPound);

	// add 3st currency
	int EUROwholePart = rand() % 100;
	int EUROfractPart = rand() % 100;
	Currency* my_euro = new Euro(EUROwholePart, EUROfractPart);
	myWallet->add(my_euro, CurrencyName::EnumEuro);

	// add 4th currency
	int AUwholePart = rand() % 100;
	int AUfractPart = rand() % 100;
	Currency* my_au_dollar = new AUDollar(AUwholePart, AUfractPart);
	myWallet->add(my_au_dollar, CurrencyName::EnumAUSDollar);

	// add 5th currency
	int YUANwholePart = rand() % 100;
	int YUANfractPart = rand() % 100;
	Currency* my_china_yuan = new ChinaYuan(YUANwholePart, YUANfractPart);
	myWallet->add(my_china_yuan, CurrencyName::EnumYuan);

	// add 6th currency
	int RUPEEwholePart = rand() % 100;
	int RUPEEfractPart = rand() % 100;
	Currency* my_india_rupee = new IndiaRupee(RUPEEwholePart, RUPEEfractPart);
	myWallet->add(my_india_rupee, CurrencyName::EnumRupee);

	// add 7th currency
	int YENwholePart = rand() % 100;
	int YENfractPart = rand() % 100;
	Currency* my_japanese_yen = new JapaneseYen(YENwholePart, YENfractPart);
	myWallet->add(my_japanese_yen, CurrencyName::EnumYen);

	// add 8th currency
	int PESOwholePart = rand() % 100;
	int PESOfractPart = rand() % 100;
	Currency* my_mexica_peso = new MexicaPeso(PESOwholePart, PESOfractPart);
	myWallet->add(my_mexica_peso, CurrencyName::EnumPeso);

	// add 9th currency
	int RUBLEwholePart = rand() % 100;
	int RUBLEfractPart = rand() % 100;
	Currency* my_russia_ruble = new RussiaRuble(RUBLEwholePart, RUBLEfractPart);
	myWallet->add(my_russia_ruble, CurrencyName::EnumRuble);

	// add 10th currency
	int BAHTwholePart = rand() % 100;
	int BAHTfractPart = rand() % 100;
	Currency* my_thai_baht = new ThaiBaht(BAHTwholePart, BAHTfractPart);
	myWallet->add(my_thai_baht, CurrencyName::EnumBaht);
	
	// add an existing currency
	int UKwholePart1 = rand() % 100;
	int UKfractPart1 = rand() % 100;
	Currency* my_uk_pound1 = new UKPound(UKwholePart1, UKfractPart1);
	myWallet->add(my_uk_pound1, CurrencyName::EnumPound);

	// add another existing currency
	int YUANwholePart1 = rand() % 100;
	int YUANfractPart1 = rand() % 100;
	Currency* my_china_yuan1 = new ChinaYuan(YUANwholePart1, YUANfractPart1);
	myWallet->add(my_china_yuan1, CurrencyName::EnumYuan);

	// remove currency
	int USwholePart1 = rand() % 100;
	int USfractPart1 = rand() % 100;
	Currency* my_us_dollar1 = new USDollar(USwholePart1, USfractPart1);
	myWallet->remove(my_us_dollar1, CurrencyName::EnumUSDollar);

	// remove another currency
	int PESOwholePart1 = rand() % 100;
	int PESOfractPart1 = rand() % 100;
	Currency* my_mexica_peso1 = new MexicaPeso(PESOwholePart1, PESOfractPart1);
	myWallet->remove(my_mexica_peso1, CurrencyName::EnumPeso);

	// output the total value and list of currencies in wallet
	std::cout << std::endl << "Here is the lists of currencys in the wallet:" << std::endl;
	myWallet->print();
	
	// release memory
	delete my_russia_ruble1;
	delete my_us_dollar;
	delete my_uk_pound;
	delete my_euro;
	delete my_au_dollar;
	delete my_china_yuan;
	delete my_india_rupee;
	delete my_japanese_yen;
	delete my_mexica_peso;
	delete my_russia_ruble;
	delete my_thai_baht;
	delete my_uk_pound1;
	delete my_china_yuan1;
	delete my_us_dollar1;
	delete my_mexica_peso1;

	// empty the wallet and print relevant information about the operation
	myWallet->clear();
	std::cout << "Number of currencies in the wallet now: " << myWallet->getCurrentSize() << std::endl << std::endl;

	delete myWallet;

	system("pause");
	return 0;
}