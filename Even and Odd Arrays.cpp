// S112 Kowata Pointers - Even and Odd Arrays.cpp 
// Author: Michael Kowata
// Goal: Separate a given array into even and odd arrays

#include <iostream>
using namespace std;

//Prototypes
int* askUserForInputArray(int& aSize);
void countOccurrences(int* a, int aSize, int& evenCount, int& oddCount);
void printArray(int* arr, int arrSize, string caption);
void transferEvenValuesFromTo(int* a, int aSize, int* even);
void transferOddValuesFromTo(int* a, int aSize, int* odd);

int main()
{
	int aSize = -1;	

	int* a = askUserForInputArray(aSize);

	int evenCount = 0;
	int oddCount = 0;

	countOccurrences(a, aSize, evenCount, oddCount);

	int* even = new int[evenCount];
	int* odd = new int[oddCount];

	transferEvenValuesFromTo(a, aSize, even);

	printArray(even, evenCount, "Even Array");

	cout << "\n";

	transferOddValuesFromTo(a, aSize, odd);
	 
	printArray(odd, oddCount, "Odd Array");

	delete[] a;
	a = nullptr;

	delete[] even;
	even = nullptr;

	delete[] odd;
	odd = nullptr;

	cout << "\nArrays a, even, and odd deleted\n";
}

//User-Defined Functions
int* askUserForInputArray(int& aSize)
{
	while(aSize<0 or aSize>100){
	cout << "How many values are there in the array: ";
	cin >>  aSize;
	}

	int* a = new int[aSize]; 

	for (int i = 0; i < aSize; i++)
	{
		cout << "Enter item - " << i << ": ";
		cin >> *(a+i);
	}
	return a;
}

void countOccurrences(int* a, int aSize, int& evenCount, int& oddCount)
{
	for (int i = 0; i < aSize; i++)
	{
		if (*(a + i) % 2 == 0)
		{
			evenCount++;
		}
		else if (*(a + i) % 2 != 0)
		{
			oddCount++;
		}
	}
}

void printArray(int* arr, int arrSize, string caption)
{
	cout << caption << endl;

	for (int i = 0; i < arrSize; i++)
	{
		cout << *(arr + i) << " ";
	}
}

void transferEvenValuesFromTo(int* a, int aSize, int* even)
{
	int pos = 0;
	for (int i = 0; i < aSize; i++)
	{
		if (*(a + i) % 2 == 0)
		{
			*(even + pos) = *(a + i);
			pos++;
		}
	}
}

void transferOddValuesFromTo(int* a, int aSize, int* odd)
{		
	int pos = 0;
	for (int i = 0; i < aSize; i++)
	{
		if (*(a + i) % 2 != 0)
		{
			*(odd + pos) = *(a + i);
			pos++;
		}
	}
}
