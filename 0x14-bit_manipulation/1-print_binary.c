#include "main.h"

/**
 * helper - helper
 * @n : n
 * Description:description
 * Return:return
 */

void helper(unsigned long int n)
{
if (!n)
{
return;
}

helper(n >> 1L);
_putchar((n & 1L) + '0');
}

/**
 * print_binary - print_binary
 * @n : n
 * Description:description
 * Return:return
 */

void print_binary(unsigned long int n)
{
if (!n)
{
_putchar('0');
return;
}

helper(n);
}
