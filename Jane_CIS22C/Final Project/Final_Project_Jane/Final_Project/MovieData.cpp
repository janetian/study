/** @file MovieData.cpp */

#include "MovieData.h"

MovieData::MovieData()
{
	movietitle = "none";
	ticsold = 0;
	money = 0;
	rating = unrated;
	opdate = "none";
}

MovieData::MovieData(string a, long int b, double c, myenum d, string e)
{
	movietitle = a;
	ticsold = b;
	money = c;
	rating = d;
	opdate = e;
}

string MovieData::getMovieTitle()
{
	return movietitle;
}

ostream & operator<< (std::ostream & ostr, const MovieData & object)
{
	ostr << "Movie Title:  " << object.movietitle << endl;
	ostr << "Ticket Sold:  " << object.ticsold << endl;
	ostr << "Profit:       " << object.money << endl;
	ostr << "Operate Date: " << object.opdate << endl;
	ostr << "Rating:       " << object.rating << endl;
	return ostr;
}
