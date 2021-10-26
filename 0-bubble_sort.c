/*
 * 0-bubble_sort.c - Bubble Sort
 * Date: October, 25, 2021
 * Author: Johanne J. Lopez
 */

#include "sort.h"

/*
 * bubble_sort - sorts given array
 * @array: memory with elements
 * @size: size of int
 */

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/* A function to implement bubble sort*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	for (i = 0; i < size-1; i++)
	{
		/* Last i elements are already in place*/
		for (j = 0; j < size-i-1; j++)
		{
			if (array[j] > array[j+1])
			{
				swap(&array[j], &array[j+1]);
				print_array(array, size);
			}
		}
	}
}
