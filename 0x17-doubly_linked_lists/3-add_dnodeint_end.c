#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/**
 * add_dnodeint_end - Adds a new node at the end of a dlist_t list.
 * @head: Head pointer
 * @n: Data
 * Return: list.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *node;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(list_t)); /* 1. allocate node */
	if (new_node == NULL)
		return (NULL);

	node = *head;
	new_node->n = n; /* put in the data  */
	new_node->next = NULL; /* New node is last node, next of it as NULL*/

	if (!*head) /* If Linked List is empty, new node as head */
	{	new_node->prev = NULL;
		*head = new_node;
		return (*head);
	}
	while (node->next) /* Traverse till the last node */
		node = node->next;

	node->next = new_node; /* Change the next of last node */
	new_node->prev = node; /* Prev of new node to last node */
	return (new_node);
}
