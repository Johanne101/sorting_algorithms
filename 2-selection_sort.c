/*
 * 2-selection- Selection Sort
 * Date: October, 25, 2021
 * Author: Johanne J. Lopez
 */

#include "sort.h"

/**
 * swap - swap elements
 * @xp: x pointer
 * @yp: y pointer
 */
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 * selection_sort - Implements Selection sort algorithm
 * @array: pointer
 * @size: structure
 */

void selection_sort(int *array, size_t size)
{
	/* array to array[size-1] is the array to sort */
	long unsigned int i,j, jMin;

	/* advance the position through the entire array */
	/*   (could do i < aLength-1 because single element is also min element) */
	for (i = 0; i < size - 1; i++)
	{
		/* find the min element in the unsorted a[i .. aLength-1] */

		/* assume the min is the first element */
		jMin = i;
		/* test against elements after i to find the smallest */
		for (j = i + 1; j < size; j++)
		{
			/* if this element is less, then it is the new minimum */
			if (array[j] < array[jMin])
			{
				/* found new minimum; remember its index */
				jMin = j;
			}
		}

		if (jMin != i) 
		{
			swap(&array[i], &array[jMin]);
			print_array(array, size);
		}
	}
}
