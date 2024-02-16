#include "hash_tables.h"

shash_node_t *create_shash_node(const char *key, const char *value);
void add_to_sorted_list(shash_table_t *table, shash_node_t *node);

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the hash table array
 *
 * Return: A pointer to the newly created sorted hash table,
 *         or NULL if memory allocation fails.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table;
	size_t i;

	table = (shash_table_t *)malloc(sizeof(shash_table_t));

	if (!table)
		return (NULL);

	table->size = size;
	table->array = (shash_node_t **)malloc(sizeof(shash_node_t *) * size);

	if (!table->array)
	{
		free(table);
		return (NULL);
	}

	for (i = 0; i < table->size; i++)
		table->array[i] = NULL;

	table->shead = NULL;
	table->stail = NULL;

	return (table);
}

/**
 * shash_table_set - Adds or updates a key/value pair in a sorted hash table
 * @ht: A pointer to the sorted hash table
 * @key: The key string (non-empty)
 * @value: The value string (non-empty)
 *
 * Return: 1 on success, 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *curr, *node;
	char *old_value = NULL;
	size_t index;

	if (!ht || !ht->array || !ht->size || !key || !value || !*key)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	curr = ht->array[index];

	while (curr)
	{
		if (strcmp(key, curr->key) == 0)
		{
			old_value = curr->value;
			curr->value = strdup(value);

			if (!curr->value)
			{
				curr->value = old_value;
				return (0);
			}

			free(old_value);
			return (1);
		}

		curr = curr->next;
	}

	node = create_shash_node(key, value);
	if (!node)
		return (0);

	node->next = ht->array[index];
	ht->array[index] = node;
	add_to_sorted_list(ht, node);

	return (1);
}

/**
 * shash_table_get - Retrieves the value associated with a key
 * in a sorted hash table
 * @ht: A pointer to the sorted hash table
 * @key: The key string (non-empty)
 *
 * Return: The value associated with the key, or NULL if the key is not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *curr;
	size_t index;

	if (!ht || !ht->array || !ht->size || !key || !*key)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	curr = ht->array[index];

	while (curr)
	{
		if (strcmp(key, curr->key) == 0)
			return (curr->value);

		curr = curr->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints the key/value pairs in a sorted hash table
 * @ht: A pointer to the sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *curr;
	bool flag = false;

	if (!ht || !ht->array || !ht->size)
		return;

	printf("{");
	curr = ht->shead;
	while (curr)
	{
		if (flag)
			printf(", ");
		printf("'%s': '%s'", curr->key, curr->value);
		flag = true;
		curr = curr->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the key/value pairs in reverse order
 * @ht: A pointer to the sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *curr;
	bool flag = false;

	if (!ht || !ht->array || !ht->size)
		return;

	printf("{");
	curr = ht->stail;
	while (curr)
	{
		if (flag)
			printf(", ");
		printf("'%s': '%s'", curr->key, curr->value);
		flag = true;
		curr = curr->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table and its contents
 * @ht: A pointer to the sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *curr, *pre;
	size_t i;

	if (!ht || !ht->array || !ht->size)
		return;

	for (i = 0; i < ht->size; i++)
	{
		curr = ht->array[i];
		while (curr)
		{
			pre = curr;
			curr = curr->next;

			free(pre->key);
			free(pre->value);
			free(pre);
		}

		ht->array[i] = NULL;
	}

	free(ht->array);
	ht->array = NULL;
	ht->size = 0;
	ht->shead = NULL;
	ht->stail = NULL;
	free(ht);
}

/**
 * create_shash_node - Creates a new node for a sorted hash table
 * @key: The key string (non-empty)
 * @value: The value string (non-empty)
 *
 * Return: A pointer to the newly created node,
 *         or NULL if memory allocation fails or invalid input.
 */
shash_node_t *create_shash_node(const char *key, const char *value)
{
	shash_node_t *node = (shash_node_t *)malloc(sizeof(shash_node_t));

	if (!node || !key || !value || !*key || !*value)
		return (0);

	node->key = strdup(key);
	if (!node->key)
	{
		free(node);
		return (NULL);
	}

	node->value = strdup(value);
	if (!node->value)
	{
		free(node->key);
		free(node);
		return (NULL);
	}

	node->next = NULL;
	node->snext = NULL;
	node->sprev = NULL;

	return (node);
}

/**
 * add_to_sorted_list - Adds a node to a sorted linked list in a hash table
 * @table: A pointer to the sorted hash table
 * @node: A pointer to the node to be added to the sorted linked list
 */
void add_to_sorted_list(shash_table_t *table, shash_node_t *node)
{
	shash_node_t *curr;

	if (!table || !node)
		return;

	if (!table->shead && !table->stail)
	{
		table->shead = table->stail = node;
		return;
	}

	curr = table->shead;
	while (curr)
	{
		if (strcmp(node->key, curr->key) < 0)
		{
			node->snext = curr;
			node->sprev = curr->sprev;
			curr->sprev = node;

			if (node->sprev)
				node->sprev->snext = node;
			else
				table->shead = node;

			return;
		}

		curr = curr->snext;
	}

	node->sprev = table->stail;
	table->stail->snext = node;
	table->stail = node;
}
