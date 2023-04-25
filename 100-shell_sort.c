#include "sort.h"
/**
 * shell_sort - shell sorting function for sort algorithm
 *
 * @array: the given unsorted array
 * @size: size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < size; gap = 3 * gap + 1)
		;

	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
