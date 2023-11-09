#include "main.h"

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
 * is_alpha - is_alpha
 * @c: c
 * Return: return
 */

char is_alpha(char c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

/**
 * is_delimiter - is_delimiter
 * @c: c
 * Return: return
 */

int is_delimiter(char c)
{
	int i;
	const char delimiters[] = " \t\n,;.!?\"(){}";

	for (i = 0; i < sizeof(delimiters) / sizeof(delimiters[0]); i++)
	{
		if (c == delimiters[i])
		{
			return (1);
		}
	}

	return (0);
}

/**
 * cap_string - cap_string
 * @str: str
 * Return: return
 */

char *cap_string(char *str)
{
	int i;
	int found_delimiter = 1;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (found_delimiter)
		{
			if (is_alpha(str[i]))
				str[i] = to_upper(str[i]);
			found_delimiter = 0;
		}
		if (is_delimiter(str[i]))
		{
			found_delimiter = 1;
		}
	}

	return (str);
}
