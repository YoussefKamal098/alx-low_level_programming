#include "variadic_functions.h"

/**
 * print_strings - print_strings
 * @separator: separator
 * @n: n
 * @...: ...
 * Return: return
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i, print_separator = 0;
	char *str;
	va_list args;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		if (print_separator && separator)
			printf("%s", separator);

		str = va_arg(args, char *);

		if (str == NULL)
			str = "(nil)";

		printf("%s", str);

		print_separator = 1;
	}

	printf("\n");
}
