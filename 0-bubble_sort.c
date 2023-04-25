#include "sort.h"


/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array
 * return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int swap, swapped;

	while (1)
	{
		swapped = 0;

		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap = array[i];
				array[i] = array[i + 1];
				array[i + 1] = swap;

				swapped = 1;
				print_array(array, size);
			}
		}

		if (swapped == 0)
			break;
	}
}
