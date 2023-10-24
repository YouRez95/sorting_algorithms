#include "sort.h"
#include <stdio.h>
/**
 * insertion_sort_list - insertion sort in a doubly linked list
 *
 * @list: list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *node, *temp;

	current = (*list)->next;
	while (current)
	{
		node = current;
		current = current->next;
		while (node->prev && node->n < node->prev->n)
		{
			temp = node->prev;
			if (node->next)
				node->next->prev = temp;
			temp->next = node->next;
			node->prev = temp->prev;
			node->next = temp;
			if (temp->prev)
				temp->prev->next = node;
			temp->prev = node;
			if (temp == *list)
				*list = node;
			print_list(*list);
		}
	}
}
