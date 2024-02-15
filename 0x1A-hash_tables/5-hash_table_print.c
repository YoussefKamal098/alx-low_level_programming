#include "hash_tables.h"

/**
 * hash_table_print - Prints the content of a hash table
 * @ht: A pointer to the hash table
 *
 * This function prints the key-value pairs of a hash table
 * in the following format:
 * {'key': 'value', 'key': 'value', ...}
 * If the hash table or its array is NULL, or if its size is zero,
 * the function does nothing.
 *
 * Note: The order of key-value pairs might not be the same as
 * the insertion order.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *curr;
	size_t i;
	bool flag = false;

	if (!ht || !ht->array || !ht->size)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		curr = ht->array[i];

		while (curr)
		{
			if (flag)
				printf(", ");

			printf("'%s': '%s'", curr->key, curr->value);

			flag = true;
			curr = curr->next;
		}
	}
	printf("}\n");
}
