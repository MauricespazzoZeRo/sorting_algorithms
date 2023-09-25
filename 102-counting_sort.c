#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting Sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The number of elements in the array.
 */
void counting_sort(int *array, size_t size)
{
	int max_value = 0;
	size_t i, l, n;
	int j, *count, k, *output;
	ssize_t m;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array */
	for (i = 0; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	/* Create a counting array of size max_value + 1 and initialize to 0 */
	count = malloc((max_value + 1) * sizeof(int));
	if (count == NULL)
		return;

	for (j = 0; j <= max_value; j++)
	{
		count[j] = 0;
	}

	/* Count the occurrences of each element in the original array */
	for (l = 0; l < size; l++)
	{
		count[array[l]]++;
	}

	/* Update the counting array to contain the cumulative counts */
	for (k = 1; k <= max_value; k++)
	{
		count[k] += count[k - 1];
	}

	/* Create a temporary array to store the sorted elements */
	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}

	/* Build the sorted array based on the counting array */
	for (m = size - 1; m >= 0; m--)
	{
		output[count[array[m]] - 1] = array[m];
		count[array[m]]--;
	}

	/* Copy the sorted elements back to the original array */
	for (n = 0; n < size; n++)
	{
		array[n] = output[n];
	}

	/* Print the counting array (optional) */
	print_counting_array(count, max_value);

	/* Free dynamically allocated memory */
	free(count);
	free(output);
}

/**
 * print_counting_array - Prints the counting array.
 * @count: The counting array to print.
 * @max_value: The maximum value in the counting array.
 *
 * Description: This function prints the elements of the counting array.
 * Each element is separated by a comma and space, and the array is printed
 * with a newline character at the end.
 */
void print_counting_array(int *count, int max_value)
{
	int i;

	if (count == NULL)
		return;

	for (i = 0; i <= max_value; i++)
	{
		printf("%d", count[i]);
		if (i < max_value)
			printf(", ");
	}
	printf("\n");
}
