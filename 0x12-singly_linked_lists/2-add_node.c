#include "lists.h"

/**
 * add_node - add_node
 * Description:description
 * @head : head
 * @str : str
 * Return:return
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new = malloc(sizeof(list_t));

	if (!new || !head)
		return (NULL);

	new->str = strdup(str);

	if (!new->str)
	{
		free(new);
		return (NULL);
	}

	new->len = strlen(str);

	new->next = *head;
	*head = new;

	return (new);
}
