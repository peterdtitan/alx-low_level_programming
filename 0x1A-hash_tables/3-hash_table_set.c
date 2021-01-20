#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to the hash table.
 * @ht: hash table to add or update the key/value to
 * @key: the key
 * @value: the value associated with the key
 * Return: 1 if it succeeded, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	hash_node_t *new_node = NULL;
	hash_node_t *existing_node = NULL;

	if (strcmp(key, "") == 0 || !ht)
		return (0);
	index = key_index((const unsigned char *)key, ht->size); /* get the hash */
	if (ht->array[index] != NULL) /* evaluate collision */
	{
		existing_node = ht->array[index];
		while (existing_node)
		{
			if (strcmp(existing_node->key, key) == 0)
			{	free(existing_node->value);
				existing_node->value = strdup(value); /* update */
				return (1);
			}
			existing_node = existing_node->next;
		}
		new_node = malloc(sizeof(hash_node_t));
		if (new_node == NULL)
			return (0);
		new_node->key = strdup(key);
		new_node->value = strdup(value);
		new_node->next = ht->array[index]; /* new_node in front of list */
	}
	else
	{
		new_node = malloc(sizeof(hash_node_t));
		if (new_node == NULL)
			return (0);
		new_node->key = strdup(key);
		new_node->value = strdup(value);
		new_node->next = NULL;
	}
	ht->array[index] = new_node; /* array[index] pointing to new_node */
	return (1);
}
