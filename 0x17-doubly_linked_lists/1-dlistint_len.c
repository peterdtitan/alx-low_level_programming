#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * dlistint_len - Returns the number of elements in a linked dlist_t list.
 * @h: Head pointer
 * Return: number of elements.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t index = 0;

	while (h)
	{	h = h->next;
		index++;
	}

	return (index);
}
