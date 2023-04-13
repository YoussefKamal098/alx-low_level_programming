#include "main.h"

char *_memset(char *s, char b, unsigned int n);

/**
 * _calloc - _calloc
 * description:decription
 * @nmemb : @nmemb
 * @size : @size
 * Return:return
*/

void *_calloc(unsigned int nmemb, unsigned int size)
{
void *m;

if (size == 0 || nmemb == 0)
return (NULL);
m = malloc(sizeof(int) * nmemb);

if (m == 0)
return (NULL);

_memset(m, 0, sizeof(int) * nmemb);

return (m);
}

/**
 * _memset - _memset
 * description:decription
 * @n : @n
 * @b : @b
 * @s : @s
 * Return:return
*/

char *_memset(char *s, char b, unsigned int n)
{
char *ptr = s;

while (n--)
*s++ = b;

return (ptr);
}
