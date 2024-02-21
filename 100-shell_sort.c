#include "sort.h"
/**
 * swap_ints - it swap two integers in an array
 * @p: a pointer to the first integer to swap
 * @q: a pointer to the second integer to swap
 */
void swap_ints(int *p, int *q)
{
	int tmp;

	tmp = *p;
	*p = *q;
	*q = tmp;
}
/**
 * shell_sort - it sort an array of integers in ascending
 * order using the shell sort algorithm
 * @array: a pointer an array of integers
 * @size: the size of the array
 *
 * Description: it uses the Knuth interval sequence
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, u, v;

	if (array == NULL || size < 2)
		return;
	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;
	for (; gap >= 1; gap /= 3)
	{
		for (u = gap; u < size; u++)
		{
			v = u;
			while (v >= gap && array[v - gap] > array[v])
			{
				swap_ints(array + v, array + (v - gap));
				v -= gap;
			}
		}
		print_array(array, size);
	}
}
