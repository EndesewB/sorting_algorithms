#include "sort.h"


/**
 * bubble_sort - Sorts an array of integers in ascending
 *	order using the Bubble sort algorithm
 *
 * @array: Pointer to the array to sort
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	int sorted = 0;
	int count = 0;

	if (!array || size < 2)
		return;

	while (!sorted)
	{
		size_t i;

		sorted = 1;
		for (i = 0; i < (size - 1 - count); i++)
		{
			if (array[i] > array[i + 1])
			{
				int tmp;

				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
				sorted = 0;
			}
		}
		count++;
	}
}

