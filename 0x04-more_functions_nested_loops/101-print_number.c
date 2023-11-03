#include "main.h"

/**
 * calc_of_digit - calc_of_digit
 * @n: n
 * Return: return
 */

int calc_of_digit(int n)
{
	int size = 0;

	while (n)
	{
		n /= 10;
		size += 1;
	}

	return (size);
}

/**
 * _pow - _pow
 * @x: x
 * @y: y
 * Return: return
 */

double _pow(double x, double y)
{
	int i;
	double res = x;

	for (i = 0; i < y - 1; i++)
	{
		res *= x;
	}

	return (res);
}

/**
 * print_number - print_number
 * @n: n
 * Return: return
 */

void print_number(int n)
{
	int digits_number, div;

	if (n < 0)
	{
		n *= -1;
		_putchar('-');
	}

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	digits_number = calc_of_digit(n);
	div = (int)_pow(10, digits_number - 1);

	while (div)
	{
		_putchar((n / div) + '0');
		n = n % div;
		div /= 10;
	}
}
