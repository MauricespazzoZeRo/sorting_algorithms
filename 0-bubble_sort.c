#include "sort.h"

/**
 *bubble_sort - sorts an array of integers in ascending order
 *using the Bubble sort algorithm
 *@array:array of integers to sort
 *@size:size of array
 */

void bubble_sort(int *array, size_t size)
{
	int swapped = 1;
	int i;
	int temp;
	int n;

	if (array == NULL || size == 0)
		return;
	do
	{
		swapped = 0;
		i = 0;
		for (n = size - 1; i < n; i++)
		{
			if (array[i + 1] < array[i])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
		n--;
	}
	while (swapped);
}
