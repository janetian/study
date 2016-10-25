/** @file Record.cpp */

#include "Record.h"

Record::Record()
{
	name = "None";
	birthday = "None";
}

Record::Record(string n, string b)
{
	name = n;
	birthday = b;
}

string Record::getName()
{
	return name;
}

string Record::getBirthday()
{
	return birthday;
}

void Record::setName(string n)
{
	name = n;
}

void Record::setBirthday(string b)
{
	birthday = b;
}

bool Record::operator< (const Record & right)
{
	if (name < right.name)
	{
		return true;
	}	
	else
	{
		return false;
	}	
}

ostream & operator<< (std::ostream & ostr, const Record & object)
{
	ostr << "Name:      " << object.name << endl;
	ostr << "Birhtday:  " << object.birthday << endl;
	return ostr;
}
