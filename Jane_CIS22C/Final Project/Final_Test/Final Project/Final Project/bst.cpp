#include "bst.h"


void bst::bstmenue() 
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		string choice;
		bool exit = false;
		foshow bstmen;
		organizeby(findbesttree(), 0); // Used to put the smallest tree in memory only! : Reads in from movie list addnoded by the smallest tree option
		organizeby("irrelevant", 1);// organize by bool set to 1 : This outputs current tree in memory to temp.txt, deletes current tree, and then reads it back from temp in movie title order
		printtofile(1);
		do
		{
			bstmen.drawbstmenue(1,1,1);
			SetConsoleTextAttribute(hConsole, 124);
			getline(cin, choice);
			SetConsoleTextAttribute(hConsole, 112);
			if (choice == "a")
			{
				addnode();
				organizeby("irrelevant", 1);
				printtofile(1);
			}
			else if (choice == "d")
			{
				organizeby(findbesttree(), 0); //Fake bst balance : Almost randomizing so that you get a sort of balanced tree in alphabetical order
				organizeby("irrelevant", 1);
				removemenue();
				organizeby("irrelevant", 1);
				printtofile(1);
			}
			else if (choice == "s")
			{
				string title;
				organizeby(findbesttree(), 0); //Fake bst balance : Almost randomizing so that you get a sort of balanced tree in alphabetical order
				organizeby("irrelevant", 1);
				bool problem;
				do{
					problem = false;
					bstmen.drawbstmenue(0, 1, 0);
					cout << "Movie title to seach for?: ";
					SetConsoleTextAttribute(hConsole, 124);
					getline(cin, title);
					SetConsoleTextAttribute(hConsole, 112);
					if (title == "x")
					{
						break;
					}
					searcheff = 0; // set to 0 so we can count number of iterations done during the search
					bstNode* temp = search(title, 0);
					if (temp != NULL)
					{
						bstmen.drawbstmenue(0, 0, 0);
						cout << "Node was found!";
						sleep_for(nanoseconds(500000000));
						cout << "\nPrinting data...";
						sleep_for(nanoseconds(500000000));
						bstmen.drawbstmenue(0, 0, 0);
						cout << "Node was found!";
						cout << "\nPrinting data...Done!\n\n";
						temp->print();
						cout << endl;
						system("PAUSE");
					}
					else
					{
						cout << "Movie not in the list...\n";
						system("PAUSE");
						problem = true;
					}
				} while (problem == true);
			}
			else if (choice == "k")
			{
				organizeby("irrelevant", 1);
				printtofile(1);
				bool flag;
				do{
					flag = false;
					bstmen.drawbstmenue(0,1,0);
					cout << "\nHow do you want it sorted?(";
					SetConsoleTextAttribute(hConsole, 124);
					cout << "\"movie title\" \"opening date\" \"tickets sold\" \"cash made\" \"rating\"";
					SetConsoleTextAttribute(hConsole, 112);
					cout << "):\n";
					SetConsoleTextAttribute(hConsole, 124);
					cout << "                                   ";
					getline(cin, choice);
					SetConsoleTextAttribute(hConsole, 112);
					if (choice == "x")
						break;
					bstmen.drawbstmenue(0, 0, 0);
					if (choice == "movie title")
					{
						printall("movietitle");
						system("PAUSE");
					}
					else if (choice == "opening date")
					{
						printall("opdate");
						system("PAUSE");
					}
					else if (choice == "tickets sold")
					{
						printall("ticsold");
						system("PAUSE");
					}
					else if (choice == "cash made")
					{
						printall("money");
						system("PAUSE");
					}
					else if (choice == "rating")
					{
						printall("rating");
						system("PAUSE");
					}
					else{
						cout << "\nError: couldn't understand input...\nTry again...\n";
						system("PAUSE");
						flag = true;
					}	
				} while (flag == true);
			}
			else if (choice == "t")
			{
				organizeby(findbesttree(),0); //Fake bst balance : Almost randomizing so that you get a sort of balanced tree in alphabetical order
				organizeby("irrelevant",1);
				ofstream fout("Tree.txt");
				bstmen.drawbstmenue(0, 0, 0);
				printPretty(rootptr, 1, 0, fout); // Printing tree to file
				printPretty(rootptr, 1, 0, cout); // Printing tree to output
				fout.close();
				cout << "Output printed to Resources\\Tree.txt...\n";
				system("PAUSE");
			}
			else if (choice == "e")
			{
				if (rootptr != NULL)
				{
					sorteff = 0;
					deleteeff = 0;
					organizeby(findbesttree(),0); // organizeby does not print anything to file:  Used to put the smallest tree in memory only!
					bstmen.drawbstmenue(0, 0, 0);
					cout << "The heigh of this tree is: ";
					SetConsoleTextAttribute(hConsole, 124);
					cout << maxHeight(rootptr)<<endl;
					SetConsoleTextAttribute(hConsole, 112);
					cout << "The # of steps for the last thing you removed: ";
					SetConsoleTextAttribute(hConsole, 124);
					cout << removeeff << endl;
					SetConsoleTextAttribute(hConsole, 112);
					cout << "The # of steps for the last thing you searched: ";
					SetConsoleTextAttribute(hConsole, 124);
					cout << searcheff << endl;
					SetConsoleTextAttribute(hConsole, 112);;
					organizeby("movietitle", 2);
					cout << "The # of steps needed to delete all nodes in tree: ";
					SetConsoleTextAttribute(hConsole, 124);
					cout << deleteeff << endl;
					SetConsoleTextAttribute(hConsole, 112);
					cout << "\n    (INCLUDES DELETING ALL PREVIOUS NODES):"<<endl;
					cout << "        The # of steps for reorganizing tree by \"Movie Title\": ";
					SetConsoleTextAttribute(hConsole, 124);
					cout << sorteff + deleteeff << endl;
					organizeby("rating", 2);
					SetConsoleTextAttribute(hConsole, 112);
					cout << "                                                \"Rating\": ";
					SetConsoleTextAttribute(hConsole, 124);
					cout << sorteff + deleteeff << endl;
					organizeby("opdate", 2);
					SetConsoleTextAttribute(hConsole, 112);
					cout << "                                                \"Opening Date\": ";
					SetConsoleTextAttribute(hConsole, 124);
					cout << sorteff + deleteeff << endl;
					organizeby("money", 2);
					SetConsoleTextAttribute(hConsole, 112);
					cout << "                                                \"Money Made\": ";
					SetConsoleTextAttribute(hConsole, 124);
					cout << sorteff + deleteeff << endl;
					organizeby("ticsold", 2);
					SetConsoleTextAttribute(hConsole, 112);
					cout << "                                                \"Tickets Sold\": ";
					SetConsoleTextAttribute(hConsole, 124);
					cout << sorteff + deleteeff << endl;
					SetConsoleTextAttribute(hConsole, 112);
					organizeby(findbesttree(), 0); 
					organizeby("irrelevant", 1);
					cout << endl;
					system("PAUSE");
				}
				else{
					bstmen.drawbstmenue(0, 0, 0);
					cout << "List is empty!";
					sleep_for(seconds(2));
				}
			}
		} while (choice != "x");
		organizeby("irrelevant", 1);
		printtofile(1);
}

string bst::findbesttree()
{
	remove("temp.txt");
	int arr[5];
	organizeby("movietitle",0);
	arr[0] = maxHeight(rootptr);
	organizeby("ticsold",0);
	arr[1] = maxHeight(rootptr);
	organizeby("money",0);
	arr[2] = maxHeight(rootptr);
	organizeby("opdate",0);
	arr[3] = maxHeight(rootptr);
	organizeby("rating",0);
	arr[4] = maxHeight(rootptr);
	int counter = 0;
	int smallest = arr[0];
	for (int i =0; i < 5; i++)
	{
		if (arr[i] < smallest)
		{
			smallest = arr[i];
			counter = i;
		}		
	}
	if (counter == 0)
		return "movietitle";
	if (counter == 1)
		return "ticsold";
	if (counter == 2)
		return "money";
	if (counter == 3)
		return "opdate";
	if (counter == 4)
		return "rating";
}

bst::bst() // Automatically reads in from the byname.txt (the bydate.txt has the same info in different order)
{
	foshow lak;
	system("CLS");
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	string movietitle;
	long int ticsold;
	string tictemp, montemp, ratemp;
	long int money;
	string opdate;
	string::size_type sz;
	myenum rating; // terrible, bad, medicore, good, exellent

	ifstream list("Movielist.txt");
	if (!list)
	{
		lak.redrawtitle();
		SetConsoleTextAttribute(hConsole, 116);
		cout << "Can't find the file Movielist.txt\nCreating new txt file...";
		ofstream temp("Movielist.txt");
		temp.close();
		sleep_for(nanoseconds(500000000));
		cout << "done\n";
		sleep_for(seconds(1));
		system("CLS");
		SetConsoleTextAttribute(hConsole, 112);
	}
	else
	{
		lak.redrawtitle();
		SetConsoleTextAttribute(hConsole, 116);
		cout << "\n       Movielist.txt found...";
		sleep_for(seconds(1));
		cout << "\n       Loading in data...\n\n";
		sleep_for(nanoseconds(200000000));
		SetConsoleTextAttribute(hConsole, 112);
		sorteff = 0; // set to 0 so it can start counting steps needed
		while (getline(list, movietitle))
		{
			cout << "              Movie Title: " << movietitle << endl;
		
			getline(list, tictemp);
			ticsold = stoi(tictemp, &sz);
			cout << "              Tickets Sold: " << ticsold << endl;
		
			getline(list, montemp);
			money = stoi(montemp, &sz);
			cout << "              Global Gross: $" << money << endl;
		
			getline(list, opdate);
			cout << "              Release Date: " << opdate << endl;
		
			getline(list, ratemp);
			rating = static_cast<myenum>(stoi(ratemp, &sz));
			cout << "              Rating: " << rating << endl;
			addnode(movietitle, ticsold, money, opdate, rating, "movietitle",1);
			sleep_for(nanoseconds(10000000));
			system("CLS");
			lak.redrawtitle();
			SetConsoleTextAttribute(hConsole, 116);
			cout << "\n       Movielist.txt found...\n       Loading in data...\n\n";
			SetConsoleTextAttribute(hConsole, 112);
		}
		system("CLS");
		list.close();
		lak.redrawtitle();
		SetConsoleTextAttribute(hConsole, 116);
		cout << "\n       Movielist.txt found...\n       Loading in data...done!";
		sleep_for(seconds(1));
		system("CLS");
		SetConsoleTextAttribute(hConsole, 112);
	}

}   // end default constructor




bst::~bst()
{
	deleteall(rootptr,0);
}




int bst::maxHeight(bstNode *p) 
{
	if (!p) return 0;
	int leftHeight = maxHeight(p->getleft());
	int rightHeight = maxHeight(p->getright());
	return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

/*
string bst::intToString(int val) 
{
	string s = std::to_string(val);
	return s;
}
*/

// Print the arm branches (eg, /    \ ) on a line
void bst::printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<bstNode*>& nodesQueue, ostream& out) 
{
	deque<bstNode*>::const_iterator iter = nodesQueue.begin();
	for (int i = 0; i < nodesInThisLevel / 2; i++) {
		out << ((i == 0) ? setw(startLen - 1) : setw(nodeSpaceLen - 2)) << "" << ((*iter++) ? "/" : " ");
		out << setw(2 * branchLen + 2) << "" << ((*iter++) ? "\\" : " ");
	}
	out << endl;
}


// Print the branches and node (eg, ___10___ )
void bst::printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<bstNode*>& nodesQueue, ostream& out) 
{
	deque<bstNode*>::const_iterator iter = nodesQueue.begin();
	for (int i = 0; i < nodesInThisLevel; i++, iter++) {
		out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->getleft()) ? setfill('_') : setfill(' '));
		out << setw(branchLen + 2) << ((*iter) ? (*iter)->getMovieTitle() : "");
		out << ((*iter && (*iter)->getright()) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
	}
	out << endl;
}



void bst::printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<bstNode*>& nodesQueue, ostream& out) 
{
	deque<bstNode*>::const_iterator iter = nodesQueue.begin();
	for (int i = 0; i < nodesInThisLevel; i++, iter++) {
		out << ((i == 0) ? setw(indentSpace + 2) : setw(2 * level + 2)) << ((*iter) ? (*iter)->getMovieTitle() : "");
	}
	out << endl;
}



void bst::printPretty(bstNode *root, int level, int indentSpace, ostream& out)
{
	int h = maxHeight(root);
	int nodesInThisLevel = 1;

	int branchLen = 2 * ((int)pow(2.0, h) - 1) - (3 - level)*(int)pow(2.0, h - 1);  // eq of the length of branch for each node of each level
	
	
	int nodeSpaceLen = 2 + (level + 1)*(int)pow(2.0, h);  // distance between left neighbor node's right arm and right neighbor node's left arm
	int startLen = branchLen + (3 - level) + indentSpace;  // starting space to the first node to print of each level (for the left most node of each level only)

	deque<bstNode*> nodesQueue;
	nodesQueue.push_back(root);
	for (int r = 1; r < h; r++) {
		printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
		branchLen = branchLen / 2 - 1;
		nodeSpaceLen = nodeSpaceLen / 2 + 1;
		startLen = branchLen + (3 - level) + indentSpace;
		printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);

		for (int i = 0; i < nodesInThisLevel; i++) {
			bstNode *currNode = nodesQueue.front();
			nodesQueue.pop_front();
			if (currNode) {
				nodesQueue.push_back(currNode->getleft());
				nodesQueue.push_back(currNode->getright());
			}
			else {
				nodesQueue.push_back(NULL);
				nodesQueue.push_back(NULL);
			}
		}
		nodesInThisLevel *= 2;
	}
	printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
	printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);
}

void bst::addnode(string movietitle, long int tickets_sold, long int money_made, string opening_date, myenum unrated_terrible_bad_medicore_good_exellent, string how_you_want_organ, 
	bool keeptrackcounter) //addtrue
{
	if (how_you_want_organ == "movietitle") // For name organization
	{
		if (rootptr == NULL)
		{
			if (keeptrackcounter)
				sorteff++;
			rootptr = new bstNode(movietitle, tickets_sold, money_made, opening_date, unrated_terrible_bad_medicore_good_exellent);
		}
		else
		{
			bstNode* temp = NULL;
			temp = rootptr;
			do
			{
				if (temp->getMovieTitle() == movietitle)
				{
					if (checkdoubleentry(temp, movietitle))
					{
						cout << "Duplicate Movie... removing" << endl;
						sleep_for(seconds(2));
						return;
					}
				}
				if (temp->getMovieTitle() > movietitle)
				{
					if (temp->getleft() == NULL)
					{
						if (keeptrackcounter)
							sorteff++;
						temp->setleft(movietitle, tickets_sold, money_made, opening_date, unrated_terrible_bad_medicore_good_exellent);
						temp = temp->getleft();
						return;
					}
					if (keeptrackcounter)
					sorteff++;
					temp = temp->getleft();
				}
				else
				{
					if (temp->getright() == NULL)
					{
						if (keeptrackcounter)
							sorteff++;
						temp->setright(movietitle, tickets_sold, money_made, opening_date, unrated_terrible_bad_medicore_good_exellent);
						temp = temp->getright();
						return;
					}
					if (keeptrackcounter)
						sorteff++;
					temp = temp->getright();
				}
			} while (true);
		}
	}
	else if (how_you_want_organ == "ticsold") // FOR THE ticket ORGANIZATION
	{
		if (rootptr == NULL)
		{
			if (keeptrackcounter)
				sorteff++;
			rootptr = new bstNode(movietitle, tickets_sold, money_made, opening_date, unrated_terrible_bad_medicore_good_exellent);
		}
		else
		{
			bstNode* temp = NULL;
			temp = rootptr;
			do
			{
				if (temp->getTicsold() == tickets_sold)
				{
					if (checkdoubleentry(temp, movietitle))
					{
						cout << "Duplicate Movie... removing" << endl;
						sleep_for(seconds(2));
						return;
					}
				}
				if (temp->getTicsold() > tickets_sold)
				{
					if (temp->getleft() == NULL)
					{
						if (keeptrackcounter)
							sorteff++;
						temp->setleft(movietitle, tickets_sold, money_made, opening_date, unrated_terrible_bad_medicore_good_exellent);
						temp = temp->getleft();
						return;
					}
					if (keeptrackcounter)
						sorteff++;
					temp = temp->getleft();
				}
				else
				{
					if (temp->getright() == NULL)
					{
						if (keeptrackcounter)
							sorteff++;
						temp->setright(movietitle, tickets_sold, money_made, opening_date, unrated_terrible_bad_medicore_good_exellent);
						temp = temp->getright();
						return;
					}
					if (keeptrackcounter)
						sorteff++;
					temp = temp->getright();
				}
			} while (true);
		}
	}
	else if (how_you_want_organ == "money") // FOR THE money ORGANIZATION
	{
		if (rootptr == NULL)
		{
			if (keeptrackcounter)
				sorteff++;
			rootptr = new bstNode(movietitle, tickets_sold, money_made, opening_date, unrated_terrible_bad_medicore_good_exellent);
		}
		else
		{
			bstNode* temp = NULL;
			temp = rootptr;
			do
			{
				if (temp->getMoney() == money_made)
				{
					if (checkdoubleentry(temp, movietitle))
					{
						cout << "Duplicate Movie... removing" << endl;
						sleep_for(seconds(2));
						return;
					}
				}
				if (temp->getMoney() > money_made)
				{
					if (temp->getleft() == NULL)
					{
						if (keeptrackcounter)
							sorteff++;
						temp->setleft(movietitle, tickets_sold, money_made, opening_date, unrated_terrible_bad_medicore_good_exellent);
						temp = temp->getleft();
						return;
					}
					if (keeptrackcounter)
						sorteff++;
					temp = temp->getleft();
				}
				else
				{
					if (temp->getright() == NULL)
					{
						if (keeptrackcounter)
							sorteff++;
						temp->setright(movietitle, tickets_sold, money_made, opening_date, unrated_terrible_bad_medicore_good_exellent);
						temp = temp->getright();
						return;
					}
					if (keeptrackcounter)
						sorteff++;
					temp = temp->getright();
				}
			} while (true);
		}
	}
	else if (how_you_want_organ == "opdate") // FOR THE opening date ORGANIZATION
	{
		if (rootptr == NULL)
		{
			if (keeptrackcounter)
				sorteff++;
			rootptr = new bstNode(movietitle, tickets_sold, money_made, opening_date, unrated_terrible_bad_medicore_good_exellent);
		}
		else
		{
			bstNode* temp = NULL;
			temp = rootptr;
			do
			{
				if (temp->getOpdate() == opening_date)
				{
					if (checkdoubleentry(temp, movietitle))
					{
						cout << "Duplicate Movie... removing" << endl;
						sleep_for(seconds(2));
						return;
					}
				}
				if (temp->getOpdate() > opening_date)
				{
					if (temp->getleft() == NULL)
					{
						if (keeptrackcounter)
							sorteff++;
						temp->setleft(movietitle, tickets_sold, money_made, opening_date, unrated_terrible_bad_medicore_good_exellent);
						temp = temp->getleft();
						return;
					}
					if (keeptrackcounter)
						sorteff++;
					temp = temp->getleft();
				}
				else
				{
					if (temp->getright() == NULL)
					{
						if (keeptrackcounter)
							sorteff++;
						temp->setright(movietitle, tickets_sold, money_made, opening_date, unrated_terrible_bad_medicore_good_exellent);
						temp = temp->getright();
						return;
					}
					if (keeptrackcounter)
						sorteff++;
					temp = temp->getright();
				}
			} while (true);
		}
	}
	else if (how_you_want_organ == "rating") // FOR THE rating ORGANIZATION
	{
		if (rootptr == NULL)
		{
			if (keeptrackcounter)
				sorteff++;
			rootptr = new bstNode(movietitle, tickets_sold, money_made, opening_date, unrated_terrible_bad_medicore_good_exellent);
		}
		else
		{
			bstNode* temp = NULL;
			temp = rootptr;
			do
			{
				if (temp->getRatingenum() == unrated_terrible_bad_medicore_good_exellent)
				{
					if (checkdoubleentry(temp, movietitle))
					{
						cout << "Duplicate Movie... removing" << endl;
						sleep_for(seconds(2));
						return;
					}
				}
				if (temp->getRatingenum() > unrated_terrible_bad_medicore_good_exellent)
				{
					if (temp->getleft() == NULL)
					{
						if (keeptrackcounter)
							sorteff++;
						temp->setleft(movietitle, tickets_sold, money_made, opening_date, unrated_terrible_bad_medicore_good_exellent);
						temp = temp->getleft();
						return;
					}
					if (keeptrackcounter)
						sorteff++;
					temp = temp->getleft();
				}
				else
				{
					if (temp->getright() == NULL)
					{
						if (keeptrackcounter)
							sorteff++;
						temp->setright(movietitle, tickets_sold, money_made, opening_date, unrated_terrible_bad_medicore_good_exellent);
						temp = temp->getright();
						return;
					}
					if (keeptrackcounter)
						sorteff++;
					temp = temp->getright();
				}
			} while (true);
		}
	}
}

void bst::removemenue()
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	foshow removemen;
	bstNode* temp2;
	string temp;
	string choice;
	printtofile(1);
	removemen.drawbstmenue(0, 1, 0);
	cout << "Enter the title of the movie you wish to remove(Must be capitol): ";
	SetConsoleTextAttribute(hConsole, 124);
	if (!cin.good())
	{
		cin.clear();
		cin.ignore();
	}
	getline(cin, temp);
	SetConsoleTextAttribute(hConsole, 112);
	if (temp == "x")
		return;
		temp2 = search(temp,0); // 0 just means not keeping count (off the books)
		if (temp2 == NULL)
		{
			cout << "Couldn't find the movie!\n";
			system("PAUSE");
			return;
		}
		else
		{
			removemen.drawbstmenue(0,0,0);
			temp2->print();
		}
		cout << "Are you sure you want this deleted?:";
		SetConsoleTextAttribute(hConsole, 124);
		cout << "(y / n): ";
		while (!(choice == "y" || choice == "n"))
		{
			getline(cin, choice);
		}
		SetConsoleTextAttribute(hConsole, 112);
		if (choice == "y")
		{
			removenode(temp);
		}
		else return;
}


bstNode* bst::search(string target, bool keeptrack)
{
	bstNode* temp = rootptr;
	while (temp != NULL)
	{ 
		if (keeptrack)
		searcheff++;
		if (target == temp->getMovieTitle())
			return temp;
		else if (target > temp->getMovieTitle())
		{
			temp = temp->getright();
		}
		else
		{
			temp = temp->getleft();
		}
	}
	return NULL;
}

void bst::removenode(string key)
{
	removeeff = 1;
	removenodeprivate(key, rootptr);
}

void bst::removerootmatch()
{
	if (rootptr != NULL)
	{
		removeeff++;
		bstNode* delptr = rootptr;
		string rootkey = rootptr->getMovieTitle();
		string smallestinrightsubtree;

		//case 0-0 children
		if (rootptr->getleft() == NULL && rootptr->getright() == NULL)
		{
			removeeff++;
			rootptr = NULL;
			delete delptr;
		}

		//case 1 - 1 child
		else if (rootptr->getleft() == NULL && rootptr->getright() != NULL)
		{
			removeeff++;
			rootptr = rootptr->getright();
			delptr->setrightptr(NULL);
			delete delptr;
			cout << "\nThe root node with key " << rootkey << "was deleted. ";
		}
		else if (rootptr->getleft() != NULL && rootptr->getright() == NULL)
		{
			removeeff++;
			rootptr = rootptr->getleft();
			delptr->setleftptr(NULL);
			delete delptr;
			cout << "\nThe root node with key " << rootkey << "was deleted. ";
		}

		//case 2 - 2 Children
		else
		{
			removeeff++;
			//SafeBoxOfData
			string movtit, opda;
			long int ticso, mon;
			myenum rat;
			//============
			smallestinrightsubtree = findsmallestprivate(rootptr->getright());
			bstNode* temp = search(smallestinrightsubtree, 0);
			//Saving data in tempo
			movtit = temp->getMovieTitle();
			ticso = temp->getTicsold();
			mon = temp->getMoney();
			opda = temp->getOpdate();
			rat = temp->getRatingenum();
			//==================
			removenodeprivate(smallestinrightsubtree, rootptr); 
			if (temp != NULL)
			{
				rootptr->setmovietitle(movtit);
				rootptr->setticsold(ticso);
				rootptr->setmoneymade(mon);
				rootptr->setopdate(opda);
				rootptr->setrating(rat);
			}
			//rootkey was overwritten
		}
	}
	else
	{
		removeeff++;
		cout << "Can not remove root. The tree is empty\n";
	}
}

void bst::removematch(bstNode* parent, bstNode* match, bool left)
{
	if (rootptr != NULL)
	{
		removeeff++;
		bstNode* delptr;
		string matchKey = match->getMovieTitle();
		string smallestinrightsubtree;
		if (match->getleft() == NULL && match->getright() == NULL)
		{
			removeeff++;
			delptr = match;
			left == true ? parent->setleftptr(NULL) : parent->setrightptr(NULL);
			delete delptr;
			cout << "\nThe node containing key " << matchKey << " was removed";
			system("pause");
		}
		else if (match->getleft() == NULL && match->getright() != NULL)
		{
			removeeff++;
			left == true ? parent->setleftptr(match->getright()) : parent->setrightptr(match->getright());
			match->setrightptr(NULL);
			delptr = match;
			delete delptr;
			cout << "\nThe node containing key " << matchKey << " was removed";
			system("pause");
		}
		else if (match->getleft() != NULL && match->getright() == NULL)
		{
			removeeff++;
			left == true ? parent->setleftptr(match->getleft()) : parent->setrightptr(match->getleft());
			match->setleftptr(NULL);
			delptr = match;
			delete delptr;
			cout << "\nThe node containing key " << matchKey << " was removed";
			system("pause");
		}

		//case 2 - 2 children
		else
		{
			removeeff++;
			//SafeBoxOfData
			string movtit, opda;
			long int ticso, mon;
			myenum rat;
			//============
			bstNode* tempo;
			smallestinrightsubtree = findsmallestprivate(match->getright());
			tempo = search(smallestinrightsubtree,0);
			//Saving data in tempo
			movtit = tempo->getMovieTitle();
			ticso = tempo->getTicsold();
			mon = tempo->getMoney();
			opda = tempo->getOpdate();
			rat = tempo->getRatingenum();
			//==================
			removenodeprivate(smallestinrightsubtree, match);
			//setting match to saved data
			match->setmovietitle(movtit);
			match->setticsold(ticso);
			match->setmoneymade(mon);
			match->setopdate(opda);
			match->setrating(rat);
			//========================
		}
	}
	else
	{
		removeeff++;
		cout << "Can not remove match. wtf?";
	}

}

string bst::findsmallestprivate(bstNode* ptr)
{
	if (rootptr == NULL)
	{
		removeeff++;
		cout << "The tree is empty\n";
		return "Error";
	}
	else
	{
		if (ptr->getleft() != NULL)
		{
			removeeff++;
			return findsmallestprivate(ptr->getleft());
		}
		else
		{
			removeeff++;
			return ptr->getMovieTitle();
		}
	}
}

string bst::findsmallest()
{
	removeeff++;
	return findsmallestprivate(rootptr);
}

void bst::removenodeprivate(string key, bstNode* parent)
{
	removeeff++;
	if (rootptr != NULL)
	{
		if (rootptr->getMovieTitle() == key)
		{
			removeeff++;
			removerootmatch();
		}
		else
		{
			if (key < parent->getMovieTitle() && parent->getleft() != NULL)
			{
				removeeff++;
				if (parent->getleft()->getMovieTitle() == key)
				{
					removeeff++;
					removematch(parent, parent->getleft(), true);
				}
				else
				{
					removeeff++;
					removenodeprivate(key, parent->getleft());
				}
			}
			else if (key > parent->getMovieTitle() && parent->getright() != NULL)
			{
				removeeff++;
				if (parent->getright()->getMovieTitle() == key)
				{
					removeeff++;
					removematch(parent, parent->getright(), false);
				}
				else
				{
					removeeff++;
					removenodeprivate(key, parent->getright());
				}
			}
			else
			{
				removeeff++;
				cout << "\nData not in the tree...\n";
				system("PAUSE");
			}
		}
	}
	else
	{
		removeeff++;
		cout << "Tree is empty\n";
	}
}

void bst::reprin(bstNode* a)
{
	if (a != NULL)
	{
		reprin(a->getleft());
		a->print();
		reprin(a->getright());
	}
}

void bst::reprinfile(bstNode* a, bool final_or_temp) 
{
	if (a != NULL)
	{
		if (final_or_temp)
		{
			ofstream output("Movielist.txt", ios::app);
			reprinfile(a->getleft(), 1);
			output << a;
			reprinfile(a->getright(), 1);
		}
		else
		{
			ofstream output("temp.txt", ios::app);
			reprinfile(a->getleft(), 0);
			output << a;
			reprinfile(a->getright(), 0);
		}
	}
}


void bst::addnode()
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	foshow addnodemen;
	string movname, opdate;
	long int ticsold, money, ratemp;
	myenum rating;
	string addchoice;
	string::size_type sz;
	do{
		addnodemen.drawbstmenue(0, 1, 0);
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
		addnode(movname, ticsold, money, opdate, rating, "movietitle",0);
		cout << "\nAdd more data?";
		SetConsoleTextAttribute(hConsole, 124);
		cout << "(y / n)";
		SetConsoleTextAttribute(hConsole, 112);
		cout << ":";
		SetConsoleTextAttribute(hConsole, 124);
		std::cin.ignore(256, '\n');
		getline(cin, addchoice);
		while (!(addchoice == "y" || addchoice == "n"))
		{
			getline(cin, addchoice);
		}
		SetConsoleTextAttribute(hConsole, 112);
	} while (addchoice == "y");

}

void bst::printall(string type)
{
	organizeby(type,0);

	bstNode* temp = rootptr;
	if (rootptr == NULL)
	{
		cout << "No data in tree\n";
		return;
	}
	if (rootptr->getleft() != NULL)
	{
		reprin(temp->getleft());
	}
	rootptr->print();
	if (rootptr->getright() != NULL)
	{
		reprin(temp->getright());
	}
}

void bst::printtofile(bool final_or_temp) // printtrue
{
	if (final_or_temp)
	{
		bstNode* temp = rootptr;
		ofstream output("Movielist.txt");
		output << "";
		output.close();
		if (rootptr == NULL)
		{
			//cout << "No data in tree";
			return;
		}
		if (rootptr->getleft() != NULL)
		{
			reprinfile(temp->getleft(), 1);
		}
		ofstream output2("Movielist.txt", ios::app);
		output2 << rootptr;
		output2.close();
		if (rootptr->getright() != NULL)
		{
			reprinfile(temp->getright(), 1);
		}
	}
	else
	{
		bstNode* temp = rootptr;
		ofstream output("temp.txt");
		output << "";
		output.close();
		if (rootptr == NULL)
		{
			cout << "No data in tree";
			return;
		}
		if (rootptr->getleft() != NULL)
		{
			reprinfile(temp->getleft(), 0);
		}
		ofstream output2("temp.txt", ios::app);
		output2 << rootptr;
		output2.close();
		if (rootptr->getright() != NULL)
		{
			reprinfile(temp->getright(), 0);
		}
	}
}


void bst::organizeby(string a, int b) //organtrue
{
	if (b == 2) // This is solely used for checking number of steps for each different organization
	{
		string tictemp, montemp, ratemp, movietitle;
		long int money, ticsold;
		string opdate;
		string::size_type sz;
		myenum rating; // terrible, bad, medicore, good, exellent

		printtofile(0);
		deleteeff = 0;
		deleteall(rootptr, 1);//doesn't set rootptr to NULL : second parameter for keeping track of steps or not
		rootptr = NULL;
		ifstream list("temp.txt");
		sorteff = 0;
		while (getline(list, movietitle))
		{
			getline(list, tictemp);
			ticsold = stoi(tictemp, &sz);
			getline(list, montemp);
			money = stoi(montemp, &sz);
			getline(list, opdate);
			getline(list, ratemp);
			rating = static_cast<myenum>(stoi(ratemp, &sz));
			addnode(movietitle, ticsold, money, opdate, rating, a, 1);
		}
		remove("temp.txt");
	}
	else if (b == 1) // print memory tree to temp.txt, then reads it back in in movie title order
	{
		string tictemp, montemp, ratemp, movietitle;
		long int money, ticsold;
		string opdate;
		string::size_type sz;
		myenum rating; // terrible, bad, medicore, good, exellent
		printtofile(0); //problem
		deleteeff = 0;
		deleteall(rootptr,1);//doesn't set rootptr to NULL : second parameter for keeping track of steps or not
		rootptr = NULL;
		ifstream list("temp.txt");
		sorteff = 0;
		while (getline(list, movietitle))
		{
			getline(list, tictemp);
			ticsold = stoi(tictemp, &sz);
			getline(list, montemp);
			money = stoi(montemp, &sz);
			getline(list, opdate);
			getline(list, ratemp);
			rating = static_cast<myenum>(stoi(ratemp, &sz));
			addnode(movietitle, ticsold, money, opdate, rating, "movietitle",1);
		}
		remove("temp.txt");
	}
	else // reads in data from movielist.txt into the asked for order
	{
		string tictemp, montemp, ratemp, movietitle;
		long int money, ticsold;
		string opdate;
		string::size_type sz;
		myenum rating; // terrible, bad, medicore, good, exellent


		deleteall(rootptr,0);//doesn't set rootptr to NULL
		rootptr = NULL;
		ifstream list("Movielist.txt");
		while (getline(list, movietitle))
		{
			getline(list, tictemp);
			ticsold = stoi(tictemp, &sz);
			getline(list, montemp);
			money = stoi(montemp, &sz);
			getline(list, opdate);
			getline(list, ratemp);
			rating = static_cast<myenum>(stoi(ratemp, &sz));
			addnode(movietitle, ticsold, money, opdate, rating, a,0);
		}
	}
	
}

void bst::deleteall(bstNode* a,bool keeptrack)
{
	if (a) {
		if (keeptrack)
		deleteeff++; 
		deleteall(a->getleft(),keeptrack);
		if (keeptrack)
			deleteeff++;
		deleteall(a->getright(),keeptrack);
		if (keeptrack)
		deleteeff++;
		delete a;
	}
}

bool bst::checkdoubleentry(bstNode* a,string b)
{
	if (a->getMovieTitle() == b)
		return true;
	return false;
}