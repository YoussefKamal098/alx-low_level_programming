#include "main.h"

/**
 * print_diagonal - print_diagonal
 * @n: n
 * Return: return
 */

void print_diagonal(int n)
{
	int i, spaces;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 0; i < n; i++)
	{
		spaces = i;

		while (spaces--)
		{
			_putchar(' ');
		}

		_putchar(92);
		_putchar('\n');
	}
}
