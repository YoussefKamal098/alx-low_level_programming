#include "lists.h"

/**
 *insert_dnodeint_at_index - insert_dnodeint_at_index
 * @h : head
 * @idx : index
 * @n : data
 * Description:description
 * Return: node or NULL
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *const node = malloc(sizeof(dlistint_t));
dlistint_t *temp;
unsigned int index = 0;
if (!h || !node)
{
free(node);
return (NULL);
}
if (!*h || idx == 0)
{
free(node);
return (add_dnodeint(h, n));
}
if (!*h)
{
free(node);
return (NULL);
}
node->n = n;
temp = *h;
while (temp)
{
if (index == idx)
{
node->next = temp;
node->prev = temp->prev;
temp->prev->next = node;
temp->prev = node;
return (node);
}
temp = temp->next;
index++;
}
free(node);
if (idx == index)
return (add_dnodeint_end(h, n));
return (NULL);
}
