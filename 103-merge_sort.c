#include "sort.h"

/**
 * merg - Merge two sorted sub-arrays into a sorted array
 * @left: Pointer to the left sub-array
 * @left_siz: Size of the left sub-array
 * @right: Pointer to the right sub-array
 * @right_siz: Size of the right sub-array
 * @array: Pointer to the merged array
 */

void merg(int *left, size_t left_siz, int *right, size_t right_siz, int *array)
{
	size_t i = 0, j = 0, k = 0;

	while (i < left_siz && j < right_siz)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < left_siz)
	{
		array[k] = left[i];
		i++;
		k++;
	}
	while (j < right_siz)
	{
		array[k] = right[j];
		j++;
		k++;
	}
}
/**
 * merge_sort - Sort an array in ascending order using the Merge sort algorithm
 * @array: Pointer to the array to sort
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (size > 1)
	{
		size_t mid;
		int *left;
		int *right;
		size_t left_siz;
		size_t right_siz;

		mid = size / 2;
		left = array;
		right = array + mid;
		left_siz = mid;
		right_siz = size - mid;

		merge_sort(left, left_siz);
		merge_sort(right, right_siz);
		printf("Merging...\n");
		printf("[left]: ");
		print_array(left, left_siz);
		printf("[right]: ");
		print_array(right, right_siz);

		int *temp;

		temp = malloc(sizeof(int) * size);

		if (!temp)
			return;
		merg(left, left_siz, right, right_siz, temp);

		size_t i;

		for (i = 0; i < size; i++)
			array[i] = temp[i];
		printf("[Done]: ");
		print_array(array, size);
		free(temp);
	}
}
