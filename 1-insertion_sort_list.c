#include "sort.h"
/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: a pointer to the head of the doubly-linked list.
 * @nl: a pointer to the first node to swap
 * @n2: a pointer to the second node to swap
 */
void swap_nodes(listint_t **h, listint_t **nl, listint_t *n2)
{
	(*nl)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *nl;
	n2->prev = (*nl)->prev;
	n2->next = *nl;
	if ((*nl)->prev != NULL)
		(*nl)->prev->next = n2;
	else
		*h = n2;
	(*nl)->prev = n2;
	*nl = n2->prev;
}
/**
 * insertion_sort_list - it sort a doubly linked list of integers
 * using the insertion sort algorithm
 * @list: a pointer to the head of a doubly-linked list of integers
 * Description: it prints the list after each swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
