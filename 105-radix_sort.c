#include "sort.h"

/**
 * getMax - Finds the maximum element in an array.
 * @array: The array to find the maximum element in.
 * @size: The size of the array.
 * Return: The maximum element in the array.
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return max;
}

/**
 * Sig_sort - Sorts an array of integers based on a significant digit.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @exp: The current significant digit to consider.
 */
void Sig_sort(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size), n;
	int count[10] = {0};
	size_t i, k;
	ssize_t j;

	if (!output)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (n = 1; n < 10; n++)
		count[n] += count[n - 1];

	for (j = size - 1; j >= 0; j--)
	{
		output[count[(array[j] / exp) % 10] - 1] = array[j];
		count[(array[j] / exp) % 10]--;
	}

	for (k = 0; k < size; k++)
		array[k] = output[k];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		Sig_sort(array, size, exp);
		print_array(array, size);
	}
}
