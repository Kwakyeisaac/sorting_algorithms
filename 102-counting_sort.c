#include "sort.h"
/**
 * counting_sort - it sort an array of integers in ascending order
 * using the counting sort algorithm.
 * @array: a pointer to an array of integers.
 * @size: the size of the array.
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, q;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (q = 0; q < (max + 1); q++)
		count[q] = 0;
	for (q = 0; q < (int)size; q++)
		count[array[q]] += 1;
	for (q = 0; q < (max + 1); q++)
		count[q] += count[q - 1];
	print_array(count, max + 1);

	for (q = 0; q < (int)size; q++)
	{
		sorted[count[array[q]] - 1] = array[q];
		count[array[q]] -= 1;
	}

	for (q = 0; q < (int)size; q++)
		array[q] = sorted[q];

	free(sorted);
	free(count);
}
/**
 * get_max - it get the maximum value in an array of integers.
 * @array: a pointer to an array of integers.
 * @size: the size of the array.
 * Return: the maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, q;

	for (max = array[0], q = 1; q < size; q++)
	{
		if (array[q] > max)
			max = array[q];
	}

	return (max);
}
