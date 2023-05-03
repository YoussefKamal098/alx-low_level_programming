#include "lists.h"

/**
 * free_listint2 - free_listint2
 * @head : head
 * Description:description
 * Return:return
 */

void free_listint2(listint_t **head)
{
listint_t *h = (*head)->next;

if (!head || !*head)
return;

free_listint2(&h);

free(*head);
}
