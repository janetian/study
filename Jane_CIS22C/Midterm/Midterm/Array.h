/** Header file for an array-based implementation of the ADT bag.
@file Array.h */


# ifndef _ARRAY
# define _ARRAY

template <class ItemType>

class Array
{
private:
	int size;
	ItemType* myArray;
public:
	Array()
	{
		size = 0;
		myArray = 0;
	}

	// construct
	Array(int s)
	{
		size = s;
		myArray = new ItemType[size];
	}

	// copy construct
	Array(const Array & source)
	{
		size = source.size;
		myArray = new ItemType[size];
		for (int i = 0; i < size; i++)
		{
			myArray[i] = source.myArray[i];
		}
	}

	// destruct
	~Array()
	{
		delete[] myArray;
	}

	// add item to the array
	void setArray(int elem, ItemType newItem) 
	{
		myArray[elem] = newItem;
	}

	// display the array
	void displayArray() 
	{
		cout << "The array you entered after sort: ";
		for (int i = 0; i < size; i++) 
		{
			cout << myArray[i] << " ";
				
		}
		cout  << endl;
	}

	// operator [] overload
	ItemType &operator[] (int index)
	{
		if (index >= 0 && index < size)
		{
			return myArray[index];
		}
	}
	
};

#endif