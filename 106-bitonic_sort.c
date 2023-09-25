#include <stdio.h>

/**
 * bitonic_compare_swap - Compare and swap two elements in the array.
 * @array: The array to be sorted.
 * @low: Starting index of the subarray.
 * @count: Number of elements to compare and swap.
 * @dir: Sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_compare_swap(int *array, size_t low, size_t count, int dir)
{
	size_t i, swap;
	int temp;

	for (i = low; i < low + count / 2; i++)
	{
		if ((array[i] > array[i + count / 2]) == dir)
		{
			temp = array[i];
			array[i] = array[i + count / 2];
			array[i + count / 2] = temp;
			swap = 1;
		}
	}

	if (swap)
	{
		printf("Merging [%lu/%lu] (%s):\n", low, low + count - 1, dir ? "UP" : "DOWN");
		for (i = low; i < low + count; i++)
		{
			if (i > low)
				printf(", ");
			printf("%d", array[i]);
		}
		printf("\n");
	}
}

/**
 * bitonic_merge - Recursively merge two subarrays.
 * @array: The array to be sorted.
 * @low: Starting index of the subarray.
 * @count: Number of elements in the subarray.
 * @dir: Sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
	size_t k;

	if (count > 1)
	{
		k = count / 2;

		bitonic_compare_swap(array, low, count, dir);
		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursively sorts the Bitonic sequence.
 * @array: The array to be sorted.
 * @low: Starting index of the subarray.
 * @count: Number of elements in the subarray.
 * @dir: Sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_sort_recursive(int *array, size_t size, size_t low, size_t count, int dir)
{
	size_t k;

	if (count > 1)
	{
		k = count / 2;

		bitonic_sort_recursive(array, size, low, k, 1);
		bitonic_sort_recursive(array, size, low + k, k, 0);
		bitonic_merge(array, low, count, dir);
	}
	/* if (size == count) */
	/* 	print_array(array, size); */
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 *				  using the Bitonic Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, size, 0, size, 1);
}
