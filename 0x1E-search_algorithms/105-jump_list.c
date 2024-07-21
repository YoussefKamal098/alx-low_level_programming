#include "search_algos.h"
#include <math.h>

static listint_t *move_forward(listint_t *list, size_t jump);

/**
 * jump_list - Searches for a value in a sorted singly linked list using the
 *             Jump Search algorithm.
 *
 * This function performs a search on a sorted singly linked list to locate
 * the target value using the Jump Search algorithm. It efficiently narrows
 * down the search range by jumping ahead by a fixed number of nodes, and
 * then performs a linear search within the identified range.
 *
 * @list: Pointer to the head of the linked list.
 * @size: The number of elements in the linked list.
 * @value: The value to search for.
 *
 * Return: A pointer to the node containing the value if found, or
 *         NULL if the value is not present in the linked list.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump;
	listint_t *left, *right;

	if (list == NULL || size == 0)
		return (NULL);

	jump = (size_t) sqrt((double) size);
	right = list;

	while (right->index < (size - 1) && right->n < value)
	{
		left = right;
		right = move_forward(right, jump);
		if (right == NULL)
			return (NULL);

		printf("Value checked at index [%lu] = [%d]\n", right->index, right->n);
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       left->index, right->index);

	printf("Value checked at index [%lu] = [%d]\n", left->index, left->n);

	while (left->index < (size - 1) && left->n < value)
	{
		left = left->next;
		if (left == NULL)
			return (NULL);

		printf("Value checked at index [%lu] = [%d]\n", left->index, left->n);
	}

	if (left->n == value)
		return (left);

	return (NULL);
}

/**
 * move_forward - Moves forward by a specified number of nodes in a singly
 *                linked list.
 *
 * This helper function advances the given list pointer by the specified
 * number of nodes, or until the end of the list is reached.
 *
 * @list: Pointer to the current node in the linked list.
 * @jump: The number of nodes to move forward.
 *
 * Return: A pointer to the node reached after moving forward, or
 *         NULL if the end of the list is reached before the specified
 *         number of nodes.
 */
listint_t *move_forward(listint_t *list, size_t jump)
{
	if (list == NULL || jump == 0)
		return (NULL);

	while (list->next != NULL && jump--)
		list = list->next;

	return (list);
}
