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
			prouct = i * num;

			if (num <= 9)
				_pucchar(' ');
			else
				_putchar((product / 10) + '0');

			_putchar((product % 10) + '0');

			putchar(' ');
		}
		_putchar('\n');
	}
}
