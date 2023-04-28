
#include "lists.h"

/**
 * sum_listint - sum_listint
 * Description:description
 * @head : head
 * Return:return
 */

int sum_listint(listint_t *head)
{
int sum = 0;

while (head)
{
sum += head->n;
head = head->next;
}

return (sum);
}
