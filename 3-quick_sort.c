#include "sort.h"


/**
 * swap - swap between two elements
 *
 * @array: array
 * @i: index of elem 1
 * @j: index of elem 2
 *
 * Return: nothing
 */

void swap(int array[], int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}


/**
 * partition - partition function
 *
 * @array: array to be sorted
 * @start: low index
 * @end: high index
 * @size: size
 *
 * Return: index
 */

int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int j = start - 1;
	int i;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			j++;
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
		}
	}
	if (pivot < array[j + 1])
	{
		swap(array, j + 1, end);
		print_array(array, size);
	}
	return (j + 1);
}


/**
 * quick - recursion func
 *
 * @array: array to be sorted
 * @start: low index
 * @end: high index
 * @size: size
 */

void quick(int *array, int start, int end, size_t size)
{
	int pivotIndex;

	if (start < end)
	{
		pivotIndex = partition(array, start, end, size);
		quick(array, start, pivotIndex - 1, size);
		quick(array, pivotIndex + 1, end, size);
	}

}

/**
 * quick_sort - calcul the low and the high index
 *
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	int start = 0;
	int end = size - 1;

	if (size < 2)
		return;
	quick(array, start, end, size);
}
