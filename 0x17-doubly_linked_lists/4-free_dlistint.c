#include "lists.h"

/**
 *free_dlistint - free_dlistint
 * @head : head
 * Description:description
 * Return: void
 */

void free_dlistint(dlistint_t *head)
{
if (!head)
return;

dlistint_t *curr = head;

while (curr->next)
{
free(curr->prev);
curr = curr->next;
}

free(curr->prev);
free(curr);
}
