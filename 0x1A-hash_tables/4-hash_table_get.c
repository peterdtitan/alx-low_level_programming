#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key.
 * @ht: hash table to look into
 * @key: the key
 * Return: value associated with the element, or NULL if key couldnt be found
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *node;
	const unsigned char *u_key;

	if (strcmp(key, "") == 0 || !ht)
		return (0);

	u_key = (const unsigned char *) key;

	/* get the hash */
	index = key_index(u_key, ht->size);

	if (ht->array[index] == NULL)
		return (NULL);

	node = ht->array[index];
	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}
