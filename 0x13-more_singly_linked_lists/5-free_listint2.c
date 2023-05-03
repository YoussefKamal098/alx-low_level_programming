#include "lists.h"

/**
 * free_listint2 - free_listint2
 * @head : head
 * Description:description
 * Return:return
 */

void free_listint2(listint_t **head)
{
listint_t *curr, *temp;

if (!head || !*head)
return;

while (curr)
{
temp = curr;
curr = curr->next;
free(curr);
}
}
