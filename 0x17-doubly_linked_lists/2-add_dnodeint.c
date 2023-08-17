#include "lists.h"

/**
 *dlistint_len - dlistint_len
 * @head : head
 * @n : data
 * Description:description
 * Return: node or NULL
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
dlistint_t *const node = malloc(sizeof(dlistint_t));
dlistint_t *temp;

if (!head || !node)
{
free(node);
return (NULL);
}

node->n = n;

if (!*head)
{
*head = node;
return (node);
}

node->next = *head;
(*head)->prev = node;

*head = node;

return (node);
}
