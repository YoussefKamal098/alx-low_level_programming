#include "lists.h"

/**
 * reverse_listint - reverse_listint
 * Description:description
 * @head : head
 * Return:return
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *curr, *pre;

	curr = *head;
	pre = NULL;

	while (curr)
	{
		curr = curr->next;
		(*head)->next = pre;
		pre = *head;
		*head = curr;
	}

	*head = pre;

	return (*head);
}
