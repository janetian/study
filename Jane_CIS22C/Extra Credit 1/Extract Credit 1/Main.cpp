/** @file Main.cpp */
/* 
CIS 22C
This algorithm add a few toys to the ToyBox and a few magic tricks to the MagicBox
Pre : 
Post:
Return: 
Jie Tian and Xiaojing Liu
*/


#include <iostream>
#include <string>
#include "BoxInterface.h"
#include "PlainBox.h"
#include "ToyBox.h"
#include "MagicBox.h"


using namespace std;

int main()
{
	// create an instance of a ToyBox
	BoxInterface<string>* mybox1 = new ToyBox<string>(RED);

	// create an instance of a MagicBox
	BoxInterface<string>* mybox2 = new MagicBox<string>();

	// Add a few toys to the ToyBox
	mybox1->setItem("toy box's first item");
	mybox1->setItem("toy box's second item");

	// Add a few magic tricks to the MagicBox
	mybox2->setItem("magic box's first item");
	mybox2->setItem("magic box's second item");

	cout << mybox1->getItem() <<endl;
	cout << mybox2->getItem() <<endl;

	// release memory
	delete mybox1;
	delete mybox2;

	return 0;
}