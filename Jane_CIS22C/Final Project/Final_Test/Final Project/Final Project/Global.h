#define _WIN32_WINNT 0x0500
#ifndef Global_H
#define Global_H
#include<iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <Windows.h>
#include <thread>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <mmsystem.h>


using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
const enum myenum { Unrated = 0, Terrible = 1, Bad, Mediocre, Good, Exellent };
const int defaultsize = 25; // This is the size HASHSIZE is set to if it loads an empty list 


#endif