#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_print - Retrieves a value associated with a key.
 * @ht: hash table to look into
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned int index = 0;
	hash_node_t *node;
	int counter = 0;

	if (!ht)
		return;

	printf("{");
	for (index = 0; index < ht->size; index++)
	{
		node = ht->array[index];
		if (node)
		{
			while (node)
			{
				if (counter != 0)
					printf(", ");
				printf("'%s': '%s'", node->key, node->value);
				counter++;
				node = node->next;
			}
		}
	}
	printf("}\n");
}
