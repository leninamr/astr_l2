#pragma once

int* creating_Array_int(int size);
char* creating_Array_char(int size);
bool is_sorted(int* Array, int size);
bool is_sorted(char* Array, int size);
int BinarySearch(int* Array, int size, int N);
void QuickSort(int* Array, int size);
void InsertionSort(int* Array, int size);
void BogoSort(int* Array, int size);
void CountingSort(char* Array, int size);
float Average(float* Array);