#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 *_print - printing
 *
 * @temp: temp
 * @array: array
 * @lft: length of left subarray
 * @lrgt: length of right subarray
 * @start: start index
 *
 * Return: nothing
 */

void _print(int *temp, int *array, int lft, int lrgt, int start)
{
	printf("Merging...\n");
	printf("[left]: ");
	print_array(temp, lft);
	printf("[right]: ");
	print_array(&temp[lft], lrgt);
	printf("[Done]: ");
	print_array(&array[start], lft + lrgt);
}

/**
 * merge - merge
 *
 * @array: array
 * @start: start
 * @mid: mid
 * @end: end
 *
 * Return: nothing
 */


void merge(int *array, int start, int mid, int end)
{
	int i, j, k;
	int length_left = mid - start + 1;
	int length_right = end - mid;


	int *temp = malloc((length_left + length_right) * sizeof(int));

	for (i = 0; i < length_left; i++)
		temp[i] = array[start + i];

	for (j = 0; j < length_right; j++)
		temp[j + length_left] = array[mid + 1 + j];

	i = 0;
	j = 0;
	k = start;

	while (i < length_left && j < length_right)
	{
		if (temp[i] < temp[j + length_left])
		{
			array[k++] = temp[i++];
		}
		else
		{
			array[k++] = temp[j++ + length_left];
		}
	}

	while (i < length_left)
		array[k++] = temp[i++];

	while (j < length_right)
		array[k++] = temp[j++ + length_left];

	_print(temp, array, length_left, length_right, start);
	free(temp);
}


/**
 * mergeSort - mergeSort
 *
 * @array: array
 * @start: start
 * @end: end
 *
 */


void mergeSort(int *array, int start, int end)
{

	int mid;

	if (start < end)
	{
		mid = (end + start) / 2;

		if ((end - start + 1) % 2 != 0)
			mid = mid - 1;
		mergeSort(array, start, mid);
		mergeSort(array, mid + 1, end);
		merge(array, start, mid, end);
	}

}

/**
 * merge_sort - merge sort
 *
 * @array: array
 * @size: size of the array
 *
 */


void merge_sort(int *array, size_t size)
{
	int start = 0;
	int end = size - 1;

	if (size < 2)
		return;
	mergeSort(array, start, end);
}
