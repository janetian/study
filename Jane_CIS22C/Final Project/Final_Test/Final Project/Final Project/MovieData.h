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
	long int money;
	string opdate;
	myenum rating; // terrible, bad, medicore, good, exellent
public:
	MovieData();
	MovieData(string movietitle, long int tickets_sold, double money_made, string opening_date, myenum unrated_terrible_bad_medicore_good_exellent);
	string getMovieTitle();
	void printnotoverload(MovieData*);
	friend ostream & operator+ (std::ostream & ostr, const MovieData & object); //used to print data to output
	friend ostream & operator<< (std::ostream & ostr, const MovieData & object); // used to print data to file

	long int getticsold();
	double getmoney();
	string getopdate();
	myenum getrating();


};


#endif