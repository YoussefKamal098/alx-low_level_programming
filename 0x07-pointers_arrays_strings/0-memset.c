#include "main.h"
/**
 * _memset - _memset
 * @s:@s
 * @b:@b
 * @n:@n
 * Return:return
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i;

	for (i = 0; n > 0; i++, n--)
	{
		s[i] = b;
	}
	return (s);
}
