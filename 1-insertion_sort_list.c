/*
 * Insertion Sort Algorithm
 * Date: October, 25, 2021
 * Author: Johanne J. Lopez
 */

#include "sort.h"


/**
 * swap - Swap 2 nodes at a time.
 * @h: head pointer.
 * @n1: First node to swap.
 * @n2: Second node to be swap by 'n1'.
 */
void swap(listint_t *n1, listint_t *n2)
{
	listint_t *before = n2->prev;
	listint_t *after = n1->next;

	if (n1 == NULL || n2 == NULL)
		return;

	before->next = n1;
	n1->next = n2;
	n2->next = after;
}

/**
 * insertion_sort_list - Function that sorts doubly linked list (int)
 *                       in asending order using insertion algorithm.
 * @list: Head pointer.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *tmp;

	if (list == NULL || (*list)->next == NULL || *list == NULL)
		return;

	head = *list;

	for (; head != NULL; tmp = head->next)
	{
		while ( tmp->n > head->n)
		{
			swap(head, tmp);
			print_list(*list);
			if (head->next)
				head = head->next;
		}
	}
}
