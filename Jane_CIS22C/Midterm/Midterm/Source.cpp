// Jie Tian

#include <iostream>
#include <string>
#include "Array.h";

using namespace std;

// find the largest item in the array
template <class ItemType>
int findLargest(Array<ItemType> theArray, int size)
{
	int index = 0;
	for (int i = 1; i < size; i++)
	{
		if (theArray[i] > theArray[index])
		{
			index = i;
		}
	}
	return index;
}

// sort the array
template <class ItemType>
void selectionSort(Array<ItemType> &theArray, int n) 
{
	if (n == 0)
	{
		return;
	}
	else
	{
		int largest = findLargest(theArray, n);
		swap(theArray[largest], theArray[n - 1]);
		selectionSort(theArray, n - 1);
	}
}


int main()
{
	/*
	// Test with int
	int sizeInt;
	cout << "Please enter the size of Int array: ";
	cin >> sizeInt;
	Array<int> int_array(sizeInt);
	int itemInt;
	for (int i = 0; i < sizeInt; i++)
	{
		cout << "Please add item: ";
		cin >> itemInt;
		int_array.setArray(i, itemInt);
	}
	selectionSort(int_array, sizeInt);
	int_array.displayArray();
	cout << endl;

	// Test with char
	int sizeChar;
	cout << "Please enter the size of Char array: ";
	cin >> sizeChar;
	Array<char> char_array(sizeChar);
	char itemChar;
	for (int i = 0; i < sizeChar; i++)
	{
		cout << "Please add item: ";
		cin >> itemChar;
		char_array.setArray(i, itemChar);
	}
	selectionSort(char_array, sizeChar);
	char_array.displayArray();
	cout << endl;

	// Test with string
	int sizeString;
	cout << "Please enter the size of array: ";
	cin >> sizeString;
	Array<string> string_array(sizeString);
	string itemString;
	for (int i = 0; i < sizeString; i++)
	{
		cout << "Please add item: ";
		cin >> itemString;
		string_array.setArray(i, itemString);
	}
	selectionSort(string_array, sizeString);
	string_array.displayArray();
	*/

	int choice;
	cout << "Please enter the number for the type of array: " << endl;
	cout << "1. int" << endl;
	cout << "2. double" << endl;
	cout << "3. char" << endl;
	cout << "4. string" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
	{			
		cout << "Please enter the size of array: ";
		int intSize;
		cin >> intSize;
		Array<int> intArray(intSize);
		int intItem;
		for (int i = 0; i < intSize; i++)
		{
			cout << "Please add item: ";
			cin >> intItem;
			intArray.setArray(i, intItem);
		}
		selectionSort(intArray, intSize);
		intArray.displayArray();
	}
		break;
	case 2:
	{
		cout << "Please enter the size of array: ";
		int doubleSize;
		cin >> doubleSize;
		Array<double> doubleArray(doubleSize);
		double doubleItem;
		for (int i = 0; i < doubleSize; i++)
		{
			cout << "Please add item: ";
			cin >> doubleItem;
			doubleArray.setArray(i, doubleItem);
		}
		selectionSort(doubleArray, doubleSize);
		doubleArray.displayArray();
	}
		break;
	case 3:
	{
		cout << "Please enter the size of array: ";
		int charSize;
		cin >> charSize;
		Array<char> charArray(charSize);
		char charItem;
		for (int i = 0; i < charSize; i++)
		{
			cout << "Please add item: ";
			cin >> charItem;
			charArray.setArray(i, charItem);
		}
		selectionSort(charArray, charSize);
		charArray.displayArray();
	}
		break;
	case 4:
	{
		cout << "Please enter the size of array: ";
		int stringSize;
		cin >> stringSize;
		Array<string> stringArray(stringSize);
		string stringItem;
		for (int i = 0; i < stringSize; i++)
		{
			cout << "Please add item: ";
			cin >> stringItem;
			stringArray.setArray(i, stringItem);
		}
		selectionSort(stringArray, stringSize);
		stringArray.displayArray();
	}
		break;
	default:
		break;
	}

	system("pause");
	return 0;
}