#include "lists.h"

/**
 *delete_dnodeint_at_index - delete_dnodeint_at_index
 * @head : head
 * @index : index
 * Description:description
 * Return: 1 or -1
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp;

	if (!head || !*head)
		return (-1);

	temp = *head;

	for (; index != 0; index--)
	{
		if (!temp)
			return (-1);

		temp = temp->next;
	}

	if (temp == *head)
	{
		(*head) = (*head)->next;
		if (*head)
			(*head)->prev = NULL;
	}
	else
	{
		temp->prev->next = temp->next;
		if (temp->next)
			temp->next->prev = temp->prev;
	}

	free(temp);

	return (1);
}
