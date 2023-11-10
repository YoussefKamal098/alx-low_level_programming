#include "main.h"

/**
 * leet - leet
 * @str: str
 * Return: return
 */

char *leet(char *str)
{
	unsigned int i, j;
	const char decrypt[] = {'a', 'e', 'o', 't', 'l'};
	const char encrypt[] = {'4', '3', '0', '7', '1'};

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j < sizeof(decrypt) / sizeof(decrypt[0]); j++)
		{
			if (str[i] == decrypt[j] || str[i] == decrypt[j] - 23)
			{
				str[i] = encrypt[j];
			}
		}
	}

	return (str);
}
