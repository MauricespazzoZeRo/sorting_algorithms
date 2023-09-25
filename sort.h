#ifndef SORT
#define SORT
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @next: Pointer to the next element of the list
 * @prev: Pointer to the previous element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void my_sort(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
void swap(int *array, int i, int j);
void merge_sort(int *array, size_t size);
void sort(int *array, int low, int high, int *temp);
void merge(int *arrayA, int low, int mid, int high, int *temp);
int len(int *array);
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t i, size_t max_size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **a, listint_t **b, listint_t **list);
void print_counting_array(int *count, int max_value);
void counting_sort(int *array, size_t size);
int get_max(int *array, size_t size);
void Sig_sort(int *array, size_t size, int exp);
void radix_sort(int *array, size_t size);
void bitonic_compare_swap(int *array, size_t low, size_t count, int dir);
void bitonic_sort_recursive(int *array, size_t size, size_t low, size_t count, int dir);
void bitonic_sort(int *array, size_t size);
void bitonic_merge(int *array, size_t low, size_t count, int dir);
int hoare_partition(int *array, int low, int high, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif /* SORT */
