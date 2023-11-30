#include "variadic_functions.h"
/**
 * print_str - print_str
 * @args: args
 * @separator: separator
 * Return: return
 */

void print_str(char *separator, va_list args)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(nil)";

	printf("%s%s", separator, str);
}

/**
 * print_char - print_char
 * @args: args
 * @separator: separator
 * Return: return
 */

void print_char(char *separator, va_list args)
{
	printf("%s%c", separator, va_arg(args, int));
}

/**
 * print_integer - print_integer
 * @args: args
 * @separator: separator
 * Return: return
 */
void print_integer(char *separator, va_list args)
{
	printf("%s%d", separator, va_arg(args, int));
}

/**
 * print_float - print_float
 * @args: args
 * @separator: separator
 * Return: return
 */

void print_float(char *separator, va_list args)
{
	printf("%s%f", separator, va_arg(args, double));
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
	int i = 0, j;
	char *separator = "";
	va_list args;

	va_start(args, format);

	while (format[i])
	{
		j = 0;

		while (j < specifiers_len)
		{
			if (format[i] == specifiers[j].type)
			{
				specifiers[j].fn(separator, args);
				separator = ", ";
				break;
			}
			j++;
		}

		i++;
	}

	printf("\n");
	va_end(args);
}
