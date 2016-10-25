/** @file Main.cpp */

/*
CIS 22C
Lab3 : evaluate an infix expression
Pre :
Post:
Return:
Jie Tian and Xiaojing Liu
*/


#include <iostream>
#include <string>
#include "infixCalculate.h"

int main()
{
	/*
	// Test the infixEval function
	std::string myExpression1 = "5+(3+4)*5";
	std::cout << "The result of expression 5+(3+4)*5 is " << infixEval(myExpression1) << std::endl << std::endl;;

	std::string myExpression2 = "9-(3+4)*1";
	std::cout << "The result of expression 9-(3+4)*1 is " << infixEval(myExpression2) << std::endl << std::endl;

	std::string myExpression3 = "(6*(2+5))/3"; 
	std::cout << "The result of expression (6*(2+5))/3 is " << infixEval(myExpression3) << std::endl << std::endl;
	*/

	std::string infixExp;
	std::cout << "Please enter an infix expression: " << std::endl;
	getline(std::cin, infixExp);
	infixCalculate result;
	std::cout << "The result of expression " << infixExp << " is " << result.infixEval(infixExp) << std::endl;


	system("pause");
	return 0;
}
