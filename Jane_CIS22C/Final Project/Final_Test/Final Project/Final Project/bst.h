

#ifndef bst_h
#define bst_h

#include "bstNode.hpp"
#include "Global.h"
#include "foshow.h"
#include <deque>
#include <vector>


class bst
{
	bstNode* rootptr; // points to the top of the tree

	int searcheff; // number of steps to search for a data 
	int sorteff; // number of steps to reorganize all data by different value
	int deleteeff; // number of steps to clear all data from tree
	int removeeff; // number of steps to remove a single data point

	void reprin(bstNode*); // recurssive function for printing data from tree to output screen
	void reprinfile(bstNode*, bool final_1_temp_0);// recurssive function for printing data from tree to movietitle.txt or temp.txt
	void removenodeprivate(string key, bstNode* parent); // private helper of removenode
	void removerootmatch();// private helper of removenode
	string findsmallestprivate(bstNode* ptr);// private helper of removenode
	void removematch(bstNode* parent, bstNode* match, bool left);// private helper of removenode

public:
	//Constructors
	bst();
	~bst();
	//Mutators
	void addnode(); // Add menue
	void addnode(string movietitle, long int tickets_sold, long int money_made, // last parameter used for organizing by name or date
		string opening_date, myenum unrated_terrible_bad_medicore_good_exellent, 
		string how_you_want_organ, bool keep_track_of_counter);
	void deleteall(bstNode* rootptr, bool keeptrack); // recurssive function that deletes all nodes (Does not set rootptr to NULL)
	void organizeby(string how_you_want_organ_irrelevant_if_bool_is_1,int beforetreeprint1_or_Not0_counter2); // Reorganized data in memory tree
	//bstNode* findNode(bstNode*, string&);
	bstNode* search(string, bool keeptrack); // search for key
	void removemenue(); // removenode menue
	void removenode(string key); // removes a node by its key
	void bstmenue(); // opens bst menue
	string findbesttree(); //used by organizeby to find how to organize tree for smallest height
	string findsmallest(); // calls findsmallestprivate and returns smallest value in bst
	bool checkdoubleentry(bstNode*, string movietitle); // checks if your trying to add a duplicate key
	int maxHeight(bstNode *p); // gets the height of the tree

	//Functions to print out tree to look like a tree
	void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<bstNode*>& nodesQueue, ostream& out);
	void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<bstNode*>& nodesQueue, ostream& out);
	void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<bstNode*>& nodesQueue, ostream& out);
	void printPretty(bstNode *root, int level, int indentSpace, ostream& out);

	//Accessors
	void printall(string name_date); // function that prints search tree to screen in-order // choose "name" or "date" for how you want it organized
	void printtofile(bool final_or_temp);// function that prints search tree to appropriate file in-order // choose "name" or "date" for how you want it organized
};

#endif