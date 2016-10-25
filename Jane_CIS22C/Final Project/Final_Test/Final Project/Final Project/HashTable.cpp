/** @file HashTable.cpp */

#include "HashTable.h"


HashTable::HashTable() // Initializes HASHSIZE based on how many entries are in the file 1.0 ratio
{
	ifstream hex("Movielist.txt");
	string movietitle;
	string tictemp, montemp, ratemp;
	string opdate;
	int counter = 0;

	while (getline(hex, movietitle))
	{
		getline(hex, tictemp);
		getline(hex, montemp);
		getline(hex, opdate);
		getline(hex, ratemp);
		counter++;
	}
	hex.close();
	if (counter == 0)
	{
		HASHSIZE = defaultsize;
	}
	else
		HASHSIZE = counter;
}

int HashTable::findfilesize() // returns amount of entries in Movielist.txt
{
	ifstream hex("Movielist.txt");
	string movietitle;
	string tictemp, montemp, ratemp;
	string opdate;
	int counter = 0;

	while (getline(hex, movietitle))
	{
		getline(hex, tictemp);
		getline(hex, montemp);
		getline(hex, opdate);
		getline(hex, ratemp);
		counter++;
	}
	hex.close();
	return counter;
}

void HashTable::hashfromfile()
{
	int filesize;
	filesize = findfilesize();
	if (filesize == 0)
	{
		filesize = defaultsize;
	}
	//HASHSIZE = filesize;
	myTable.resize(filesize);
	for (int i = 0; i < filesize; i++)
	{
		myTable[i] = LinkedList<MovieData>();
	}

	string movietitle;
	long int ticsold;
	string tictemp, montemp, ratemp;
	long int money;
	string opdate;
	string::size_type sz;
	myenum rating;

	ifstream hex("Movielist.txt");
	while (getline(hex, movietitle))
	{

		getline(hex, tictemp);
		ticsold = stoi(tictemp, &sz);
		getline(hex, montemp);
		money = stoi(montemp, &sz);
		getline(hex, opdate);
		getline(hex, ratemp);
		rating = static_cast<myenum>(stoi(ratemp, &sz));
		MovieData mov(movietitle, ticsold, money, opdate, rating);
		insertItem(mov);
	}
	hex.close();
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
	try{
		searchItem(newItem.getMovieTitle(), 0);
	}
	catch (int e)
	{
		LinkedList<MovieData>* my_linkedlist = &(myTable[index]);
		Node<MovieData>* newNodePtr = new Node<MovieData>();
		newNodePtr->setItem(newItem);
		return my_linkedlist->insert(0, newNodePtr);
	}
	MovieData test = searchItem(newItem.getMovieTitle(), 0);
	if (checkduplicate(newItem, test))
	{
		cout << "Duplicate entry...removing";
		sleep_for(seconds(2));
		return 0;
	}

}

bool HashTable::checkduplicate(MovieData a, MovieData b)
{
	if (a.getMovieTitle() == b.getMovieTitle() && a.getticsold() == b.getticsold() && a.getmoney() == b.getmoney() && a.getopdate() == b.getopdate() && a.getrating() == b.getrating())
		return 1;
	return 0;
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
			curPtr = curPtr->getNext();
		}
	}
	// move the item to the front
	if (!curPtr)
	{
		return -1;
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
MovieData HashTable::searchItem(string itemKey, bool Trueforprint_Falsefornoprint)
{
	int index = searchItemInternal(itemKey);
	if (index != -1)
	{
		LinkedList<MovieData>* my_linkedlist = &(myTable[index]);
		MovieData my_moviedata = my_linkedlist->getEntry(0)->getItem();
		if (Trueforprint_Falsefornoprint)
		{
			cout + my_moviedata;
		}
		return my_moviedata;
	}
	else
	{
		//cout << "The item was not found." << endl;
		throw 20;
	}
}

//  Display the contents of the Hash Table sequence
void HashTable::printTable()
{
	int counter = 0;
	for (int i = 0; i < myTable.size(); i++)
	{
		LinkedList<MovieData>* my_linkedlist = &(myTable[i]);
		if (!my_linkedlist->isEmpty())
		{
			my_linkedlist->print();
		}
		else
		{
			counter++;
		}
	}
	//if (counter == HASHSIZE)
	if (counter == myTable.size())
	{
		cout << "List was empty...\n";
	}

}

void HashTable::printTablefile()
{
	remove("Movielist.txt"); // instead of clearing using space // removed so we can appened and not double data
	for (int i = 0; i < myTable.size(); i++)
	{
		LinkedList<MovieData>* my_linkedlist = &(myTable[i]);
		if (!my_linkedlist->isEmpty())
		{
			my_linkedlist->printfile();
		}
	}
}

void HashTable::printLoadFactor()
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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
			numberOfCollision++;
		}

	}
	double loadFactor;
	loadFactor = ((double)myTable.size() - (double)numberOfCollision) / (double)myTable.size();
	double averageNode;
	averageNode = 1.0 / loadFactor;
	cout.precision(4);
	cout << "Hash Table Size: ";
	SetConsoleTextAttribute(hConsole, 124);
	cout << myTable.size() << endl;
	SetConsoleTextAttribute(hConsole, 112);
	cout << "Number of collision: ";
	SetConsoleTextAttribute(hConsole, 124);
	cout << numberOfCollision++ << endl;
	SetConsoleTextAttribute(hConsole, 112);
	cout << "The size of longest linked list: ";
	SetConsoleTextAttribute(hConsole, 124);
	cout << length << endl;
	SetConsoleTextAttribute(hConsole, 112);
	cout << "The average number of nodes in Linked Lists: ";
	SetConsoleTextAttribute(hConsole, 124);
	cout << averageNode << endl;
	SetConsoleTextAttribute(hConsole, 112);
}

void HashTable::addmenue()
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	string movname, opdate;
	long int ticsold, money, ratemp;
	myenum rating;
	foshow hexmen;
	string choice;
	MovieData check;
	bool flag;
	do{
		flag = false;
		hexmen.drawhexmenue(0, 1, 0);
		cout << "Movie name's must be capatalized and dates must be in the form (yyyy/mm/dd). Do\nNOT use commas. Input rating as a number.\n";
		cout << "Movie name?: ";
		SetConsoleTextAttribute(hConsole, 124);
		if (!cin.good())
		{
			cin.clear();
			cin.ignore();
		}
		getline(cin, movname);
		SetConsoleTextAttribute(hConsole, 112);
		if (movname == "x")
			return;
		try{
			searchItem(movname, 0);
		}
		catch (int e)
		{
			flag = true;
		}
		if (flag)
		{
			cout << "Tickets sold?: ";
			SetConsoleTextAttribute(hConsole, 124);
			cin >> ticsold;
			string s = to_string(ticsold);
			if (s == "x")
				return;
			while (std::cin.fail()) {
				std::cout << "Error" << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cin >> ticsold;
			}
			SetConsoleTextAttribute(hConsole, 112);
			cout << "Money made?: ";
			SetConsoleTextAttribute(hConsole, 124);
			cin >> money;
			s = to_string(money);
			if (s == "x")
				return;
			while (std::cin.fail()) {
				std::cout << "Error" << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cin >> money;
			}
			SetConsoleTextAttribute(hConsole, 112);
			cout << "Opening date?: ";
			SetConsoleTextAttribute(hConsole, 124);
			std::cin.ignore(256, '\n');
			getline(cin, opdate);
			SetConsoleTextAttribute(hConsole, 112);
			if (opdate == "x")
				return;
			cout << "Rating?(Unrated = 0, Terrible = 1, Bad = 2, Mediocre = 3, Good = 4, Exellent = 5): ";
			int te;
			SetConsoleTextAttribute(hConsole, 124);
			cin >> te;
			s = to_string(te);
			if (s == "x")
				return;
			while (std::cin.fail()) {
				std::cout << "Error" << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cin >> te;
			}
			SetConsoleTextAttribute(hConsole, 112);
			if (te < 0 || te >5)
			{
				cout << "\nImpossible rating... giving it a 0 for unrated.";
				sleep_for(seconds(2));
				te = 0;
			}
			rating = static_cast<myenum>(te);
			MovieData temp(movname, ticsold, money, opdate, rating);
			insertItem(temp);
			cout << "\nAdd more data?";
			SetConsoleTextAttribute(hConsole, 124);
			cout << "(y / n)";
			SetConsoleTextAttribute(hConsole, 112);
			cout << ":";
			SetConsoleTextAttribute(hConsole, 124);
			std::cin.ignore(256, '\n');
			getline(cin, choice);
			while (!(choice == "y" || choice == "n"))
			{
				getline(cin, choice);
			}
			SetConsoleTextAttribute(hConsole, 112);
		}
		else
		{
			cout << "\nThat movie is already on the list...\n";
			system("PAUSE");
			return;
		}	
	} while (choice == "y");
}

void HashTable::removemenue()
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	foshow ram;
	string temp;
	string choice;
	ram.drawhexmenue(0, 1, 0);
	cout << "Enter the title of the movie you wish to remove(Must be capitol): ";
	SetConsoleTextAttribute(hConsole, 124);
	getline(cin, temp);
	cin.sync();
	SetConsoleTextAttribute(hConsole, 112);
	if (temp == "x")
		return;
	try{
		searchItem(temp, 1);
	}
	catch (int e)
	{
		cout << "Couldn't find the movie!\n";
		system("PAUSE");
		ram.drawhexmenue(1, 0, 0);
		return;
	}
	cout << "Are you sure?";
	SetConsoleTextAttribute(hConsole, 124);
	cout << "(y / n): ";
	while (!(choice == "y" || choice == "n"))
	{
		getline(cin, choice);
	}
	SetConsoleTextAttribute(hConsole, 112);

	if (choice == "y")
	{
		if (removeItem(temp))
		{
			cout << "\nSuccessfully removed!\n";
			system("PAUSE");
		}
		else {
			cout << "\Couldn't remove...";
			system("PAUSE");
		}
	}
	else
		return;
}

void HashTable::hashmenue()
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	foshow hexmen;
	bool problem = false;
	hashfromfile();


	string choice;
	do
	{
		hexmen.drawhexmenue(1, 1, 1);
		SetConsoleTextAttribute(hConsole, 124);
		getline(cin, choice);
		SetConsoleTextAttribute(hConsole, 112);
		if (choice == "a")
		{
			hexmen.drawhexmenue(0, 1, 0);
			addmenue();
		}
		else if (choice == "d")
			removemenue();
		else if (choice == "s")
		{

			do
			{
				hexmen.drawhexmenue(0, 1, 0);
				problem = false;
				string title;
				cout << "Movie title to seach for?: ";
				SetConsoleTextAttribute(hConsole, 124);
				getline(cin, title);
				SetConsoleTextAttribute(hConsole, 112);
				if (title == "x")
					break;
				MovieData temp;
				try{
					temp = searchItem(title, 0);
				}
				catch (int k)
				{
					cout << "Movie not in hash!\n";
					system("PAUSE");
					hexmen.drawhexmenue(1, 1, 0);
					problem = true;
				}
				if (problem != true)
				{
					hexmen.drawhexmenue(0, 0, 0);
					problem = false;
					cout << "Node was found!";
					sleep_for(nanoseconds(500000000));
					cout << "\nPrinting data...";
					sleep_for(nanoseconds(500000000));
					hexmen.drawhexmenue(0, 0, 0);
					cout << "Node was found!";
					cout << "\nPrinting data...Done!\n\n";
					cout + temp;
					cout << endl;
					system("PAUSE");
				}
				else
				{
					cout << "\n                                Try again...";
					sleep_for(seconds(1));
				}
			} while (problem == true);

		}
		else if (choice == "l")
		{
			hexmen.drawhexmenue(1, 0, 0);
			cout << endl << "THIS DATA IS LISTED IN HASH ORDER:" << endl << endl;
			printTable();
			system("PAUSE");
		}
		else if (choice == "i")
		{
			hexmen.drawhexmenue(1, 0, 0);
			cout << endl;
			printLoadFactor();
			system("PAUSE");
		}
	} while (choice != "x");
	printTablefile();
}