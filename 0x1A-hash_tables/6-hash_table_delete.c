#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table.
 *
 * @ht: The hash table
 */

void hash_table_delete(hash_table_t *ht)
{
	unsigned int index = 0;
	hash_node_t *node = NULL;
	hash_node_t *aux = NULL;

	for (index = 0; index < ht->size; index++)
	{
		if (ht->array[index] != NULL)
		{
			node = ht->array[index];
			while (node)
			{
				aux = node;
				node = node->next;
				free(aux->value);
				free(aux->key);
				free(aux);
			}
		}
	}
	free(ht->array);
	free(ht);
}
