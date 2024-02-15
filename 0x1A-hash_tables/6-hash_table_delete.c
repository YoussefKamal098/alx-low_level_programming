#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table and its contents
 * @ht: A pointer to the hash table to be deleted
 *
 * This function frees the memory occupied by a hash table,
 * including its nodes,
 * keys, values, and array. If the hash table, its array,
 * or its size is zero, the
 * function does nothing.
 *
 * Note: After calling this function,
 * the hash table pointer should be set to NULL.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *curr, *pre;
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
	free(ht);
}
