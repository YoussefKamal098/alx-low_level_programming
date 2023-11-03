#include "main.h"

/**
 * print_line - print_line
 * @n: n
 * Return: return
 */

void print_line(int n)
{
	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	while (n--)
	{
		_putchar('_');
	}

	_putchar('\n');
}
