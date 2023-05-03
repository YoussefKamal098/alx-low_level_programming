#include "lists.h"

/**
 * insert_nodeint_at_index - insert_nodeint_at_index
 * Description:description
 * @head : head
 * @idx : idx
 * @n : n
 * Return:return
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
listint_t *new = malloc(sizeof(listint_t)), *curr;
unsigned int i = 0;

if (!new || !head)
return (NULL);

new->n = n;

if (!idx)
{
new->next = *head;
*head = new;
return (new);
}

curr = *head;

while (curr)
{
if (i == idx - 1)
{
new->next = curr->next;
curr->next = new;
return (new);
}
i++;
curr = curr->next;
}

free(new);
return (NULL);
}
