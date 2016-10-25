/** @file infixCalculate.h */

#ifndef _INFIX_CALCULATE
#define _INFIX_CALCULATE

#include "Stack.h"

class infixCalculate
{
public:
	infixCalculate() {}
	int precedence(char op);
	int getResult(char op, int a, int b);
	int infixEval(std::string str);
};

#endif