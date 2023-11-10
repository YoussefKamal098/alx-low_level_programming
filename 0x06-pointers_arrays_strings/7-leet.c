#include "main.h"

/**
 * to_lower - to_lower
 * @c: c
 * Return: return
 */

char to_lower(char c)
{
	if (c >= 97 || c <= 122)
		return (c);

	return (c + 32);
}

/**
 * leet - leet
 * @str: str
 * Return: return
 */

char *leet(char *str)
{
	int i, j;
	const char decrypt[] = {'a', 'e', 'o', 't', 'l'};
	const char encrypt[] = {'4', '3', '0', '7', '1'};

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j < sizeof(decrypt) / sizeof(decrypt[0]); j++)
		{
			if (to_lower(str[i]) == decrypt[j])
			{
				str[i] = encrypt[j];
				break;
			}
		}
	}

	return (str);
}
