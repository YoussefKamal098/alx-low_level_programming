#include "main.h"

/**
 * _strcpy - _strcpy
 * @dest : @dest
 * @src : @src
 * Return:return
 */
char *_strcpy(char *dest, char *src)
{
	int i = -1;

	do
	{
		i++;
		dest[i] = src[i];
	} while (src[i] != '\0');
	return (dest);
}
