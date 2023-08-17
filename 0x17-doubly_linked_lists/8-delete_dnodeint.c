#include "lists.h"

/**
 *delete_dnodeint_at_index - delete_dnodeint_at_index
 * @head : head
 * @index : index
 * Description:description
 * Return: 1 or -1
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *temp;
unsigned int idx = 0;
if (!head || !*head)
return (-1);
if (index == 0)
{
if (!(*head)->next)
{
free(*head);
*head = NULL;
}
else
{
*head = (*head)->next;
free((*head)->prev);
}
return (1);
}
temp = *head;
while (temp)
{
if (idx == index)
{
temp->prev->next = temp->next;
if (temp->next)
temp->next->prev = temp->prev;
else
temp->prev = NULL;
free(temp);
return (1);
}
temp = temp->next;
idx++;
}
return (-1);
}
