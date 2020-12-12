#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/**
 * free_dlistint - Frees a list_t list.
 * @head: Head pointer
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current;
	dlistint_t *next;

	current = head; /* deref head to get the real head */

	while (current)
	{	next = current->next;
		free(current);
		current = next;
	}

}
