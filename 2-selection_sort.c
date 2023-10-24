#include "sort.h"

/**
 * selection_sort - sort an array
 *
 * @array: array to be sorted
 * @size: the size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, minIndex;
	int swapped, temp;

	if (size < 2)
		return;
	for (i = 0; i < size ; i++)
	{
		swapped = 0;
		minIndex = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
				swapped = 1;
			}
		}
		if (swapped == 1)
		{
			temp = array[i];
			array[i] = array[minIndex];
			array[minIndex] = temp;
			print_array(array, size);
		}
	}
}
