/** @file Main.cpp */

/*
CIS 22C
Lab4 - Binary Search
Pre :
Post:
Return:
Jie Tian and Xiaojing Liu
*/

#include <iostream>
#include <fstream>
#include <string>
#include "BSTbyName.h"
#include "BSTbyBirthday.h"


int main()
{
	BSTbyName<Record> myBST1;
	BSTbyBirthday<Record> myBST2;

	// Read the data to create BST for the database by name and birthday 
	ifstream input;
	input.open("Records.txt");
	string name, birthday;
	while (!input.eof())
	{
		getline(input, name);
		getline(input, birthday);
		if ((name != "") && (birthday != ""))
		{
			// construct record
			Record myRecord(name, birthday);

			// insert record
			myBST1.insert(myRecord);        // insert by name
			myBST2.insert(myRecord);        // insert by birthday
		}
	}
	input.close();

	ofstream output;
	// Write out the listing of everyone by name using a post-order traversal mechanism
	output.open("RecordsbyName.txt");
	cout << "Post-order traversal by name:" << endl;
	myBST1.printPostorder(output);
	output.close();

	// Write out the listing of everyone by birthday using a breadth-first traversal mechanism
	output.open("RecordsbyBirthday.txt");
	cout << "Breadth-first traversal by birthday" << endl;
	myBST2.printBredth(output);
	output.close();

	system("pause");
	return 0;
}

