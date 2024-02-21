#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - it prints an array of integers
 *
 * @array: a pointer to the array to be printed
 * @size: the number of elements in @array.
 */
void print_array(const int *array, size_t size)
{
	size_t q;

	q = 0;
	while (array && q < size)
	{
		if (q > 0)
		printf(", ");
		printf("%d", array[q]);
		++q;
	}
	printf("\n");
}
