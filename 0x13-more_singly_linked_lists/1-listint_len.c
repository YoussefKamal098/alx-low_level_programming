#include "lists.h"

/**
 * listint_len - listint_len
 * @h : h
 * Description:description
 * Return:return
 */

size_t listint_len(const listint_t *h)
{
	size_t sz = 0;

	while (h)
	{
		h = h->next;
		sz++;
	}

	return (sz);
}
