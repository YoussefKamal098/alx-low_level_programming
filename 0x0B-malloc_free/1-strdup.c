#include "main.h"

/**
 * _strdup - _strdup
 * @str :str
 * Return: return
 */

char *_strdup(char *str)
{
	int i, str_len = 0;
	char *str_copy;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		str_len++;

	str_copy = (char *)malloc(str_len + 1);

	if (str_copy == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		str_copy[i] = str[i];

	str_copy[i] = '\0';

	return (str_copy);
}
