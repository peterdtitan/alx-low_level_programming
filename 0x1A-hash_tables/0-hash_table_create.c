#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table.
 *
 * @size: Hash table size
 * Return: Pointer to the newly created hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table = NULL;
	hash_node_t **array = NULL;
	unsigned long int index;


	/* allocate table */
	hash_table = malloc(sizeof(hash_table_t));
	if (hash_table == NULL)
		return (NULL);

	hash_table->size = size;

	/* allocate array */
	array = malloc(size * sizeof(hash_node_t *));
	if (array == NULL)
		return (NULL);

	/* initialize array */
	for (index = 0; index < size; index++)
		array[index] = NULL;


	hash_table->array = array;

	return (hash_table);
}
