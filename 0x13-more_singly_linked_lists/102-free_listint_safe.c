#include "lists.h"
/**
 * add_node_to_list - add_node_to_list
 * @list: list
 * @size: size
 * @node: node
 * Return: return
 */
listint_t **add_node_to_list(listint_t **list, size_t size, listint_t *node)
{
	listint_t **new_list;
	size_t i;

	new_list = (listint_t **)malloc(sizeof(listint_t *) * (size + 1));

	if (new_list == NULL)
	{
		if (list)
			free(list);
		exit(98);
	}

	for (i = 0; i < size; i++)
		new_list[i] = list[i];

	new_list[i] = node;

	free(list);
	return (new_list);
}

/**
 * find_loop - find_loop
 * @head:head
 * Return: return
 */

listint_t *find_loop(listint_t *head)
{

	listint_t **list = NULL;
	size_t size = 0, i;

	if (!head)
		return (NULL);

	while (head && head->next)
	{
		for (i = 0; i < size; i++)
		{
			if (head->next == list[i])
			{
				free(list);
				return (head);
			}
		}

		list = add_node_to_list(list, size, head);

		if (list == NULL)
			return (NULL);

		head = head->next;
		size++;
	}

	if (list)
		free(list);
	return (NULL);
}

/**
 * free_listint_safe - free_listint_safe
 * @h:h
 * Return: return
 */

size_t free_listint_safe(listint_t **h)
{
	listint_t *temp, *curr, *start_loop_node;
	size_t size = 0;

	if (!h || !*h)
		return (size);

	start_loop_node = find_loop(*h);
	curr = *h;

	while (curr)
	{

		temp = curr;
		curr = curr->next;

		if (temp == start_loop_node)
		{
			free(temp);
			*h = NULL;
			return (size);
		}

		free(temp);
		size++;
	}
	*h = NULL;
	return (size);
}
