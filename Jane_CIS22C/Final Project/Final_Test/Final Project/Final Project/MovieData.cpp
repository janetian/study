/** @file MovieData.cpp */

#include "MovieData.h"

MovieData::MovieData()
{
	movietitle = "none";
	ticsold = 0;
	money = 0;
	rating = Unrated;
	opdate = "none";
}

MovieData::MovieData(string a, long int b, double c,string d, myenum e)
{
	movietitle = a;
	ticsold = b;
	money = c;
	opdate = d;
	rating = e;
}

string MovieData::getMovieTitle()
{
	return movietitle;
}

ostream & operator<< (std::ostream & ostr, const MovieData & object)
{
	ostr << object.movietitle << endl;
	ostr << object.ticsold << endl;
	ostr <<  object.money << endl;
	ostr << object.opdate << endl;
	ostr << object.rating << endl;
	return ostr;
}

ostream & operator+ (std::ostream & ostr, const MovieData & object)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ostr << "Movie Title:  "; 
	SetConsoleTextAttribute(hConsole, 124);
	cout << object.movietitle << endl;
	SetConsoleTextAttribute(hConsole, 112);
	ostr << "Ticket Sold:  ";
	SetConsoleTextAttribute(hConsole, 124);
	cout << object.ticsold << endl;
	SetConsoleTextAttribute(hConsole, 112);
	ostr << "Profit:       ";
	SetConsoleTextAttribute(hConsole, 124);
	cout << object.money << endl;
	SetConsoleTextAttribute(hConsole, 112);
	ostr << "Opening Date: ";
	SetConsoleTextAttribute(hConsole, 124);
	cout << object.opdate << endl;
	SetConsoleTextAttribute(hConsole, 112);
	ostr << "Rating:       ";
	SetConsoleTextAttribute(hConsole, 124);
	cout << object.rating << endl;
	SetConsoleTextAttribute(hConsole, 112);
	return ostr;
}

void MovieData::printnotoverload(MovieData* x)
{
	cout << "Movie Title:  " << x->movietitle << endl;
	cout << "Ticket Sold:  " << x->ticsold << endl;
	cout << "Profit:       " << x->money << endl;
	cout << "Opening Date: " << x->opdate << endl;
	cout << "Rating:       " << x->rating << endl;
	
}

long int MovieData::getticsold()
{
	return ticsold;
}
double MovieData::getmoney()
{
	return money;
}
string MovieData::getopdate()
{
	return opdate;
}
myenum MovieData::getrating()
{
	return rating;
}