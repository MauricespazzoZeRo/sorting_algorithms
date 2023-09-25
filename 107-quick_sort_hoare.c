#include "sort.h"

/**
 * hoare_partition - Partition the array using the Hoare scheme.
 * @array: The array to be partitioned.
 * @low: The lowest index of the partition.
 * @high: The highest index of the partition.
 * @size: Size of the array (used for printing).
 * Return: Index of the pivot.
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j = high + 1, temp;

	while (1)
	{
		do
		{
			i++;
		} while (array[i] < pivot);

		do
		{
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
		else
		{
			return j;
		}
	}
}


/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using
 *					  the Quick sort algorithm (Hoare scheme).
 * @array: The array to be sorted.
 * @size: Size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	int low = 0, high = size - 1;
	int *stack;
	int top = -1, pivot_idx;

	if (size < 2 || !array)
		return;

	stack = malloc(sizeof(int) * size * 2);

	stack[++top] = low;
	stack[++top] = high;

	while (top >= 0)
	{
		high = stack[top--];
		low = stack[top--];

		pivot_idx = hoare_partition(array, low, high, size);

		if (pivot_idx - 1 > low)
		{
			stack[++top] = low;
			stack[++top] = pivot_idx - 1;
		}

		if (pivot_idx + 1 < high)
		{
			stack[++top] = pivot_idx + 1;
			stack[++top] = high;
		}
	}
	free(stack);
}
