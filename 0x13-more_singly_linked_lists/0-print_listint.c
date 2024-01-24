#include "lists.h"

/**
 * print_listint - print_listint
 * Description:description
 * @h : h
 * Return:return
 */

size_t print_listint(const listint_t *h)
{
	size_t sz = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		sz++;
	}

	return (sz);
}
