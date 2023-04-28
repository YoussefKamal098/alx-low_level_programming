#include "lists.h"

/**
 * add_node_end - add_node_end
 * Description:description
 * @head : head
 * @str : str
 * Return:return
 */

list_t *add_node_end(list_t **head, const char *str)
{
list_t *new = malloc(sizeof(list_t)), *temp;

if (!new || !head)
return (NULL);

new->str = strdup(str);

if (!new->str)
{
free(new);
return (NULL);
}

new->len = strlen(str);

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
