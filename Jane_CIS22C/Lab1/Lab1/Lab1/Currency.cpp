/** @file Currency.cpp */

#include "Currency.h"

Currency Currency::operator+(const Currency & right)
{
	Currency result;
	result.currencyName = currencyName;
	result.fractName = fractName;
	if (result.currencyName == right.currencyName)
	{
		result.wholeParts = wholeParts + right.wholeParts;
		result.fractParts = fractParts + right.fractParts;
		if (result.fractParts >= 100)
		{
			result.wholeParts += (result.fractParts / 100);
			result.fractParts = result.fractParts % 100;
		}
	}
	return result;
}

Currency Currency::operator-(const Currency & right)
{
	Currency result;
	result.currencyName = currencyName;
	result.fractName = fractName;
	if (result.currencyName == right.currencyName)
	{
		result.wholeParts = wholeParts - right.wholeParts;
		result.fractParts = fractParts - right.fractParts;
		if (result.fractParts < 0 && result.wholeParts > 0)
		{
			result.wholeParts -= ((abs(result.fractParts) / 100) + 1);
			result.fractParts = 100 - (abs(result.fractParts) % 100);
		}
		if (result.wholeParts < 0)
		{
			result.wholeParts = 0;
			result.fractParts = 0;
		}
	}
	return result;
}

// overload << operator
std::ostream & operator<< (std::ostream & ostr, const Currency & object)
{
	switch (object.currencyName)
	{
	case CurrencyName::EnumUSDollar:
		ostr << std::left << std::setw(12) << "Dollar" << std::setw(5) << object.wholeParts << std::setw(5) << object.fractParts << std::setw(5) << "Cent" << std::endl;
		break;
	case CurrencyName::EnumPound:
		ostr << std::left << std::setw(12) << "Pound" << std::setw(5) << object.wholeParts << std::setw(5) << object.fractParts << std::setw(5) << "Pence" << std::endl;
		break;
	case CurrencyName::EnumEuro:
		ostr << std::left << std::setw(12) << "Euro" << std::setw(5) << object.wholeParts << std::setw(5) << object.fractParts << std::setw(5) << "Cent" << std::endl;
		break;
	case CurrencyName::EnumAUSDollar:
		ostr << std::left << std::setw(12) << "AUSDollar" << std::setw(5) << object.wholeParts << std::setw(5) << object.fractParts << std::setw(5) << "Cent" << std::endl;
		break;
	case CurrencyName::EnumYuan:
		ostr << std::left << std::setw(12) << "Yuan" << std::setw(5) << object.wholeParts << std::setw(5) << object.fractParts << std::setw(5) << "Fen" << std::endl;
		break;
	case CurrencyName::EnumRupee:
		ostr << std::left << std::setw(12) << "Rupee" << std::setw(5) << object.wholeParts << std::setw(5) << object.fractParts << std::setw(5) << "Paisa" << std::endl;
		break;
	case CurrencyName::EnumYen:
		ostr << std::left << std::setw(12) << "Yen" << std::setw(5) << object.wholeParts << std::setw(5) << object.fractParts << std::setw(5) << "Sen" << std::endl;
		break;
	case CurrencyName::EnumPeso:
		ostr << std::left << std::setw(12) << "Peso" << std::setw(5) << object.wholeParts << std::setw(5) << object.fractParts << std::setw(5) << "Centavo" << std::endl;
		break;
	case CurrencyName::EnumRuble:
		ostr << std::left << std::setw(12) << "Ruble" << std::setw(5) << object.wholeParts << std::setw(5) << object.fractParts << std::setw(5) << "Kopek" << std::endl;
		break;
	case CurrencyName::EnumBaht:
		ostr << std::left << std::setw(12) << "Baht" << std::setw(5) << object.wholeParts << std::setw(5) << object.fractParts << std::setw(5) << "Satang" << std::endl;
		break;
	}
	return ostr;
}


