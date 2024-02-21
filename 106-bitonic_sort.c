/*
 * File: 106-bitonic_sort.c
 * Auth: Brennan D Baraban
 */
#include "sort.h"
void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - it swap two integers in an array.
 * @p: a pointer to the first integer to swap.
 * @q: a pointer to the second integer to swap.
 */
void swap_ints(int *p, int *q)
{
	int tmp;

	tmp = *p;
	*p = *q;
	*q = tmp;
}

/**
 * bitonic_merge - it sort a bitonic sequence inside an array of integers.
 * @array: a pointer to an array of integers.
 * @size: the size of the array.
 * @start: the starting index of the sequence in array to sort.
 * @seq: the size of the sequence to sort.
 * @flow: the direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t q, jump = seq / 2;

	if (seq > 1)
	{
		for (q = start; q < start + jump; q++)
		{
			if ((flow == UP && array[q] > array[q + jump]) ||
			    (flow == DOWN && array[q] < array[q + jump]))
				swap_ints(array + q, array + q + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}
/**
 * bitonic_seq - it convert an array of integers into a bitonic sequence.
 * @array: a pointer to an array of integers.
 * @size: the size of the array.
 * @start: the starting index of a block of the building bitonic sequence.
 * @seq: the size of a block of the building bitonic sequence.
 * @flow: the direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}
/**
 * bitonic_sort - it sort an array of integers in ascending
 * order using the bitonic sort algorithm.
 * @array: a pointer to an array of integers.
 * @size: the size of the array.
 * Description: it prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
