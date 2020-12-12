#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 * @h: Head pointer
 * @idx: index
 * @n: value
 * Return: nth node.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *node = *h;
	unsigned int i = 0;

	if (idx == 0) /* beginning */
		return (add_dnodeint(h, n));

	while (i < idx - 1)  /* traverse list */
	{	node = node->next;
		if (!node)
			return (NULL);
		i++;
	}

	if (!node->next) /*end */
		return (add_dnodeint_end(h, n));

	new_node = malloc(sizeof(dlistint_t)); /* allocate node */
	if (!new_node)
		return (NULL);

	new_node->n = n; /* put in the data  */
	new_node->prev = node; /* Make prev_node as previous of new_node */
	new_node->next = node->next;
	node->next->prev = new_node;
	node->next = new_node;
	return (new_node);
}
