#include "main.h"

/**
 * _strstr - _strstr
 * description:decription
 * @haystack : @haystack
 * @needle : @needle
 * Return:return
*/

char *_strstr(char *haystack, char *needle)
{int i, j;
char *ptr;

if (needle[0] == '\0')
{
return (0);
}

i = 0;
while (haystack[i] != '\0')
{
j = 0;
ptr = &haystack[i];
while (haystack[i] == needle[j])
{
j++;
if (needle[j] == '\0')
{
return (ptr);
}
}
i++;
}
return (0);
}
