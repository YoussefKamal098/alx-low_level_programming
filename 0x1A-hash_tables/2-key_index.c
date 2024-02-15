#include "hash_tables.h"

/**
 * key_index - Computes the index in a hash table for a given key using
 * the djb2 hash function.
 * @key: A pointer to the unsigned char array representing the key.
 * @size: The size of the hash table.
 *
 * Return: The index in the hash table where the key should be stored.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
