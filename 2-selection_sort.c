#include "sort.h"


/**
 * selection_sort - Sorts an array of integers in ascending order using
 * the Selection sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		int smallestValue = array[i];
		size_t smallestIndex = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < smallestValue)
			{
				smallestValue = array[j];
				smallestIndex = j;
			}
		}
		tmp = array[i];
		array[i] = array[smallestIndex];
		array[smallestIndex] = tmp;
		print_array(array, size);
	}
}

