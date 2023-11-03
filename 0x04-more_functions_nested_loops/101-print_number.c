#include "main.h"

/**
 * print_number - print_number
 * @n: n
 * Return: return
 */

void print_number(int n)
{
	if (n < 0)
	{
		n *= -1;
		_putchar('-');
	}

	if (n / 10 > 0)
		print_number(n / 10);

	_putchar((n % 10) + '0');
}
