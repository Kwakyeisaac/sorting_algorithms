#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - it sort a subarray of integers.
 * @subarr: a pointer to subarray of an array of integers to sort.
 * @buff: a poiner to buffer to store the sorted subarray.
 * @front: the front index of the array.
 * @mid: the middle index of the array.
 * @back: the back index of the array.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t u, v, w = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (u = front, v = mid; u < mid && v < back; w++)
		buff[w] = (subarr[u] < subarr[v]) ? subarr[u++] : subarr[v++];
	for (; u < mid; u++)
		buff[w++] = subarr[u];
	for (; v < back; v++)
		buff[w++] = subarr[v];
	for (u = front, w = 0; u < back; u++)
		subarr[u] = buff[w++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - it implement the merge sort
 * algorithm through recursion.
 * @subarr: a pointer subarray of an array of integers to sort.
 * @buff: a pointer to buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - it sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: a pointer to an array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
