#include "lists.h"

/**
 *get_dnodeint_at_index - get_dnodeint_at_index
 * @head : head
 * @index : index
 * Description:description
 * Return: node or NULL
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *temp = head;
	size_t idx = 0;

	if (!head)
		return (NULL);

	while (temp)
	{
		if (idx == index)
			return (temp);

		temp = temp->next;
		idx++;
	}

	return (NULL);
}
