#include "lists.h"

/**
 * free_list - afree_list
 * Description:description
 * @head : head
 * Return:return
 */

void free_list(list_t *head)
{
if (!head)
return;
free_list(head->next);
free(head->str);
free(head);
}
