#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *                        order using the Insertion sort algorithm.
 * @list: Double pointer to the head of the list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		prev = current->prev;
		while (prev != NULL && prev->n > current->n)
		{
			temp = prev->prev;
			prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev;
			current->next = prev;
			prev->prev = current;
			current->prev = temp;
			if (temp != NULL)
				temp->next = current;
			else
				*list = current;
			prev = current->prev;
			print_list(*list);
		}
		current = current->next;
	}
}

