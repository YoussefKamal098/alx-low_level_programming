#include "main.h"
/**
 * _memset - _memset
 * description:decription
 * @s:@s
 * @b:@b
 * @n:@n
 * Return:return
*/
char *_memset(char *s, char b, unsigned int n)
{int i;
char *t = s;
for (i = 0; i < n; i++)
{
*t = b;
t++;
}
return (s);
}
