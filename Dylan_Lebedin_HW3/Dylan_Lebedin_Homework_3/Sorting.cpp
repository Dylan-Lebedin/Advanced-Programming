/*
*  FileName:    Sorting.cpp
*  Author:	Dylan Lebedin
*  Date:	10/21/2018
*
*  Description:  Implemented Functions for sorting. Bubble sort, Selection Sort
*/
#include "Sorting.h"
/**
*  This function sorts integers based on function pointers to
*    a desired sorting function and desired comparison function.
*
*  @param values  - pointer to array of integers
*      @param n  - number of integers in the array
*  @param alg  - function pointer to sorting algorithm
*  @param cmp  - function pointer to comparision function
*
*/
void sortArray(int* values, int n, void(*alg)(int*, int, bool(*cmp)(int, int)), bool(*cmp)(int, int))
{
	alg(values, n, cmp);
	// Finish
}
/**
*  This function sorts integers using the bubble sort method
*    based on a desired comparison function.
*
*  @param values  - pointer to array of integers
*    @param n  - number of integers in the array
*  @param cmp  - function pointer to comparision function
*
*/
void bubbleSort(int* values, int n, bool(*cmp)(int, int))
{
	bool sorted = false;// keep track here whether you still need to sort
	int iMin;
	while (!sorted) // repeat this until no more swaps
	{
		sorted = true;
		for (int i = 0; i < n-1; i++) // Repeat until N - 1 (i.e. 8 in this case)
		{

			if (cmp(*(values + i), *(values + i + 1))) // make sure you don't access out of bounds
			{
				swap((values + i), (values + i + 1));
				sorted = false; // we swapped, so keep sorting
			}
		}
	}
	// Finish
}
/**
*  This function sorts integers using the selection sort method
*    based on a desired comparison function.
*
*  @param values  - pointer to array of integers
*    @param n  - number of integers in the array
*  @param cmp  - function pointer to comparision function
*
*/
void selectionSort(int* values, int n, bool(*cmp)(int, int))
{
	bool sorted = false; // keep track here whether you still need to sort
	while (!sorted) // repeat this until no more swaps
	{
		sorted = true;
		int min;                     /* Loc of minimum. */
		for (int i = 0; i < n - 1; i++) {
			min = i;
			for (int j = i + 1; j < n; j++) {
				if (cmp(values[min], values[j]))
					min = j;
			}
			if (min != i) {
				swap(&values[i], &values[min]);
			}
		}
	}
	// Finish
}
/**
*  This function sorts integers using the selection sort method
*    based on a desired comparison function.
*
*  @param values  - pointer to array of integers
*    @param n  - number of integers in the array
*  @param cmp  - function pointer to comparision function
*
*/
void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	// Finish
}
/**
Page 5
*  This function sorts integers using the selection sort method
*    based on a desired comparison function.
*
*  @param values  - pointer to array of integers
*    @param n  - number of integers in the array
*  @param cmp  - function pointer to comparision function
*
*/
bool ascending(int a, int b)
{
	if (a > b) {
		return true;
	}
	else {
		return false;
	}
	// Finish
}
/**
*  This function compares two integers for descending order
*
*  @param a  - pointer to an integer
*  @param b  - pointer to an integer
*
*  @return true if a < b, else false
*/
bool descending(int a, int b)
{
	if (a < b) {
		return true;
	}
	else {
		return false;
	}
	// Finish
}
