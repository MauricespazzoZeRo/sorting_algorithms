#include "sort.h"

/**
 * heapify - Organizes the array into a max heap.
 * @array: The array to be organized.
 * @size: The size of the array.
 * @i: The root index.
 * @max_size: The original size of the array for printing.
 */
void heapify(int *array, size_t size, size_t i, size_t max_size)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;
	int temp;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;
		print_array(array, max_size);
		heapify(array, size, largest, max_size);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	ssize_t i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Build a max heap */
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	/* Extract elements one by one */
	for (j = size - 1; j >= 0; j--)
	{
		temp = array[0];
		array[0] = array[j];
		array[j] = temp;
		print_array(array, size);
		heapify(array, j, 0, size);
	}
}
