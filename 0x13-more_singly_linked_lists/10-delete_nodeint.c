#include "lists.h"

/**
 *  delete_nodeint_at_index -  delete_nodeint_at_index
 * Description:description
 * @head : head
 * @index : index
 * Return:return
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *curr, *pre;

if (!head || !*head)
return (-1);

curr = *head;

if (!index)
{
*head = curr->next;
free(curr);

return (1);
}

pre = NULL;

while (index-- && curr)
{
pre = curr;
curr = curr->next;
}

if (index == -1 && curr)
{
pre->next = curr->next;
free(curr);

return (1);
}

return (-1);
}
