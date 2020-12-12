#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * add_dnodeint - Adds a new node at the beginning of a list_t list.
 * @head: Head pointer
 * @n: Data
 * Return: dlist.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t)); /* 1. allocate node */
	if (new_node == NULL)
		return (NULL);

	new_node->n = n; /* put in the data  */
	new_node->prev = NULL; /* Make prev of new node as NULL */

	if (!*head)
	{	new_node->next =  NULL;
		*head = new_node;
		return (new_node);
	}

	new_node->next = *head; /* Point next of new node to old head */
	(*head)->prev = new_node; /* change prev of head node to new node */
	*head = new_node; /* move the head to point to the new node */
	return (new_node);
}
