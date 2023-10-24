#include "sort.h"

/**
 * partition - partition function
 *
 * @array: array to be sorted
 * @low: low index
 * @high: high index
 * @size: size
 *
 * Return: index
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	print_array(array, size);
	return (i + 1);
}

/**
 * quick_sort_recur - recursion func
 *
 * @array: array to be sorted
 * @low: low index
 * @high: high index
 * @size: size
 */

void quick_sort_recur(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		quick_sort_recur(array, low, pivot_index - 1, size);
		quick_sort_recur(array, pivot_index + 1, high, size);
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
	int low, high;

	low = 0;
	high = size - 1;

	quick_sort_recur(array, low, high, size);
}
