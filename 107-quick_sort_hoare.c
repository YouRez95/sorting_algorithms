#include "sort.h"

/**
 * swap - swap two elements
 *
 * @array: array
 * @i: first element
 * @j: second element
 */

void swap(int *array, int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
 * partition - partition
 *
 * @array: array
 * @start: start index
 * @end: final index
 * @size: size
 *
 * Return: index of pivot
 */


int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int i = start;
	int j = end;

	while (i < j)
	{
		while (array[i] < pivot)
		{
			i++;
		}

		while (array[j] > pivot)
		{
			j--;
		}

		if (i < j)
		{
			swap(array, i, j);
			print_array(array, size);
			i++;
		}
	}
	return (i);
}

/**
 * quickSort - recursion function
 *
 * @array: array
 * @start: start index
 * @end: final index
 * @size: size
 */


void quickSort(int *array, int start, int end, size_t size)
{
	int pivotIndex;

	if (start < end)
	{
		pivotIndex = partition(array, start, end, size);
		quickSort(array, start, pivotIndex - 1, size);
		quickSort(array, pivotIndex, end, size);
	}

}

/**
 * quick_sort_hoare - quick sort
 *
 * @array: array
 * @size: size
 */


void quick_sort_hoare(int *array, size_t size)
{
	int start;
	int end;

	if (size < 2)
		return;
	start = 0;
	end = size - 1;
	quickSort(array, start, end, size);
}
