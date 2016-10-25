//
//  bstNode.hpp
//  FinalProject
//
//  Created by Xiaojing Liu on 11/10/15.
//  Copyright © 2015 Xiaojing Liu. All rights reserved.
//

#ifndef bstNode_hpp
#define bstNode_hpp


#include "Global.h"
#include <string>
using namespace std;


class bstNode
{
	bstNode* right;
	bstNode* left;
	string movietitle;
	long int ticsold;
	long int money;
	string opdate;
	myenum rating; // terrible, bad, medicore, good, exellent
public:
	//constructors
	bstNode();
	bstNode(string movietitle, long int tickets_sold, double money_made, string opening_date, myenum unrated_terrible_bad_medicore_good_exellent);
	~bstNode(){}
	//accessors
	string getMovieTitle();
	long int getTicsold(){ return ticsold; }
	double getMoney(){ return money; }
	string getOpdate(){ return opdate; }
	myenum getRatingenum();
	string getRatingstring();
	bstNode* getleft();
	bstNode* getright();
	//mutators
	void setmovietitle(string);
	void setticsold(long int);
	void setmoneymade(long int);
	void setopdate(string);
	void setrating(myenum);
	void setleft(string movietitle, long int tickets_sold, double money_made, string opening_date, myenum unrated_terrible_bad_medicore_good_exellent);
	void setright(string movietitle, long int tickets_sold, double money_made, string opening_date, myenum unrated_terrible_bad_medicore_good_exellent);
	void setleftptr(bstNode*);
	void setrightptr(bstNode*);
	//
	void print();
	void printfiletemp();
	void printfilefinal();// must clear movielist.txt before calling this because it's reccursive
	bstNode& operator=(const bstNode& rightHandSide);
	friend ostream& operator<<(ostream& os, bstNode* dt);

};



#endif /* bstNode_hpp */