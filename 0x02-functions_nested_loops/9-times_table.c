#include "main.h"

/**
 * times_table - times_table
 * Return: return)
 */

void times_table(void)
{
	int i, num, product;

	for (i = 0; i <= 9; i++)
	{
		_putchar('0');
		for (num = 1; num <= 9; num++)
		{
			_putchar(',');
			_putchar(' ');
			product = i * num;

			if (product <= 9)
				_putchar(' ');
			else
				_putchar((product / 10) + '0');

			_putchar((product % 10) + '0');
		}
		_putchar('\n');
	}
}
