#include "main.h"

/**
 * _strstr - _strstr
 * description:decription
 * @haystack : @haystack
 * @needle : @needle
 * Return:return
*/

char *_strstr(char *haystack, char *needle)
{
int i = 0;
while (haystack[i] != '\0')
{
int j = 0;
char *ptr = &haystack[i];
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
return (NULL);
}
