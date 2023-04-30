#include "lists.h"

/**
 * free_listint2 - free_listint2
 * @head : head
 * Description:description
 * Return:return
 */

void free_listint2(listint_t **head)
{
if (!head || !*head)
return;

listint_t *temp = *head;
listint_t *h = temp->next;



free_listint2(&h);

free(*head);
}
