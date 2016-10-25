/** @file MovieData.h */

#ifndef Movie_Data_H
#define Movie_Data_H

#include "Global.h"
#include <string>

using namespace std;


class MovieData
{
	string movietitle;
	long int ticsold;
	double money;
	string opdate;
	myenum rating; // terrible, bad, medicore, good, exellent
public:
	MovieData();
	MovieData(string movietitle, long int tickets_sold, double money_made, myenum unrated_terrible_bad_medicore_good_exellent, string opening_date);
	string getMovieTitle();
	friend ostream & operator<< (std::ostream & ostr, const MovieData & object);
};


#endif