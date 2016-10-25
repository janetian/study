//
//  bstNode.cpp
//  FinalProject
//
//  Created by Xiaojing Liu on 11/10/15.
//  Copyright © 2015 Xiaojing Liu. All rights reserved.
//

#include "bstNode.hpp"
#include <iostream>

bstNode::bstNode()
{
	right = NULL;
	left = NULL;
	rating = Unrated;
}

bstNode::bstNode(string a, long int b, double c, string d, myenum e)
{
	movietitle = a;
	ticsold = b;
	money = c;
	opdate = d;
	rating = e;

}
string bstNode::getMovieTitle()
{
	return movietitle;
}

myenum bstNode::getRatingenum()
{
	return rating;
}

string bstNode::getRatingstring()
{
	if (rating == 0)
		return "Unrated";
	else if (rating == 1)
		return "Terrible";
	else if (rating == 2)
		return "Bad";
	else if (rating == 3)
		return "Mediocre";
	else if (rating == 4)
		return "Good";
	else if (rating == 5)
		return "Exellent";
}

bstNode* bstNode::getleft()
{
	return left;
}
bstNode* bstNode::getright()
{
	return right;
}
void bstNode::setleftptr(bstNode* leftPtr)
{
	left = leftPtr;
}

void bstNode::setrightptr(bstNode* rightPtr)
{
	right = rightPtr;
}

void bstNode::setleft(string a, long int b, double c, string d, myenum e)
{
	left = new bstNode(a, b, c, d, e);
}

void bstNode::setright(string a, long int b, double c, string d, myenum e)
{
	right = new bstNode(a, b, c, d, e);
}

void bstNode::setmovietitle(string a)
{
	movietitle = a;
}
void bstNode::setticsold(long int a)
{
	ticsold = a;
}
void bstNode::setmoneymade(long int a)
{
	money = a;
}
void bstNode::setopdate(string a)
{
	opdate = a;
}
void bstNode::setrating(myenum a)
{
	rating = a;
}

void bstNode::print()
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	
	cout << "Movie: ";
	SetConsoleTextAttribute(hConsole, 124);
	cout << movietitle << endl;
	SetConsoleTextAttribute(hConsole, 112);
	cout << "Tickets sold: " ;
	SetConsoleTextAttribute(hConsole, 124);
	cout << ticsold << endl;
	SetConsoleTextAttribute(hConsole, 112);
	cout << "Money earned: " ;
	SetConsoleTextAttribute(hConsole, 124);
	cout << money << endl;
	SetConsoleTextAttribute(hConsole, 112);
	cout << "Open date: ";
	SetConsoleTextAttribute(hConsole, 124);
	cout << opdate << endl;
	SetConsoleTextAttribute(hConsole, 112);
	cout << "Rating: ";
	SetConsoleTextAttribute(hConsole, 124);
	cout << rating << endl << endl;
	SetConsoleTextAttribute(hConsole, 112);
	
}

void bstNode::printfiletemp()
{
	ofstream temp("temp.txt", ios::app);
	temp << movietitle << endl;
	temp << ticsold << endl;
	temp << money << endl;
	temp << opdate << endl;
	temp << static_cast<int>(rating) << endl;
	temp.close();
}

void bstNode::printfilefinal()
{
	ofstream temp("Movielist.txt", ios::app);
	temp << movietitle << endl;
	temp << ticsold << endl;
	temp << money << endl;
	temp << opdate << endl;
	temp << static_cast<int>(rating) << endl;
	temp.close();
}

bstNode& bstNode::operator=(const bstNode& rightHandSide)
{
	movietitle = rightHandSide.movietitle;
	ticsold = rightHandSide.ticsold;
	money = rightHandSide.money;
	rating = rightHandSide.rating;
	opdate = rightHandSide.opdate;

	return *this;
}

ostream& operator<<(ostream& os, bstNode* dt)
{
	os << dt->movietitle << endl <<  dt->ticsold << endl
		<< dt->money << endl
		<<  dt->opdate << endl << dt->rating << endl;
	return os;
}
