#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * delete_dnodeint_at_index - Deletes the node at index index of a listint_t.
 * @head: Head pointer
 * @index: index
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node;
	unsigned int i = 0;

	if (!*head)
		return (-1);

	node = *head;

	while (i < index) /* traverse til node */
	{
		if (node->next != NULL)
		{	node = node->next;
			i++;
		}
		else
			return (-1);
	}

	if (!node)
		return (-1);

	if (index == 0) /* If head node to be deleted (idex == 0) */
	{	*head = node->next; /* Changed head */
		if (node->next)
			node->next->prev = NULL; /* prev of second node to NULL */
		free(node); /* free old head */
		return (1);
	}


	node->prev->next = node->next; /*jump node forward */
	if (node->next)
		node->next->prev = node->prev; /*jump node bakwards */
	free(node); /* Free memory */
	return (1);
}
