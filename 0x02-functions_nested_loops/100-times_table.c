#include "main.h"

/**
 * print_times_table - print_times_table
 * @n : n
 * Return: return
 */

void print_times_table(int n)
{
	int product, multi, num;

	if (n <= 15 && n >= 0)
	{
		for (num = 0; num <= n; num++)
		{
			_putchar('0');
			for (multi = 1; multi <= n; multi++)
			{
				_putchar(',');
				_putchar(' ');

				product = num * multi;

				if (product <= 9)
				{
					_putchar(' ')
				}
				if (product <= 99)
				{
					_putchar(' ');
				}

				if (product >= 100)
				{
					_putchar((product / 100) + '0');
					_putchar((product / 10) % 10 + '0');
				}
				else if (product <= 99 && product >= 10)
				{
					_putchar((product / 10) + '0');
				}
				_putchar((product % 10) + '0');
			}
			_putchar('\n');
		}
	}
}

