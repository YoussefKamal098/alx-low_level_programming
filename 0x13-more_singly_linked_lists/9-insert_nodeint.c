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
listint_t *new = malloc(sizeof(listint_t)), *curr, *pre;
if (!new)
return (NULL);
if (!head || (!*head && idx))
{
free(new);
return (NULL);
}
new->n = n;
if (!*head)
{
*head = new;
return (new);
}
if (!idx)
{
new->next = *head;
*head = new;
return (new);
}
curr = *head;
pre = NULL;
while (idx-- && curr)
{
pre = curr;
curr = curr->next;
}
if (idx == -1)
{
new->next = curr;
pre->next = new;
return (new);
}
free(new);
return (NULL);
}


