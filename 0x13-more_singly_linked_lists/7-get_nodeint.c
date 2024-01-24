#include "lists.h"

/**
 * get_nodeint_at_index -  get_nodeint_at_index
 * Description:description
 * @head : head
 * @index : index
 * Return:return
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	while (index-- && head)
	{
		head = head->next;
	}

	return (head ? head : NULL);
}
