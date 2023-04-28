#include "lists.h"

/**
 * print_list - print_list
 * Description:description
 * @h : h
 * Return:return
 */

size_t print_list(const list_t *h)
{
size_t sz = 0;

while (h)
{
printf("[%d] %s\n", h->str ? h->len : 0, h->str ? h->str : "(nil)");
h = h->next;
sz++;
}

return (sz);
}
