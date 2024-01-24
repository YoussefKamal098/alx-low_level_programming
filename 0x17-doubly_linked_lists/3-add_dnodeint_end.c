#include "lists.h"

/**
 *add_dnodeint_end - add_dnodeint_end
 * @head : head
 * @n : data
 * Description:description
 * Return: node or NULL
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *const node = malloc(sizeof(dlistint_t));
	dlistint_t *temp;

	if (!head || !node)
	{
		free(node);
		return (NULL);
	}

	node->n = n;

	if (!*head)
	{
		*head = node;
		return (node);
	}

	temp = *head;

	while (temp->next)
	{
		temp = temp->next;
	}

	temp->next = node;
	node->prev = temp;

	return (node);
}
