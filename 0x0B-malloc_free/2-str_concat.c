#include "main.h"

/**
 * str_concat - str_concat
 * @s1 :s1
 * @s2 :s2
 * Return: return
 */

char *str_concat(char *s1, char *s2)
{
	int i, j, str_len = 0;
	char *str_copy;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i] != '\0'; i++)
		str_len++;

	for (j = 0; s2[j] != '\0'; j++)
		str_len++;

	str_copy = (char *)malloc(str_len + 1);

	if (str_copy == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
		str_copy[i] = s1[i];

	for (j = 0; s2[j] != '\0'; i++, j++)
		str_copy[i] = s2[j];

	str_copy[i] = '\0';

	return (str_copy);
}
