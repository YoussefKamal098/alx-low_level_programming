#include "hash_tables.h"

/**
 * create_hash_node - Creates a new hash node with the specified key and value.
 * @key: The key for the new hash node.
 * @value: The value associated with the key for the new hash node.
 *
 * Return: A pointer to the newly created hash node, or NULL on failure.
 */
hash_node_t *create_hash_node(const char *key, const char *value);

/**
 * hash_table_set - Adds or updates a key-value pair in the hash table.
 * @ht: The hash table in which to add or update the key-value pair.
 * @key: The key for the key-value pair.
 * @value: The value associated with the key.
 *
 * Return: 1 if successful, 0 on failure.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *curr, *node;
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

	node = create_hash_node(key, value);
	if (!node)
		return (0);

	node->next = ht->array[index];
	ht->array[index] = node;

	return (1);
}

/**
 * create_hash_node - Creates a new hash node with the specified key and value.
 * @key: The key for the new hash node.
 * @value: The value associated with the key for the new hash node.
 *
 * Return: A pointer to the newly created hash node, or NULL on failure.
 */
hash_node_t *create_hash_node(const char *key, const char *value)
{
	hash_node_t *node = (hash_node_t *)malloc(sizeof(hash_node_t));

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

	return (node);
}
