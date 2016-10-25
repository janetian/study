/** @file Main.cpp */

#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.h"


int main()
{
	int numberOfMovie;
	cout << "numberOfMovie:" << endl;
	cin >> numberOfMovie;
	HashTable myHashTable(numberOfMovie);

	//HashTable myHashTable(10);
	MovieData newMovie("Frozen", 2000, 58.60, good, "2009/05/07");
	MovieData newMovie1("Mission Impossible", 1000, 8.60, bad, "2010/05/07");
	MovieData newMovie2("Fozenr", 2000, 58.60, good, "2009/05/07");

	cout << "Insert" << endl;
	myHashTable.insertItem(newMovie);
	myHashTable.insertItem(newMovie1);
	myHashTable.insertItem(newMovie2);
	myHashTable.printTable();

	//cout << "Remove a movie" << endl;
	//myHashTable.removeItem("Frozen");
	//myHashTable.printTable();

	//cout << "Search a item" << endl;
	//myHashTable.searchItem("Frozen");

	myHashTable.printLoadFactor();

	system("pause");
	return 0;
}
