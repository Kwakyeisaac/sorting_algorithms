#include "sort.h"
/**
 * swap_ints - it swap two integers in an array.
 * @a: a pointer to the first integer to swap.
 * @b: a pointer to the second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - it sort an array of integers in ascending order.
 * @array: a pointer to an array of integers to sort.
 * @size: the size of the array
 *
 * Description: it prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t q, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;
	while (bubbly == false)
	{
		bubbly = true;
		for (q = 0; q < len - 1; q++)
		{
			if (array[q] > array[q + 1])
			{
				swap_ints(array + q, array + q + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
