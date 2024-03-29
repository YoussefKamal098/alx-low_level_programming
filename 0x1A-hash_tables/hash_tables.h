#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

/**
 * struct shash_node_s - Node of a sorted hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 * @sprev: A pointer to the previous element of the sorted linked list
 * @snext: A pointer to the next element of the sorted linked list
 */
typedef struct shash_node_s
{
	char *key;
	char *value;
	struct shash_node_s *next;
	struct shash_node_s *sprev;
	struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - Sorted hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 * @shead: A pointer to the first element of the sorted linked list
 * @stail: A pointer to the last element of the sorted linked list
 */
typedef struct shash_table_s
{
	unsigned long int size;
	shash_node_t **array;
	shash_node_t *shead;
	shash_node_t *stail;
} shash_table_t;

/**
 * hash_table_create - Creates a hash table with the specified size.
 * @size: Size of the hash table.
 *
 * Return: A pointer to the newly created hash table, or NULL on failure.
 */
hash_table_t *hash_table_create(unsigned long int size);

/**
 * hash_djb2 - implementation of the djb2 algorithm
 * @str: string used to generate hash value
 *
 * Return: hash value
 */
unsigned long int hash_djb2(const unsigned char *str);

/**
 * key_index - Computes the index in a hash table for a given key using
 * the djb2 hash function.
 * @key: A pointer to the unsigned char array representing the key.
 * @size: The size of the hash table.
 *
 * Return: The index in the hash table where the key should be stored.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size);

/**
 * hash_table_set - Adds or updates a key-value pair in the hash table.
 * @ht: The hash table in which to add or update the key-value pair.
 * @key: The key for the key-value pair.
 * @value: The value associated with the key.
 *
 * Return: 1 if successful, 0 on failure.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value);

/**
 * hash_table_get - Retrieves the value associated with
 * a given key in a hash table
 * @ht: A pointer to the hash table
 * @key: The key to search for
 *
 * Return: On success, returns the value associated with the key.
 * On failure (if key is not found or if ht is NULL), returns NULL.
 */
char *hash_table_get(const hash_table_t *ht, const char *key);

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
void hash_table_print(const hash_table_t *ht);

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
void hash_table_delete(hash_table_t *ht);

/* Sorted hash table functions */

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the hash table array
 *
 * Return: A pointer to the newly created sorted hash table,
 *         or NULL if memory allocation fails.
 */
shash_table_t *shash_table_create(unsigned long int size);

/**
 * shash_table_set - Adds or updates a key/value pair in a sorted hash table
 * @ht: A pointer to the sorted hash table
 * @key: The key string (non-empty)
 * @value: The value string (non-empty)
 *
 * Return: 1 on success, 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value);

/**
 * shash_table_get - Retrieves the value associated with a key
 * in a sorted hash table
 * @ht: A pointer to the sorted hash table
 * @key: The key string (non-empty)
 *
 * Return: The value associated with the key, or NULL if the key is not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key);

/**
 * shash_table_print - Prints the key/value pairs in a sorted hash table
 * @ht: A pointer to the sorted hash table
 */
void shash_table_print(const shash_table_t *ht);

/**
 * shash_table_print_rev - Prints the key/value pairs in reverse order
 * @ht: A pointer to the sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht);

/**
 * shash_table_delete - Deletes a sorted hash table and its contents
 * @ht: A pointer to the sorted hash table
 */
void shash_table_delete(shash_table_t *ht);

#endif /* HASH_TABLES_H */
