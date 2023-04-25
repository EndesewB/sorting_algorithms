#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 * Counting sort algorithm
 *
 * @array: The array to sort
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *counting_array, *output_array;
	int max = array[0], i;

	if (!array || size < 2)
		return;

	for (i = 1; i < (int) size; i++)
		if (array[i] > max)
			max = array[i];

	counting_array = malloc(sizeof(int) * (max + 1));
	output_array = malloc(sizeof(int) * size);

	for (i = 0; i <= max; i++)
		counting_array[i] = 0;
	for (i = 0; i < (int) size; i++)
		counting_array[array[i]]++;

	printf("%d", counting_array[0]);
	for (i = 1; i <= max; i++)
		printf(", %d", counting_array[i]);
	printf("\n");

	for (i = 1; i <= max; i++)
		counting_array[i] += counting_array[i - 1];
	for (i = (int) size - 1; i >= 0; i--)
	{
		output_array[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]]--;
	}
	for (i = 0; i < (int) size; i++)
		array[i] = output_array[i];

	free(counting_array);
	free(output_array);
}

