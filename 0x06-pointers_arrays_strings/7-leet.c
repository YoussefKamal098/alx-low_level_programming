#include "main.h"

/**
 * leet - leet
 * @c: c
 * Return: return
 */

char *leet(char *c)
{
	char *str = c;
	const char decrypt[] = {'a', 'e', 'o', 't', 'l'};
	const int encrypt[] = {4, 3, 0, 7, 1};
	unsigned int i;

	while (*c)
	{
		for (i = 0; i < sizeof(decrypt) / sizeof(decrypt[0]); i++)
		{
			if (*c == decrypt[i] || *c == decrypt[i] - 32)
			{
				*c = encrypt[i] + 48;
			}
		}

		c++;
	}

	return (str);
}
