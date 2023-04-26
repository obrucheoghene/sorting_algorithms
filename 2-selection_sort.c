#include "sort.h"


/**
 * selection_sort -  a function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 *
 * @array: The array
 * @size: size of array
 * return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t min_index, i, j;
	int temp;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}

		temp = array[i];
		array[i] = array[min_index];
		array[min_index] = temp;
		
		print_array(array, size);
	}
}
