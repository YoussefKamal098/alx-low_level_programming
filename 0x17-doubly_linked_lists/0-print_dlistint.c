#include "lists.h"

/**
 * print_dlistint - print_dlistint
 * @h : head
 * Description:description
 * Return: length of the Doubly-linkedList
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *temp = h;
	size_t size = 0;

	if (!h)
		return (0);

	while (temp)
	{
		printf("%i\n", temp->n);
		temp = temp->next;
		size++;
	}

	return (size);
}
