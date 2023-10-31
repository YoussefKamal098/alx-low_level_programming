#include "main.h"

/**
 * times_table - times_table
 * Return: return)
 */

void times_table(void)
{
	int i, num;

	for (i = 0; i <= 9; i++)
	{
		for (num = 0; num <= 9; num += i)
		{
			if (num > 9)
				_putchar((num / 10) + '0');

			_putchar((num % 10) + '0');

			_putchar(',');

			if (num >= 9)
				_putchar(' ');

			putchar(' ');
		}
		_putchar('\n');
	}
}
