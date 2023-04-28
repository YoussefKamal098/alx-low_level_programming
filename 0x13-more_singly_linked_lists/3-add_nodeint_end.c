#include "lists.h"

/**
 * add_nodeint_end - add_nodeint_end
 * @head : head
 * @n : n
 * Description:description
 * Return:return
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new = malloc(sizeof(listint_t)), *temp;

if (!new || !head)
return (NULL);

new->n = n;

if (!*head)
{
*head = new;
return (new);
}

temp = *head;

while (temp->next)
{
temp = temp->next;
}

temp->next = new;

return (new);
}
