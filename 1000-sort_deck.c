#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deck.h"

/**
 * compare_cards - Custom comparison function for qsort.
 * Compares two cards based on their values and kinds.
 * @a: Pointer to the first card node.
 * @b: Pointer to the second card node.
 * Return: Negative, 0, or positive value depending on the comparison result.
 */
int compare_cards(const void *a, const void *b)
{
	const deck_node_t *node_a = *(const deck_node_t **)a;
	const deck_node_t *node_b = *(const deck_node_t **)b;

	if (node_a->card->kind == node_b->card->kind)
	{
		const char *values[] = {
			"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"
		};

		int value_a = -1, i;
		int value_b = -1;

		for (i = 0; i < 13; i++)
		{
			if (strcmp(node_a->card->value, values[i]) == 0)
				value_a = i;

			if (strcmp(node_b->card->value, values[i]) == 0)
				value_b = i;
		}

		return value_a - value_b;
	}

	return node_a->card->kind - node_b->card->kind;
}

/**
 * sort_deck - Sorts a deck of cards.
 * @deck: Pointer to a pointer to the deck's head.
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current, **node_array;
	size_t count = 0, j, k;

	current = *deck;

	if (deck == NULL || *deck == NULL)
		return;

	/* Count the number of nodes in the deck. */
	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	/* Create an array of pointers to deck nodes. */
    node_array = malloc(sizeof(deck_node_t *) * count);

	if (node_array == NULL)
		return;

	current = *deck;
	for (j = 0; j < count; j++)
	{
		node_array[j] = current;
		current = current->next;
	}

	/* Sort the array of pointers using qsort. */
	qsort(node_array, count, sizeof(deck_node_t *), compare_cards);

	/* Rearrange the linked list nodes based on the sorted array*/
	for (k = 0; k < count - 1; k++)
	{
		node_array[k]->next = node_array[k + 1];
		node_array[k + 1]->prev = node_array[k];
	}

	node_array[0]->prev = NULL;
	node_array[count - 1]->next = NULL;
	*deck = node_array[0];

	free(node_array);
}
