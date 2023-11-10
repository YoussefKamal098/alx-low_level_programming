#include "main.h"

/**
 * rot13 - rot13
 * @str: str
 * Return: return
 */

char *rot13(char *str)
{
	unsigned int i, j;
	const char encrypt[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	const char decrypt[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *encrypted_str = str;

	for (i = 0; encrypted_str[i] != '\0'; i++)
	{
		for (j = 0; j < sizeof(encrypt) / sizeof(encrypt[0]); j++)
		{
			if (encrypted_str[i] == encrypt[j])
			{
				encrypted_str[i] = decrypt[j];
				break;
			}
		}
	}

	return (encrypted_str);
}
