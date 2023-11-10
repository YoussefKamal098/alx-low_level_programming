#include "main.h"

/**
 * leet - leet
 * @c: c
 * Return: return
 */

char *leet(char *c)
{
	char *str = c;
	unsigned int i;
	const char decrypt[] = {'a', 'e', 'o', 't', 'l'};
	const char encrypt[] = {'4', '3', '0', '7', '1'};

	while (*c)
	{
		for (i = 0; i < sizeof(decrypt) / sizeof(decrypt[0]); i++)
		{
			if (*c == decrypt[i] || *c == decrypt[i] - 23)
			{
				*c = encrypt[i];
			}
		}

		c++;
	}

	return (str);
}
