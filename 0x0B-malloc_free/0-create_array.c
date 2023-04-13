#include "main.h"

/**
 * create_array - create_array
 * description:decription
 * @size : @size
 * @c : @c
 * Return:return
*/

char *create_array(unsigned int size, char c)
{char *s = malloc(size);
if (size == 0 || s == 0)
{
return (0);
}
while (size--)
{
s[size] = c;
}
return (s);
}
