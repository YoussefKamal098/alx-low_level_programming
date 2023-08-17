#include "lists.h"

/**
 *dlistint_len - dlistint_len
 * @h : head
 * Description:description
 * Return: length of the Doubly-linkedList
 */
size_t dlistint_len(const dlistint_t *h)
{
const dlistint_t *temp = h;
size_t size = 0;

if (!h)
return (0);

while (temp)
{
temp = temp->next;
size++;
}

return (size);
}
