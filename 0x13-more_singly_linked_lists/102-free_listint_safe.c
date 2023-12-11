#include "lists.h"
/**
 * find_loop - find_loop
 * @head:head
 * Return: return
 */

listint_t *find_loop(listint_t *head)
{

	listint_t *curr, *ptr;

	if (!head)
		return (NULL);

	curr = head;
	while (curr)
	{
		if (curr == curr->next)
			return (curr);

		ptr = head;
		while (ptr != curr)
		{
			if (curr->next == ptr)
				return (curr);
			ptr = ptr->next;
		}

		curr = curr->next;
	}

	return (NULL);
}

/**
 * free_listint_safe - free_listint_safe
 * @h:h
 * Return: return
 */

size_t free_listint_safe(listint_t **h)
{
	listint_t *temp, *curr, *start_loop_node;
	size_t size = 0;

	if (!h || !*h)
		return (size);

	start_loop_node = find_loop(*h);
	curr = *h;

	while (curr)
	{

		temp = curr;
		curr = curr->next;

		if (temp == start_loop_node)
		{
			free(temp);
			*h = NULL;
			return (size);
		}

		free(temp);
		size++;
	}
	*h = NULL;
	return (size);
}
