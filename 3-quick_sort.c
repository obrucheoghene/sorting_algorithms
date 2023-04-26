#include "sort.h"

/**
 * quick_sort - a function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 *
 * @array: The array
 * @size: The size
 * return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_operation(array, 0, size - 1, size);
}



/**
 * quick_sort_operation - Quick sort operation
 *
 * @array: The given array
 * @low: lower
 * @high: higher
 * @size: array size
 * Return: void
 */

void quick_sort_operation(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lumuto_partition(array, low, high, size);
		quick_sort_operation(array, low, pivot - 1, size);
		quick_sort_operation(array, pivot + 1, high, size);
	}
}


/**
 * lumuto_partition - Lomuto partition scheme for Quick Sort.
 * @array: array
 * @low: lower
 * @high: higher
 * @size: array's size
 * Return: pivot (int)
 */
int lumuto_partition(int *array, int low, int high, size_t size)
{
	int i = low - 1;
	int pivot = array[high];
	int temp = 0;
	int j = low;

	for (; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
