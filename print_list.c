#include <stdio.h>
#include "sort.h"
/**
 * print_list - it prints a list of integers
 * @list: a pointer to the list to be printed
 */
void print_list(const listint_t *list)
{
	int q;

	q = 0;
	while (list)
	{
		if (q > 0) printf(", ");
		printf("%d",list->n);
		++q;
		list = list->next;
	}
	printf("\n");
}
