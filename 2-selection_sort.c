#include "sort.h"
/**
 * swap_ints - it swap two integers in an array
 * @q: a pointer to the first integer swap
 * @p: a pointer to the second integer swap
 */
void swap_ints(int *q, int *p)
{
	int tmp;

	tmp = *q;
	*q = *p;
	*p = tmp;
}
/**
 * selection_sort - it sort an array of integers in ascending order
 * using the selection sort algorithm.
 * @array: a pointer to an array of intergers
 * @size: the size of the array
 * Description: it prints the array after each swap
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t p, q;

	if (array == NULL || size < 2)
		return;
	for (p = 0; p < size - 1; p++)
	{
		min = array + p;
		for (q = p + 1; q < size; q++)
			min = (array[q] < *min) ? (array + q) : min;
		if ((array + p) != min)
		{
			swap_ints(array + p, min);
			print_array(array, size);
		}
	}
}
