/** @file HashTable.cpp */

#include "HashTable.h"


HashTable::HashTable()
{
	myTable.resize(DEFAULT_SIZE);
	for (int i = 0; i < DEFAULT_SIZE; i++)
	{
		myTable[i] = LinkedList<MovieData>();
	}
}

HashTable::HashTable(int size)
{
	myTable.resize(size);
	for (int i = 0; i < size; i++)
	{
		myTable[i] = LinkedList<MovieData>();
	}

}

// Destruct
HashTable::~HashTable()
{
	myTable.clear();
}

//get the key for the hash table
string HashTable::getKey(MovieData& item)
{
	string key = item.getMovieTitle();
	return key;
}

// hash function to get hash index
int HashTable::getHashIndex(string itemKey)
{
	int index = 0;
	for (int i = 0; i < itemKey.length(); i++)
	{
		index += (int)itemKey[i];
	}
	index = index % myTable.size();
	return index;
}

// Add an item to the Hash Table.
bool HashTable::insertItem(MovieData newItem)
{
	string itemKey = getKey(newItem);
	int index = getHashIndex(itemKey);
	LinkedList<MovieData>* my_linkedlist = &(myTable[index]);
	Node<MovieData>* newNodePtr = new Node<MovieData>(); 
	newNodePtr->setItem(newItem);
	return my_linkedlist->insert(0, newNodePtr);
}

// search an item and move it to the front of the list
int HashTable::searchItemInternal(string itemKey)
{
	// find the index
	int index = getHashIndex(itemKey);
	LinkedList<MovieData>* my_linkedlist = &(myTable[index]);
	// find the item
	Node<MovieData>* curPtr = my_linkedlist->getHeadPtr();
	Node<MovieData>* prePtr = nullptr;
	while (curPtr)
	{
		if (curPtr->getItem().getMovieTitle() == itemKey)
		{
			break;
		}
		else
		{
			prePtr = curPtr;
			//curPtr->setNext(curPtr->getNext());
			curPtr = curPtr->getNext();
		}
	}
	// move the item to the front
	if (!curPtr)
	{
		return -1;   // not found
	}
	else
	{
		if (curPtr != my_linkedlist->getHeadPtr())
		{
			prePtr->setNext(curPtr->getNext());
			curPtr->setNext(my_linkedlist->getHeadPtr());
			my_linkedlist->setHeadPtr(curPtr);
		}
		return index;
	}
}

// Delete an Item from the Hash Table.
bool HashTable::removeItem(string itemKey)
{
	int index = searchItemInternal(itemKey);
	if (index != -1)
	{
		LinkedList<MovieData>* my_linkedlist = &(myTable[index]);
		my_linkedlist->remove(0);
		return true;
	}
	else
	{
		cout << "The item does not found." << endl;
		return false;
	}
}

// Find an item from the Hash Table
MovieData HashTable::searchItem(string itemKey)
{
	int index = searchItemInternal(itemKey);
	if (index != -1)
	{
		LinkedList<MovieData>* my_linkedlist = &(myTable[index]);
		MovieData my_moviedata = my_linkedlist->getEntry(0)->getItem();
		cout << my_moviedata;
		return my_moviedata;
	}
	else
	{
		cout << "The item does not found." << endl;
		return MovieData();
	}
}

//  Display the contents of the Hash Table sequence
void HashTable::printTable()
{
	for (int i = 0; i < myTable.size(); i++)
	{
		LinkedList<MovieData>* my_linkedlist = &(myTable[i]);
		if (!my_linkedlist->isEmpty())
		{
			my_linkedlist->print();
		}
	}
}


void HashTable::printLoadFactor()
{
	int numberOfCollision = 0;
	int length = 0; 
	int count = 0;
	for (int i = 0; i < myTable.size(); i++)
	{
		LinkedList<MovieData>* my_linkedlist = &(myTable[i]);
		if (!my_linkedlist->isEmpty())
		{
			if (my_linkedlist->getLength() > length)
			{
				length = my_linkedlist->getLength();
				count++;
			}
		}
		else
		{
			numberOfCollision++;;
		}

	}
	double loadFactor;
	loadFactor = ((double)myTable.size() - (double)numberOfCollision) / (double)myTable.size();
	double averageNode;
	(myTable.size() - numberOfCollision);
	averageNode = 1.0 / loadFactor;
	cout.precision(4);
	cout << "Hash Table Size: " << myTable.size() << endl;
	cout << "Number of collision: " << numberOfCollision << endl;
	cout << "Load Factor: " << loadFactor * 100 << "%" << endl;
	cout << "The size of longest linked list: " << length << endl;
	cout << "The average number of nodes in Linked Lists: " << averageNode << endl;
	
}


