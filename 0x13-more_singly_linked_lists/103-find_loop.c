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
				return (ptr);
			ptr = ptr->next;
		}

		curr = curr->next;
	}

	return (NULL);
}
