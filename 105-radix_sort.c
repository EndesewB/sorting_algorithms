#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order using the LSD
 * radix sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int *output, *count, max_digit = 0, divisor = 1;
	size_t i, j;

	if (!array || size < 2)
		return;

	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;

	count = malloc(10 * sizeof(int));
	if (count == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max_digit)
			max_digit = array[i];
	}
	while (max_digit / divisor > 0)
	{
		memset(count, 0, 10 * sizeof(int));
		for (i = 0; i < size; i++)
			count[(array[i] / divisor) % 10]++;
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
		for (i = size - 1; i < size; i--)
		{
			j = (array[i] / divisor) % 10;
			output[count[j] - 1] = array[i];
			count[j]--;
		}
		for (i = 0; i < size; i++)
			array[i] = output[i];
		print_array(array, size);
		divisor *= 10;
	}
	free(output);
	free(count);
}

