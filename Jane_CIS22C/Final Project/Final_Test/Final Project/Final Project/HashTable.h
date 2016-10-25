/** @file HashTable.h */

#ifndef _HASH_TABLE
#define _HASH_TABLE

#include <vector>
#include "MovieData.h"
#include "LinkedList.h"
#include "foshow.h"



class HashTable
{
private:
	vector<LinkedList<MovieData> > myTable;
	int HASHSIZE;
	// search an item and move it to the front of the list if found
	int searchItemInternal(string item);
public:
	// construct
	HashTable();

	// Destruct
	~HashTable();

	void printLoadFactor();

	void hashmenue();

	void addmenue();

	void removemenue();

	bool checkduplicate(MovieData,MovieData);

	//get the key for the hash table
	string getKey(MovieData& item);

	// hash function
	int getHashIndex(string itemKey);

	void hashfromfile();

	// Add an item to the Hash Table.
	bool insertItem(MovieData newItem);

	int findfilesize();

	// Delete an Item from the Hash Table.
	bool removeItem(string itemKey);

	// Find an item from the Hash Table
	MovieData searchItem(string itemKey, bool Trueforprintalso_Falseforprintnothing);

	// Display the contents of the Hash Table sequence
	void printTable();

	void printTablefile();
};

#endif