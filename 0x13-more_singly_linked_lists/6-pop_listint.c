#include "lists.h"

/**
 * pop_listint - pop_listint
 * Description:description
 * @head : head
 * Return:return
 */

int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n;

	if (!head || !*head)
		return (0);

	temp = *head;
	n = temp->n;
	*head = temp->next;

	free(temp);

	return (n);
}
