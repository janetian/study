/** @file HashTable.h */

#ifndef _HASH_TABLE
#define _HASH_TABLE

#include <vector>
#include "MovieData.h"
#include "LinkedList.h"

const int DEFAULT_SIZE = 101; // default size of Hash table


class HashTable
{
private:
	vector<LinkedList<MovieData> > myTable;
	// search an item and move it to the front of the list if found
	int searchItemInternal(string item);

public:
	// construct
	HashTable();
	HashTable(int size);

	// Destruct
	~HashTable();

	//get the key for the hash table
	string getKey(MovieData& item);

	// hash function
	int getHashIndex(string itemKey);

	// Add an item to the Hash Table.
	bool insertItem(MovieData newItem);

	// Delete an Item from the Hash Table.
	bool removeItem(string itemKey);

	// Find an item from the Hash Table
	MovieData searchItem(string itemKey);

	// Display the contents of the Hash Table sequence
	void printTable();

	void printLoadFactor();
};

#endif