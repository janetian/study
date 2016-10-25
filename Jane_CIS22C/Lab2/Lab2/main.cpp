/** @file Main.cpp */

/*
CIS 22C
Lab2 : implement a link-based Stack ADT
Pre :
Post:
Return:
Jie Tian and Xiaojing Liu
*/


#include <iostream>
#include <string>
#include "Stack.h"
#include "Currency.h"

int main()
{
	// Test the Stack ADT with int type data
	std::cout << "Test the stack with number:" << std::endl;
	// Push items
	Stack<int> my_int_stack;
	my_int_stack.push(0);
	my_int_stack.push(1);
	my_int_stack.push(2);
	my_int_stack.push(3);
	std::cout << "Push items into stack: " << std::endl;
	my_int_stack.print();

	// Pop item
	my_int_stack.pop();
	std::cout << "Pop item from stack: " << std::endl;
	my_int_stack.print();
	
	// Pop another item
	my_int_stack.pop();
	std::cout << "Pop another item from stack: " << std::endl;
	my_int_stack.print();

	// show the first item
	std::cout << "Show the top item from stack: " << std::endl
		<< my_int_stack.peek() << std::endl << std::endl;

	// Test the Stack ADT with string type data
	std::cout << "Test the stack with string:" << std::endl;
	// Push items
	Stack<std::string> my_string_stack;
	my_string_stack.push("zero");
	my_string_stack.push("one");
	my_string_stack.push("two");
	my_string_stack.push("three");
	std::cout << "Push items into stack: " << std::endl;
	my_string_stack.print();

	// Pop item
	my_string_stack.pop();
	std::cout << "Pop item from stack: " << std::endl;
	my_string_stack.print();

	// Pop another item
	my_string_stack.pop();
	std::cout << "Pop another item from stack: " << std::endl;
	my_string_stack.print();

	// show the first item
	std::cout << "Show the top item from stack:" << std::endl
		<< my_string_stack.peek() << std::endl << std::endl;


	// Test the Stack ADT with currency object
	std::cout << "Test the stack with currecy object:" << std::endl;
	Stack<USDollar> my_currency_stack;
	USDollar my_usdollar(100, 20);
	my_currency_stack.push(my_usdollar);
	USDollar my_usdollar1(88, 10);
	my_currency_stack.push(my_usdollar1);
	USDollar my_usdollar2(27, 68);
	my_currency_stack.push(my_usdollar2);
	USDollar my_usdollar3(54, 18);
	my_currency_stack.push(my_usdollar3);
	std::cout << "Push items into stack: " << std::endl;
	my_currency_stack.print();
	
	// Pop item
	my_currency_stack.pop();
	std::cout << "Pop item from stack: " << std::endl;
	my_currency_stack.print();

	// Pop another item/
	my_currency_stack.pop();
	std::cout << "Pop another item from stack: " << std::endl;
	my_currency_stack.print();

	// show the first item
	std::cout << "Show the top item from stack:" << std::endl
		<< my_currency_stack.peek() << std::endl << std::endl;

	system("pause");
	return 0;
}
