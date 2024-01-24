#include "lists.h"

/**
 *  delete_nodeint_at_index -  delete_nodeint_at_index
 * Description:description
 * @head : head
 * @index : index
 * Return:return
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *curr, *pre;
	unsigned int i = 0;

	if (!head || !*head)
		return (-1);

	curr = *head;

	if (!index)
	{
		*head = curr->next;
		free(curr);

		return (1);
	}

	while (curr)
	{
		if (i == index)
		{
			pre->next = curr->next;
			free(curr);
			return (1);
		}

		i++;
		pre = curr;
		curr = curr->next;
	}

	return (-1);
}
