#include "sort.h"
#include <stdio.h>
/*
 *
 */

void insertion_sort_list(listint_t **list)
{
	size_t i, j;
	size_t length;
	listint_t *node1;
	listint_t *node2;
	listint_t *node3;

	length = 0;
	node1 = *list;
	while (node1)
	{
		length++;
		node1 = node1->next;
	}

	node1 = *list;
	for (i = 1; i < length - 1; i++)
	{
		node2 = node1->next;
		node3 = node2->next;
		j = i - 1;
		while (j >= 0 && node1->n > node2->n)
		{
			node2->next = node1;
			node2->prev = node1->prev;
			node1->next = node3;
			node1->prev = node2;
			node2->prev->next = node1;
			node3->prev = node1;
			node1 = node3;
			print_list(*list);
		}
	}
}
