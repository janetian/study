/** @file Currency.h */

#ifndef _Currency
#define _Currency

#include <iostream>
#include <iomanip>

enum CurrencyName
{
	EnumUSDollar, EnumPound, EnumEuro, EnumAUSDollar, EnumYuan, EnumRupee, EnumYen, EnumPeso, EnumRuble, EnumBaht 
};

enum FractName
{
	EnumUSCent, EnumPence, EnumEuroCent, EnumAUSCent, EnumFen, EnumPaisa, EnumSen, EnumCentavo, EnumKopek, EnumSatang
};

class Currency
{
//public:
public:
	CurrencyName currencyName;
	int			 wholeParts;
	int          fractParts;
	FractName    fractName;
public:
	Currency() : currencyName(), wholeParts(0), fractParts(0), fractName() {}
	virtual ~Currency() {}
	//operator overload
	Currency operator+(const Currency & right);
	Currency operator-(const Currency & right);
	// friend function
	friend std::ostream & operator<< (std::ostream & ostr, const Currency & object);
};


// Initialize currency objects demonstrating polymorphic construction. 
class USDollar : public Currency
{
public:
	USDollar() :
		Currency()
	{}
	USDollar(int whole_part, int fract_part)
	{
		Currency::currencyName = CurrencyName::EnumUSDollar;
		Currency::wholeParts = whole_part;
		Currency::fractParts = fract_part;
		Currency::fractName = FractName::EnumUSCent;
	}
};

class UKPound : public Currency
{
public:
	UKPound(int whole_part, int fract_part)
	{
		Currency::currencyName = CurrencyName::EnumPound;
		Currency::wholeParts = whole_part;
		Currency::fractParts = fract_part;
		Currency::fractName = FractName::EnumPence;
	}
};

class Euro : public Currency
{
public:
	Euro(int whole_part, int fract_part)
	{
		Currency::currencyName = CurrencyName::EnumEuro;
		Currency::wholeParts = whole_part;
		Currency::fractParts = fract_part;
		Currency::fractName = FractName::EnumEuroCent;
	}
};

class AUDollar : public Currency
{
public:
	AUDollar(int whole_part, int fract_part)
	{
		Currency::currencyName = CurrencyName::EnumAUSDollar;
		Currency::wholeParts = whole_part;
		Currency::fractParts = fract_part;
		Currency::fractName = FractName::EnumAUSCent;
	}
};

class ChinaYuan : public Currency
{
public:
	ChinaYuan(int whole_part, int fract_part)
	{
		Currency::currencyName = CurrencyName::EnumYuan;
		Currency::wholeParts = whole_part;
		Currency::fractParts = fract_part;
		Currency::fractName = FractName::EnumFen;
	}
};

class IndiaRupee : public Currency
{
public:
	IndiaRupee(int whole_part, int fract_part)
	{
		Currency::currencyName = CurrencyName::EnumRupee;
		Currency::wholeParts = whole_part;
		Currency::fractParts = fract_part;
		Currency::fractName = FractName::EnumPaisa;
	}
};

class JapaneseYen : public Currency
{
public:
	JapaneseYen(int whole_part, int fract_part)
	{
		Currency::currencyName = CurrencyName::EnumYen;
		Currency::wholeParts = whole_part;
		Currency::fractParts = fract_part;
		Currency::fractName = FractName::EnumSen;
	}
};

class MexicaPeso : public Currency
{
public:
	MexicaPeso(int whole_part, int fract_part)
	{
		Currency::currencyName = CurrencyName::EnumPeso;
		Currency::wholeParts = whole_part;
		Currency::fractParts = fract_part;
		Currency::fractName = FractName::EnumCentavo;
	}
};

class RussiaRuble : public Currency
{
public:
	RussiaRuble(int whole_part, int fract_part)
	{
		Currency::currencyName = CurrencyName::EnumRuble;
		Currency::wholeParts = whole_part;
		Currency::fractParts = fract_part;
		Currency::fractName = FractName::EnumKopek;
	}
};

class ThaiBaht : public Currency
{
public:
	ThaiBaht(int whole_part, int fract_part)
	{
		Currency::currencyName = CurrencyName::EnumBaht;
		Currency::wholeParts = whole_part;
		Currency::fractParts = fract_part;
		Currency::fractName = FractName::EnumSatang;
	}
};


#endif