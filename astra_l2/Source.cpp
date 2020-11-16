#include <iostream>
#include <ctime>
#include "astr_l2.h"

using namespace std;


int* creating_Array_int(int size) 
{
	srand(time(NULL));
	int *Array = new int [size];
	for (int index = 0; index < size; index++) {
		Array[index] = rand() - rand();
	}
	return Array;
}

char* creating_Array_char(int size)
{
	srand(time(NULL));
	char* Array = new char[size];
	for (int index = 0; index < size; index++) {
		Array[index] = rand()%128;
	}
	return Array;
}

bool is_sorted(int *Array, int size) {
	for (int index = 0; index < (size - 1); index++) {
		if (Array[index] > Array[index + 1])
			return false;
	}
	return true;
}

bool is_sorted(char* Array, int size) {
	for (int index = 0; index < (size - 1); index++) {
		if (Array[index] > Array[index + 1])
			return false;
	}
	return true;
}

int BinarySearch(int* Array, int size, int N)
{
	int left = 0, right = size-1, mid = size/2;
	if (!is_sorted(Array, size))
		throw out_of_range("Array is not sorted");
	while (Array[mid] != N) {
		mid = left + right;
		if (N < Array[mid])
			right = mid - 1;
		else if (N > Array[mid])
			left = mid + 1;
		else return mid;
		if (left > right) {
			throw out_of_range("The key doesn't exist");
		}
	}
	return mid;
}

void QuickSort(int* Array, int size)
{
	int i = 0, j = size - 1, pivot = Array[size/2];
	int temp = 0;
	while (i <= j) {
		while (Array[i] < pivot) 
			i++;
		while (Array[j] > pivot) 
			j--;
		if (i <= j) {
			temp = Array[i];
			Array[i] = Array[j];
			Array[j] = temp;
			i++;
			j--;
		}
	}
	if (j > 0)
		QuickSort(Array, j + 1);
	if (i < size)
		QuickSort(&Array[i], size - i);
}

void InsertionSort(int* Array, int size) {
	int j, key;
	for (int i = 1; i < size; i++) {
		key = Array[i];
		j = i - 1;
		while (j >= 0 && Array[j] > key) 
		{
			Array[j + 1] = Array[j];
			j = j - 1;
		}
		Array[j + 1] = key;
	}
}

void BogoSort(int* Array, int size) {
	srand(time(NULL));
	int temp;
	while (!is_sorted(Array, size))
		for (int index = 0; index < size; index++) {
			temp = Array[index];
			Array[index] = Array[rand() % size];
			Array[rand() % size] = temp;
		}
}

void CountingSort(char* Array, int size) {
	int Max = 256, count = 0;
	int* result = new int[Max];
	for (int index = 0; index < Max; index++)
		result[index] = 0;
	for (int index = 0; index < size; index++)
		result[Array[index] + 127] += 1;
	for (int i = 0; i < Max; i++)
		for (int j = 0; j < result[i]; j++) {
			Array[count] = i - 127;
			count++;			
		}
}

float Average(float* Array) {
	float average = 0;
	for (int index = 0; index < 10; index++) {
		average += Array[index];
	}
	average /=  10;
	return average;
}

int main()
{
	float selection[10];
	int* Array;
	int size = 10;
	float time = 0;
	cout << "For Quick sort:"<<endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			Array = creating_Array_int(size);
			time = clock();
			QuickSort(Array,size);
			time = clock() - time;
			selection[j] = ((double)time*1000/CLOCKS_PER_SEC);
			cout << selection[j]<<' ';
			delete[] Array;
		}
		cout << "Average: "<<Average(selection)<<endl;
		size *= 10;
	}
	size = 10;
	cout << endl<< "For Insertion sort:"<<endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			Array = creating_Array_int(size);
			time = clock();
			InsertionSort(Array, size);
			time = clock() - time;
			selection[j] = ((double)time * 1000 / CLOCKS_PER_SEC);
			cout << selection[j] << ' ';
			delete[] Array;
		}
		cout << "Average: " << Average(selection) << endl;
		size *= 10;
	}
	return 0;
}