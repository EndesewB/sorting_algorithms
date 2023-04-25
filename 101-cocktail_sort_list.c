#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * using the Cocktail shaker sort algorithm
 *
 * @list: Pointer to a pointer to the first node of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 0;
	listint_t *left = *list;
	listint_t *right = NULL;

	if (*list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		while (left->next != right)
		{
			if (left->n > left->next->n)
			{
				swap_nodes(list, left, left->next);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				left = left->next;
			}
		}
		right = left;
		while (right->prev != NULL)
		{
			if (right->n < right->prev->n)
			{
				swap_nodes(list, right->prev, right);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				right = right->prev;
			}
		}
		left = right;
	} while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: Pointer to a pointer to the first node of the list
 * @node1: Pointer to the first node to be swapped
 * @node2: Pointer to the second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
	{
		node1->prev->next = node2;
	}
	else
	{
		*list = node2;
	}
	if (node2->next != NULL)
	{
		node2->next->prev = node1;
	}
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

