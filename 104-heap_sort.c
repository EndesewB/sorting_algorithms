#include "sort.h"

/**
 * sift_down - Repairs the heap whose root element is at index start,
 * and ensures that the subtree rooted at start is a valid heap.
 *
 * @array: Array to be sorted
 * @start: Index of the root of the heap.
 * @end: Index of the last element in the heap.
 * @size: Size of the array
 *
 * Return: void
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child, swap;

	while (2 * root + 1 <= end)
	{
		int temp = array[root];
		child = 2 * root + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;

		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;

		if (swap == root)
			return;

		array[root] = array[swap];
		array[swap] = temp;
		root = swap;

		print_array(array, size);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using
 * the sift-down heap sort algorithm.
 *
 * @array: Array to be sorted
 * @size: Size of the array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	size_t end = size - 1;
	size_t start;

	for (start = (size - 2) / 2; (int)start >= 0; start--)
		sift_down(array, start, end, size);

	while (end > 0)
	{
		int temp = array[end];
		array[end] = array[0];
		array[0] = temp;

		print_array(array, size);
		end--;

		sift_down(array, 0, end, size);
	}
}

