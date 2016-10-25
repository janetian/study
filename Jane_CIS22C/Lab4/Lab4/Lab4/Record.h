/** @file Record.h */

#ifndef _RECORD
#define _RECORD

#include<iostream>
#include<string>

using namespace std;

class Record
{
private:
	string name;
	string birthday;
public:
	Record();
	Record(string name, string birthday);
	string getName();
	string getBirthday();
	void setName(string name);
	void setBirthday(string birthday);
	bool operator< (const Record & right);
	friend ostream & operator<< (std::ostream & ostr, const Record & object);
};

#endif