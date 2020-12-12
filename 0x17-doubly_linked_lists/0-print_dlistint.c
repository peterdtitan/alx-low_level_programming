#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * print_dlistint - Prints all the elements of a dlist_t list.
 * @h: Head pointer
 * Return: number of elements.
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t index = 0;

	while (h)
	{
		printf("%i\n", h->n);
		h = h->next;
		index++;
	}

	return (index);
}
