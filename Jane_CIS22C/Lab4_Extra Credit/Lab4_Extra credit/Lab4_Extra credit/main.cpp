/** @file Main.cpp */

/*
CIS 22C
Lab4 - Extra credit: sort an array using insertion sort, quicksort, mergesort
Pre :
Post:
Return:
Jie Tian and Xiaojing Liu
*/

#include <iostream>
#include <fstream>

using namespace std;

#define ARRAY_SIZE 32

void insertionSort(int arr[], int size, ofstream& output);
int pivot(int arr[], int first, int last);
void quickSort(int arr[], int first, int last, ofstream& output);
void merge(int arr[], int first, int mid, int last);
void mergeSort(int arr[], int first, int last, ofstream& output);


int main()
{
	// ask for array size
	int size;
	cout << "Please enter the size of array (can not exceed 32): ";
	cin >> size;
	if (size > ARRAY_SIZE)
	{
		cout << "The size can not exceed 32, please enter again:";
		cin >> size;
	}
	// add numbers to array
	int* myArray = new int[size];
	int number;
	for (int i = 0; i < size; i++)
	{
		cout << "Please enter an integer number: ";
		cin >> number;
		myArray[i] = number;
	}
	cout << endl;

	ofstream output;
	output.open("output.txt");

	output << "Lab4 - Extra credit" << endl;
	output << "Jie Tian and Xiaojing Liu" << endl << endl;

	cout << "Here is the original array:" << endl;
	output << "Here is the original array:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << myArray[i] << " ";
		output << myArray[i] << " ";
	}
	cout << endl << endl;
	output << endl << endl;

	cout << "Insertion sort: " << endl;
	output << "Insertion sort: " << endl;
	insertionSort(myArray, size, output);
	cout << endl;
	output << endl;
	
	cout << "Quick sort: " << endl;
	output << "Quick sort: " << endl;
	quickSort(myArray, 0, size - 1, output);
	cout << endl;
	output << endl;

	cout << "Merge sort: " << endl;
	output << "Merge sort: " << endl;
	mergeSort(myArray, 0, size - 1, output);
	cout << endl;
	output << endl;
	
	delete[] myArray;

	output.close();

	system("pause");
	return 0;
}

// insertion sort
void insertionSort(int arr[], int size, ofstream& output)
{
	int current = 1;				      
	int last = size - 1;			    	
	int temp;						 
	int walker;						 
	while (current <= last)
	{
		temp = arr[current];		    
		walker = current - 1;
		while (walker >= 0			// not past front of array yet
			&& temp < arr[walker])	// and current element < element in front     
		{
			arr[walker + 1] = arr[walker];  // shift element in front to the right
			walker--;        
		}
		arr[walker + 1] = temp;		// insert current element to the proper location in the array 
		current++;
		
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
			output << arr[i] << " ";
		}
		cout << endl;
		output << endl;
	}
}

// Find and return the index of pivot element.
int pivot(int arr[], int first, int last)
{
	int index = first;     
	int pivotElement = arr[first];  
	for (int i = first + 1; i <= last; i++)
	{
		if (arr[i] <= pivotElement)      // current element <= first element
		{
			index++;                     
			swap(arr[i], arr[index]);     // shift the element
		}
	}
	swap(arr[index], arr[first]);
	return index;
}

// quick sort
void quickSort(int arr[], int first, int last, ofstream& output)
{
	int pivotIndex;
	if (first < last)
	{
		pivotIndex = pivot(arr, first, last);    
		quickSort(arr, first, pivotIndex - 1, output);  // sort the left half array
		quickSort(arr, pivotIndex + 1, last, output);	 // sort the right half array
		//cout << "QuickSort(first=" << first << ", last=" << last << ")" << endl;
		for (int i = first; i < last+1; i++)
		{
			cout << arr[i] << " ";
			output << arr[i] << " ";
		}
		cout << endl;
		output << endl;
	}
}

// merge two sorted array
void merge(int arr[], int first, int mid, int last)
{
	int* tempArray = new int[last+1];	// Temporary array
	int first1 = first;		// Beginning of first subarray
	int last1 = mid;		// End of first subarray
	int first2 = mid + 1;		// Beginning of second subarray
	int last2 = last;		// End of second subarray

	// While both subarrays are not empty, copy thesmaller item into the temporary array
	int index = first1;		// Next available location in tempArray
	while ((first1 <= last1) && (first2 <= last2))
	{
		if (arr[first1] <= arr[first2])
		{
			tempArray[index] = arr[first1];
			first1++;
		}
		else
		{
			tempArray[index] = arr[first2];
			first2++;
		}			
		index++;
	}				
	// Finish off the first subarray, if necessary
	while (first1 <= last1)
	{
		tempArray[index] = arr[first1];
		first1++;
		index++;
		
	}				
	// Finish off the second subarray, if necessary
	while (first2 <= last2)
	{
		tempArray[index] = arr[first2];
		first2++;
		index++;
	
	}				
	// Copy the result back into the original array
	for (index = first; index <= last; index++)
	{
		arr[index] = tempArray[index];
	}

	delete[] tempArray;
}				

// merge sort
void mergeSort(int arr[], int first, int last, ofstream& output)
{
	if (first < last)
	{
		int mid = first + (last - first) / 2;
		mergeSort(arr, first, mid, output);      // sort the left half array
		mergeSort(arr, mid + 1, last, output);    // sort the right half array
		merge(arr, first, mid, last);       // merge the two halves

		//cout << "Merge Sort(first=" << first << ", last=" << last << ")" << endl;
		for (int i = first; i < last + 1; i++)
		{
			cout << arr[i] << " ";
			output << arr[i] << " ";
		}
		cout << endl;
		output << endl;
	}
}
