//This program uses BST and Hashtables to hold movie data
//Brandon, Jie, David, Jane

#include <iostream>
#include "bstNode.hpp"
#include "bst.h"
#include "foshow.h"
#include "HashTable.h"
#include "Global.h"



//Overloads enum cout to output enum name
ostream& operator<<(std::ostream& out, const myenum value);

int main()
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	foshow hot;
	string choice;
	hot.summonthegraphics();
	hot.testit();
	hot.titlescreen();
	bst kind;
	bool sound=hot.s();
	do{
		
		hot.drawmainmenue();
		SetConsoleTextAttribute(hConsole, 124);
		getline(cin, choice);
		SetConsoleTextAttribute(hConsole, 112);
		if (choice == "bst")
			kind.bstmenue();
		else if (choice == "hash")
		{
			HashTable* help = new HashTable;
			help->hashmenue();
			delete help;
			help = NULL;
		}
		else if (choice == "m")
		{
		sound = hot.afterstartmusicmanage(sound);
		}
		else if (choice == "x")
		{
		}
	} while (choice != "x");
	remove("temp.txt");
}

ostream& operator<<(std::ostream& out, const myenum value)
{
	const char* s = 0;
#define PROCESS_VAL(p) case(p): s = #p; break;
	switch (value){
		PROCESS_VAL(Unrated);
		PROCESS_VAL(Terrible);
		PROCESS_VAL(Bad);
		PROCESS_VAL(Mediocre);
		PROCESS_VAL(Good);
		PROCESS_VAL(Exellent);
	}
#undef PROCESS_VAL

	return out << s;
}

