#include "lists.h"

/**
 * list_len - list_len
 * Description:description
 * @h : h
 * Return:return
 */

size_t list_len(const list_t *h)
{
	size_t sz = 0;

	while (h)
	{
		h = h->next;
		sz++;
	}

	return (sz);
}
