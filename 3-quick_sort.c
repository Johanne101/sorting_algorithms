/**
 * Quick Sort Algorithm
 * Date: October, 25, 2021
 * Author: Johanne J. Lopez
 */

#include "sort.h"

int partition(int *array, int low, int high, size_t size);
void lomuto(int *array, size_t low, size_t high, size_t size);

/**
 * quick_sort - sorts array of int. in ascending order using Quick sort algo.
 * @array: pointer to array of integers
 * @size: size of array
 * Return: Void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	/* if low = 0, high = size-1, sort w/ partition*/
	lomuto(array, 0, size - 1, size);
}
/**
 * partition - Function (Partition Algorithm) keeps track of,
 *             index of lower value, while traversing array,
 *             from high to low.
 * @array: array of elements.
 * @low: Starting index.
 * @high: Ending index.
 * @size: size of array.
 *
 * Return: the index of the array from where the check should begin.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, tmp = 0, j;
	/*i = keeps low index value, j = current elemnt traversing*/

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			printf("i: [%i], j: [%i], pivot: [%i]\n", i, j, pivot);
			if (i != j)
			{
				/* swap*/
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
				printf("--------------------\n");
				print_array(array, size);
			}
		}
		i++; /*increment smaller index*/
	}
/*	tmp = array[i];
	array[i] = array[high];
	array[high] = tmp;
	print_array(array, size);
*/
	return (i);
}

/**
 * lomuto - sort an array of integers
 * @array: array to be sorted.
 * @low: first element in array.
 * @high: last element in array.
 * @size: size of the array.
 *
 */
/*recursion(arr[], low, high) recursive quick sort function*/
void lomuto(int *array, size_t low, size_t high, size_t size)
{
	size_t pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		lomuto(array, low, pi - 1, size); /* Before partition index*/
		lomuto(array, pi + 1, high, size); /* After partition index*/
	}
}
