#include "lists.h"

/**
 * free_listint - free_listint
 * Description:description
 * @head : head
 * Return:return
 */

void free_listint(listint_t *head)
{
if (!head)
return;

free_listint(head->next);
free(head);
}

