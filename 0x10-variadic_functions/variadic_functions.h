#ifndef VARIADIC_FUNCTION_H
#define VARIADIC_FUNCTION_H

#include <stdio.h>
#include <stdarg.h>

/**
 * struct specifier - struct specifier
 * @type: type
 * @fn: fn
 */
typedef struct specifier
{
	char type;
	void (*fn)(va_list);
} specifier_t;

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif
