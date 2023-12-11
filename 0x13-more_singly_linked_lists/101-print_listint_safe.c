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
 * print_listint_safe - print_listint_safe
 * @head:head
 * Return: return
 */

size_t print_listint_safe(const listint_t *head)
{
	listint_t **list = NULL;
	size_t size = 0, i;

	if (!head)
		return (size);

	while (head)
	{
		for (i = 0; i < size; i++)
		{
			if (head == list[i])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(list);
				return (size);
			}
		}

		list = add_node_to_list(list, size, (listint_t *)head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		size++;
	}

	if (list)
		free(list);
	return (size);
}
