#include "sort.h"

/**
 * swap - swaps two elements of an array
 * @a: first element
 * @b: second element
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * partition - partitions an array
 * @array: array to be partitioned
 * @low: index of the first element of the partition to be sorted
 * @high: index of the last element of the partition to be sorted
 * @size: size of the array
 *
 * Return: index of the pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_helper - sorts a partition of an array
 * @array: array to be sorted
 * @low: index of the first element of the partition to be sorted
 * @high: index of the last element of the partition to be sorted
 * @size: size of the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_sort_helper(array, low, pivot - 1, size);
		quick_sort_helper(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using quicksort
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL && size > 1)
		quick_sort_helper(array, 0, size - 1, size);
}

