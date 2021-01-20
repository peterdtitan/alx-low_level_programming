#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * shash_table_create - creates a hash table.
 *
 * @size: Hash table size
 * Return: Pointer to the newly created hash table.
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *shash_table = NULL;
	shash_node_t **array = NULL;
	unsigned long int index;


	/* allocate table */
	shash_table = malloc(sizeof(shash_table_t));
	if (shash_table == NULL)
		return (NULL);

	shash_table->size = size;

	/* allocate array */
	array = malloc(size * sizeof(shash_node_t *));
	if (array == NULL)
		return (NULL);

	/* initialize array */
	for (index = 0; index < size; index++)
		array[index] = NULL;


	shash_table->array = array;
	shash_table->shead = NULL;
	shash_table->stail = NULL;

	return (shash_table);
}


/**
 * shash_table_set - Adds an element to the hash table.
 * @ht: hash table to add or update the key/value to
 * @key: the key
 * @value: the value associated with the key
 * Return: 1 if it succeeded, 0 otherwise
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	shash_node_t *new_node = NULL;
	shash_node_t *existing_node = NULL;

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
		new_node = malloc(sizeof(shash_node_t));
		if (new_node == NULL)
			return (0);
		new_node->key = strdup(key);
		new_node->value = strdup(value);
		new_node->next = ht->array[index]; /* new_node in front of list */
		sort_node(ht, new_node);
	}
	else
	{
		new_node = malloc(sizeof(shash_node_t));
		if (new_node == NULL)
			return (0);
		new_node->key = strdup(key);
		new_node->value = strdup(value);
		new_node->next = NULL;
		sort_node(ht, new_node);
	}
	ht->array[index] = new_node; /* array[index] pointing to new_node */
	return (1);
}

/**
 * sort_node - Sorts list.
 * @ht: hash table to look into
 * @new_node: inserted node
 * Return: value associated with the element, or NULL if key couldnt be found
 */

void sort_node(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *node = NULL;

	if (!ht->shead)
	{
		ht->shead = new_node;
		ht->stail = new_node;
		new_node->sprev = NULL;
		new_node->snext = NULL;
		return;
	}
	node = ht->shead;

	while (node)
	{
		if (strcmp(new_node->key, node->key) <= 0)
		{
			new_node->snext = node;
			new_node->sprev = node->sprev;

			if (node->sprev)
				node->sprev->snext = new_node;
			else
				ht->shead = new_node;

			node->sprev = new_node;
			return;

		}
		node = node->snext;
	}
	ht->stail->snext = new_node;
	new_node->sprev = ht->stail;
	ht->stail = new_node;

}


/**
 * shash_table_get - Retrieves a value associated with a key.
 * @ht: hash table to look into
 * @key: the key
 * Return: value associated with the element, or NULL if key couldnt be found
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node;
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

/**
 * shash_table_print - Retrieves a value associated with a key.
 * @ht: hash table to look into
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node = NULL;
	int counter = 0;

	if (!ht)
		return;

	printf("{");
	node = ht->shead;
	if (node)
	{
		while (node)
		{
			if (counter != 0)
				printf(", ");
			printf("'%s': '%s'", node->key, node->value);
			counter++;
			node = node->snext;
		}
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Retrieves a value associated with a key.
 * @ht: hash table to look into
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node = NULL;
	int counter = 0;

	if (!ht)
		return;

	printf("{");
	node = ht->stail;
	if (node)
	{
		while (node)
		{
			if (counter != 0)
				printf(", ");
			printf("'%s': '%s'", node->key, node->value);
			counter++;
			node = node->sprev;
		}
	}
	printf("}\n");
}


/**
 * shash_table_delete - deletes a hash table.
 *
 * @ht: The hash table
 */

void shash_table_delete(shash_table_t *ht)
{
	unsigned int index = 0;
	shash_node_t *node = NULL;
	shash_node_t *aux = NULL;

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
