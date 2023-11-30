#include "main.h"

/**
 * print_str - print_str
 * @args: args
 * Return: return
 */

void print_str(va_list args)
{
	char *str = va_arg(args, char *);

	if (str)
		printf("%s", str);
	else
		printf("(nil)");
}

/**
 * print_char - print_char
 * @args: args
 * Return: return
 */

void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_integer - print_integer
 * @args: args
 * Return: return
 */
void print_integer(va_list args)
{
	printf("%i", va_arg(args, int));
}

/**
 * print_float - print_float
 * @args: args
 * Return: return
 */

void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_all - print_all
 * @format: format
 * @...: ...
 * Return: return
 */

void print_all(const char *const format, ...)
{
	specifier_t specifiers[] = {
	    {'s', print_str},
	    {'c', print_char},
	    {'i', print_integer},
	    {'f', print_float}};

	int specifiers_len = sizeof(specifiers) / sizeof(specifiers[0]);
	int i = 0, j, print_separator = 0;
	va_list args;

	va_start(args, format);

	while (format[i])
	{
		j = 0;

		while (j < specifiers_len)
		{
			if (format[i] == specifiers[j].type)
			{
				if (print_separator)
					printf(", ");

				specifiers[j].fn(args);
				print_separator = 1;
				break;
			}
			j++;
		}

		i++;
	}

	printf("\n");
	va_end(args);
}
