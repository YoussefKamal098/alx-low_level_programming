#include "variadic_functions.h"


/**
 * print_numbers - print_numbers
 * @separator: separator
 * @n: n
 * @...: ...
 * Return: return
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i, print_separator = 0;
	va_list args;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		if (print_separator && separator)
			printf("%s", separator);

		printf("%d", va_arg(args, int));
		print_separator = 1;
	}

	printf("\n");
}
