#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * sum_dlistint - Returns the nth node of a listint_t linked list.
 * @head: Head pointer
 * Return: sum all.
 */

int sum_dlistint(dlistint_t *head)
{
	dlistint_t *node;
	int sum = 0;

	if (head == NULL)
		return (0);

	node = head;

	while (node->next != NULL)
	{	sum = sum + node->n;
		node = node->next;
	}

	sum = sum + node->n;

	return (sum);
}
