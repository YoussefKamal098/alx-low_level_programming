#include "variadic_functions.h"

/**
 *  sum_them_all -  sum_them_all
 * @n: n
 * @...: ...
 * Return: return
 */

int sum_them_all(const unsigned int n, ...)
{
	unsigned int i, sum = 0;
	va_list args;

	if (n == 0)
		return (0);

	va_start(args, n);

	for (i = 0; i < n; i++)
		sum += va_arg(args, int);

	return (sum);
}
