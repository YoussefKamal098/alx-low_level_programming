#include "lists.h"

/**
 *sum_dlistint - sum_dlistint
 * @head : head
 * Description:description
 * Return: sum
 */

int sum_dlistint(dlistint_t *head)
{
	dlistint_t *temp = head;
	int sum = 0;

	if (!head)
		return (0);

	while (temp)
	{
		sum += temp->n;
		temp = temp->next;
	}

	return (sum);
}
