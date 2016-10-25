#include "foshow.h"

bool foshow::summonthegraphics()
{
	//This Block Manipulates TXT color and prompt size
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	//MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, r.left, r.top, 800, 800, TRUE);
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	return 1;
}

void foshow::redrawtitle()
{
	cout << "   __  __            _      _____        _        ____           _____ ______ " << endl;

	cout << "  |  \\/  |          (_)    |  __ \\      | |      |  _ \\   /\\    / ____|  ____|" << endl;

	cout << "  | \\  / | _____   ___  ___| |  | | __ _| |_ __ _| |_) | /  \\  | (___ | |__   " << endl;

	cout << "  | |\\/| |/ _ \\ \\ / / |/ _ \\ |  | |/ _` | __/ _` |  _ < / /\\ \\  \\___ \\|  __|  " << endl;

	cout << "  | |  | | (_) \\ V /| |  __/ |__| | (_| | || (_| | |_) / ____ \\ ____) | |____ " << endl;

	cout << "  |_|  |_|\\___/ \\_/ |_|\\___|_____/ \\__,_|\\__\\__,_|____/_/    \\_\\_____/|______|" << endl;
}

void foshow::titlescreen()
{
	system("Color 70");
	const long int time = 150000000;
	const long int time2 = 10000000;
	sleep_for(seconds(1));
	cout << "   __  __            _      _____        _        ____           _____ ______ " << endl;
	sleep_for(nanoseconds(time));
	cout << "  |  \\/  |          (_)    |  __ \\      | |      |  _ \\   /\\    / ____|  ____|" << endl;
	sleep_for(nanoseconds(time));
	cout << "  | \\  / | _____   ___  ___| |  | | __ _| |_ __ _| |_) | /  \\  | (___ | |__   " << endl;
	sleep_for(nanoseconds(time));
	cout << "  | |\\/| |/ _ \\ \\ / / |/ _ \\ |  | |/ _` | __/ _` |  _ < / /\\ \\  \\___ \\|  __|  " << endl;
	sleep_for(nanoseconds(time));
	cout << "  | |  | | (_) \\ V /| |  __/ |__| | (_| | || (_| | |_) / ____ \\ ____) | |____ " << endl;
	sleep_for(nanoseconds(time));
	cout << "  |_|  |_|\\___/ \\_/ |_|\\___|_____/ \\__,_|\\__\\__,_|____/_/    \\_\\_____/|______|" << endl;
	sleep_for(nanoseconds(time));
	cout << "                          By:Brandon, Jane, David, Jie" << endl;
	PlaySound(TEXT("lib\\s.wav"), NULL, SND_FILENAME);
	system("CLS");
	cout << endl;
	cout << "  |  \\/  |          (_)    |  __ \\      | |      |  _ \\   /\\    / ____|  ____|" << endl;
	cout << "  | \\  / | _____   ___  ___| |  | | __ _| |_ __ _| |_) | /  \\  | (___ | |__   " << endl;
	cout << "  | |\\/| |/ _ \\ \\ / / |/ _ \\ |  | |/ _` | __/ _` |  _ < / /\\ \\  \\___ \\|  __|  " << endl;
	cout << "  | |  | | (_) \\ V /| |  __/ |__| | (_| | || (_| | |_) / ____ \\ ____) | |____ " << endl;
	cout << "  |_|  |_|\\___/ \\_/ |_|\\___|_____/ \\__,_|\\__\\__,_|____/_/    \\_\\_____/|______|" << endl;
	sleep_for(nanoseconds(time));
	system("CLS");
	cout << endl;
	cout << endl;
	cout << "  | \\  / | _____   ___  ___| |  | | __ _| |_ __ _| |_) | /  \\  | (___ | |__   " << endl;
	cout << "  | |\\/| |/ _ \\ \\ / / |/ _ \\ |  | |/ _` | __/ _` |  _ < / /\\ \\  \\___ \\|  __|  " << endl;
	cout << "  | |  | | (_) \\ V /| |  __/ |__| | (_| | || (_| | |_) / ____ \\ ____) | |____ " << endl;
	sleep_for(nanoseconds(time));
	system("CLS");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "  | |\\/| |/ _ \\ \\ / / |/ _ \\ |  | |/ _` | __/ _` |  _ < / /\\ \\  \\___ \\|  __|  " << endl;
	sleep_for(nanoseconds(time));
	system("CLS");
	sleep_for(seconds(2));
}

bool foshow::s() // program start music initiallization
{
	char temp;
	ifstream sound("preference.txt");
	if (!sound)
	{
		ofstream create("preference.txt");
		create.close();
	}
	sound >> temp;
	sound.close();
	if (temp == 'm')
	{
		return false;
	}
	else
	{
		PlaySound(TEXT("lib\\main.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
		return true;
	}
}

bool foshow::afterstartmusicmanage(bool sound)
{
	if (sound == true)
	{
		PlaySound(NULL, NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
		ofstream disable("preference.txt");
		disable << "m";
		disable.close();
		return false;
	}
	else {
		PlaySound(TEXT("lib\\main.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
		remove("preference.txt");
		return true;
	}
}

void foshow::drawmaintitle()
{
	system("CLS");
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	cout << "              ";

	cout << " __  __       _         __  __                       " << endl;
	cout << "              ";
	cout << "|  \\/  |     (_)       |  \\/  |                      " << endl;
	cout << "              ";
	cout << "| \\  / | __ _ _ _ __   | \\  / | ___ _ __  _   _  ___ " << endl;
	cout << "  Mute  ";
	cout << "      ";
	cout << "| |\\/| |/ _` | | '_ \\  | |\\/| |/ _ \\ '_ \\| | | |/ _ \\" << endl;
	cout << " Toggle: ";
	SetConsoleTextAttribute(hConsole, 124);
	cout << "m";
	SetConsoleTextAttribute(hConsole, 112);
	cout << "    ";
	
	cout << "| |  | | (_| | | | | | | |  | |  __/ | | | |_| |  __/" << endl;
	
	cout << "              ";

	cout << "|_|  |_|\\__,_|_|_| |_| |_|  |_|\\___|_| |_|\\__,_|\\___|" << endl<<endl;

}

void foshow::drawbsttitle()
{
	cout << "             ___    _  _____              __  __                  " << endl;
	cout << "            | _ )__| ||_   _| _ ___ ___  |  \\/  |___ _ _ _  _ ___ " << endl;
	cout << "            | _ (_-<  _|| || '_/ -_) -_) | |\\/| / -_) ' \\ || / -_)" << endl;
	cout << "            |___/__/\\__||_||_| \\___\\___| |_|  |_\\___|_||_\\_,_\\___|" << endl<<endl;
}

void foshow::drawbstmenue(bool a, bool b, bool c)
{
	system("CLS");
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	drawbsttitle();
	if (c)
	{
		cout << "                                 Add new data = ";
		SetConsoleTextAttribute(hConsole, 124);
			cout << "a\n"; 
			SetConsoleTextAttribute(hConsole, 112);
			cout << "                                 Delete data = ";
			SetConsoleTextAttribute(hConsole, 124);
			cout << "d\n";
			SetConsoleTextAttribute(hConsole, 112);
			cout << "                                 Search data = ";
			SetConsoleTextAttribute(hConsole, 124);
			cout << "s\n";
			SetConsoleTextAttribute(hConsole, 112);
			cout << "                           List data in key order = ";
			SetConsoleTextAttribute(hConsole, 124);
			cout << "k\n";
			SetConsoleTextAttribute(hConsole, 112);
			cout << "                           List data in tree order = ";
			SetConsoleTextAttribute(hConsole, 124);
			cout << "t\n";
			SetConsoleTextAttribute(hConsole, 112);
			cout << "                                 Efficiency = ";
			SetConsoleTextAttribute(hConsole, 124);
			cout << "e";
			SetConsoleTextAttribute(hConsole, 112);
	}
	SetConsoleTextAttribute(hConsole, 124);
	if (b)
	cout << "\n                                 ('x' to exit)";
	SetConsoleTextAttribute(hConsole, 112);
	cout << endl;
	if (a)
		cout << "                                      ";
}

void foshow::drawhextitle()
{
	cout << "               _  _   __   ____  _  _  _  _  ____  __ _  _  _  ____ " << endl;
	cout << "              / )( \\ / _\\ / ___)/ )( \\( \\/ )(  __)(  ( \\/ )( \\(  __)" << endl;
	cout << "              ) __ (/    \\\\___ \\) __ (/ \\/ \\ ) _) /    /) \\/ ( ) _) " << endl;
	cout << "              \\_)(_/\\_/\\_/(____/\\_)(_/\\_)(_/(____)\\_)__)\\____/(____)" << endl<<endl;
}

void foshow::drawhexmenue(bool a,bool b, bool c)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("CLS");
	drawhextitle();
	if (c)
	{
		cout << "                                Add new data = ";
		SetConsoleTextAttribute(hConsole, 124);
		cout << "a\n";
		SetConsoleTextAttribute(hConsole, 112);
		cout << "                                Delete data = ";
		SetConsoleTextAttribute(hConsole, 124);
		cout << "d\n";
		SetConsoleTextAttribute(hConsole, 112);
		cout << "                                Search data = ";
		SetConsoleTextAttribute(hConsole, 124);
		cout <<"s\n";
		SetConsoleTextAttribute(hConsole, 112);
		cout << "                                List data = ";
		SetConsoleTextAttribute(hConsole, 124);
		cout << "l\n";
		SetConsoleTextAttribute(hConsole, 112);
		cout << "                                Information = ";
		SetConsoleTextAttribute(hConsole, 124);
		cout << "i";
		SetConsoleTextAttribute(hConsole, 112);
	}
	SetConsoleTextAttribute(hConsole, 124);
	if (b)
	cout << "\n                                ('x' to exit)";
	SetConsoleTextAttribute(hConsole, 112);
	cout << endl;
	if (a)
	cout << "                                      ";
}

void foshow::drawmainmenue()
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	drawmaintitle();
	cout << " Type ";
	SetConsoleTextAttribute(hConsole, 124);
	cout << "\"bst\" ";
	SetConsoleTextAttribute(hConsole, 112);
	cout << "to access the bst menue or";
	SetConsoleTextAttribute(hConsole, 124);
	cout << " \"hash\" ";
	SetConsoleTextAttribute(hConsole, 112);
	cout << "to enter the hex menue";
	SetConsoleTextAttribute(hConsole, 124);
	cout << " (x to exit)";
	SetConsoleTextAttribute(hConsole, 112);
	cout << ":";
	cout << "\n                                      ";
}

void foshow::testit()
{
	system("lib\\Egg.exe");
}