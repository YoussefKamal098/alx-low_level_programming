#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 *
 * @list: Pointer to the head of the skip list.
 * @value: The value to search for.
 *
 * Description:
 * The linear_skip function searches for a specified value in a
 * sorted skip list of integers. The skip list is a modified linked list that
 * includes an "express lane" to speed up the search process. The function
 * first uses the express lane to narrow down the range where the
 * value might be, and then performs a linear search within that range.
 *
 * The function prints each value it checks, both in the express lane and
 * in the linear search range.
 *
 * Parameters:
 *  - list: A pointer to the head of the skip list.
 *  - value: The value to search for within the skip list.
 *
 * Return:
 *  - A pointer to the first node where the value is located.
 *  - NULL if the value is not present in the list or if the list is NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *left, *right;

	if (list == NULL)
		return (NULL);

	left = list;
	right = list->express;

	while (right != NULL && right->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", right->index, right->n);
		left = right;
		right = right->express;
	}

	if (right == NULL)
	{
		right = left;
		while (right->next != NULL)
			right = right->next;
	} else
	{
		printf("Value checked at index [%lu] = [%d]\n", right->index, right->n);
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       left->index, right->index);

	while (left != NULL && left->index <= right->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", left->index, left->n);
		if (left->n == value)
			return (left);
		left = left->next;
	}

	return (NULL);
}
