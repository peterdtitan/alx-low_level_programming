#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list.
 * @head: Head pointer
 * @index: Index
 * Return: list.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;
	dlistint_t *current;

	if (head == NULL)
		return (NULL);

	current = head;

	i = 0;
	while (i < index) /* traverse til node */
	{
		if (current->next != NULL)
		{	current = current->next;
			i++;
		}
		else
			return (NULL);
	}
	return (current);
}
