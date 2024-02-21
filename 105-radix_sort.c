#include "sort.h"
int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);
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
/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 * in ascending order using the counting sort algorithm.
 * @array: a pointer to an array of integers.
 * @size: the size of the array.
 * @sig: the significant digit to sort on.
 * @buff: a pointer to a buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t q;

	for (q = 0; q < size; q++)
		count[(array[q] / sig) % 10] += 1;

	for (q = 0; q < 10; q++)
		count[q] += count[q - 1];

	for (q = size - 1; (int)q >= 0; q--)
	{
		buff[count[(array[q] / sig) % 10] - 1] = array[q];
		count[(array[q] / sig) % 10] -= 1;
	}

	for (q = 0; q < size; q++)
		array[q] = buff[q];
}
/**
 * radix_sort - it sort an array of integers in ascending
 * order using the radix sort algorithm.
 * @array: a pointer to an array of integers.
 * @size: the size of the array.
 * Description: it implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
