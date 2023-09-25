#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *					   order using the Cocktail Shaker Sort algorithm.
 * @list: Pointer to a pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start = NULL, *end = NULL, *current = NULL;

	if (list == NULL || *list == NULL)
		return;

	do
	{
		swapped = 0;
		current = *list;

		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(&current, &current->next, list);
				print_list(*list);
				swapped = 1;
			}
			else
			{
				current = current->next;
			}
		}

		if (!swapped)
			break;

		swapped = 0;
		end = current;

		while (current->prev != start)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(&current, &current->prev, list);
				print_list(*list);
				swapped = 1;
			}
			else
			{
				current = current->prev;
			}
		}
		start = current;
	}
	while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list and prints the list.
 * @a: Pointer to the first node.
 * @b: Pointer to the second node.
 * @list: Pointer to a pointer to the head of the list.
 */
void swap_nodes(listint_t **a, listint_t **b, listint_t **list)
{
	listint_t *temp_prev, *temp_next;

	if (*a == NULL || *b == NULL)
		return;

	temp_prev = (*a)->prev;
	temp_next = (*b)->next;

	if (temp_prev)
		temp_prev->next = *b;
	else
		*list = *b;

	if (temp_next)
		temp_next->prev = *a;

	(*a)->prev = *b;
	(*b)->next = *a;
	(*b)->prev = temp_prev;
	(*a)->next = temp_next;
}
