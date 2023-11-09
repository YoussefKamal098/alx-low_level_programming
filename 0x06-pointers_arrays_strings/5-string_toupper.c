#include "main.h"

/**
 * is_alpha - is_alpha
 * @c: c
 * Return: return
 */

char is_alpha(char c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

/**
 * to_upper - to_upper
 * @c: c
 * Return: return
 */

char to_upper(char c)
{
	if (c >= 65 && c <= 90)
		return (c);
	return (c - 32);
}

/**
 * string_toupper - string_toupper
 * @str: str
 * Return: return
 */

char *string_toupper(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (is_alpha(str[i]))
			str[i] = to_upper(str[i]);
	}

	return (str);
}
