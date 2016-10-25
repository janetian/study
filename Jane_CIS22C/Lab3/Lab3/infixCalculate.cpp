/** @file infixCalculate.h */

#include <string>
#include <cctype> 
#include "infixCalculate.h"


// compare the precedence of operators
int infixCalculate::precedence(char op)
{
	switch (op)
	{
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case ')':
		return 3;
	default:
		return -1;
	}
}

// calculate the result
int infixCalculate::getResult(char op, int a, int b)
{
	int result;
	switch (op)
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		result = a / b;
		break;
	}
	return result;
}

// evaluate the infix expression
int infixCalculate::infixEval(std::string str)
{
	Stack<char> opStack;  // stack to hold operators
	Stack<int> valStack;   // stack to hold operands
	int operand1;
	int operand2;
	int result;
	char op;
	for (int i = 0; i < str.length(); i++)      // walk through the expression
	{
		if (!isdigit(str[0]))  
		{
			std::cout << "syntax error!" << std::endl;
			return -1;
		}

		if (isdigit(str[i]))   // char is a number
		{
			valStack.push(str[i] - '0');  // convert the char to int and push to value stack
		}
		else     // char is a operators
		{
			switch (str[i])
			{
			case '(':
				opStack.push(str[i]);
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				if (opStack.isEmpty())
				{
					opStack.push(str[i]);
				}
				else if (precedence(str[i]) > precedence(opStack.peek()))
				{
					opStack.push(str[i]);
				}
				else    // calcalute
				{
					while (!opStack.isEmpty() && precedence(str[i]) <= precedence(opStack.peek()))
					{
						if (valStack.isEmpty())
						{
							std::cout << "syntax error!" << std::endl;
							return -1;
						}
						else
						{
							operand2 = valStack.peek();  // save the value from the top of value stack
							valStack.pop();              // pop the char
						}
						if (valStack.isEmpty())
						{
							std::cout << "syntax error!" << std::endl;
							return -1;
						}
						else
						{
							operand1 = valStack.peek();  // save the value from the top of value stack
							valStack.pop();              // pop the char
						}
						if (opStack.isEmpty())
						{
							std::cout << "syntax error!" << std::endl;
							return -1;
						}
						else
						{
							op = opStack.peek();         // get the operater
							opStack.pop();
						}
						result = getResult(op, operand1, operand2);  // call the result function to calculate 
						valStack.push(result);   // push the result to value stack
					}
					opStack.push(str[i]);
				}
				break;
			case ')':
				while (opStack.peek() != '(')  // calculate
				{
					if (valStack.isEmpty())
					{
						std::cout << "syntax error!" << std::endl;
						return -1;
					}
					else
					{
						operand2 = valStack.peek();  // save the value from the top of value stack
						valStack.pop();              // pop the char
					}
					if (valStack.isEmpty())
					{
						std::cout << "syntax error!" << std::endl;
						return -1;
					}
					else
					{
						operand1 = valStack.peek();  // save the value from the top of value stack
						valStack.pop();              // pop the char
					}
					if (opStack.isEmpty())
					{
						std::cout << "syntax error!" << std::endl;
						return -1;
					}
					else
					{
						op = opStack.peek();         // get the operater
						opStack.pop();
					}
					result = getResult(op, operand1, operand2);  // call the result function to calculate 
					valStack.push(result);   // push the result to value stack
				}
				if (opStack.isEmpty())
				{
					std::cout << "syntax error!" << std::endl;
					return -1;
				}
				else
				{
					opStack.pop();
					break;
				}
			}
		}
	}
	while (!opStack.isEmpty())    // calculate
	{
		if (valStack.isEmpty())
		{
			std::cout << "syntax error!" << std::endl;
			return -1;
		}
		else
		{
			operand2 = valStack.peek();  // save the value from the top of value stack
			valStack.pop();              // pop the char
		}
		if (valStack.isEmpty())
		{
			std::cout << "syntax error!" << std::endl;
			return -1;
		}
		else
		{
			operand1 = valStack.peek();  // save the value from the top of value stack
			valStack.pop();              // pop the char
		}
		if (opStack.isEmpty())
		{
			std::cout << "syntax error!" << std::endl;
			return -1;
		}
		else
		{
			op = opStack.peek();         // get the operater
			opStack.pop();
		}
		result = getResult(op, operand1, operand2);  // call the result function to calculate 
		valStack.push(result);   // push the result to value stack value stack
	}
	return result;
}
