#include "hash_tables.h"
/**
 * hash_table_get - Retrieves the value associated with
 * a given key in a hash table
 * @ht: A pointer to the hash table
 * @key: The key to search for
 *
 * Return: On success, returns the value associated with the key.
 * On failure (if key is not found or if ht is NULL), returns NULL.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *curr;
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
