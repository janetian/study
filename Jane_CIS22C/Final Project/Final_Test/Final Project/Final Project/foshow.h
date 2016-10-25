//Graphics by Brandon Sipos
//This class is in charge of music and graphics for the program

#ifndef foshow_h
#define foshow_h
#include "Global.h"
#include <shlobj.h>

class foshow
{
	void drawhextitle();
	void drawbsttitle();
	void drawmaintitle();
public:
	void testit();
	bool summonthegraphics();
	void titlescreen();
	void redrawtitle();
	void drawbstmenue(bool BunchofSpacesAtEnd1, bool True_for_x_to_exit, bool True_for_displaying_options);
	void drawhexmenue(bool BunchofSpacesAtEnd1,bool True_for_x_to_exit, bool True_for_displaying_options);
	void drawmainmenue();
	bool afterstartmusicmanage(bool);
	bool s();
};

#endif