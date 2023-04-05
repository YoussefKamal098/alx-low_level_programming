#include "main.h"
#include <string.h>
/**
 * _strstr - _strstr
 * description:decription
 * @haystack : @haystack
 * @needle : @needle
 * Return:return
*/

char *_strstr(char *haystack, char *needle)
{char *ptr;
ptr = haystack;
while (*ptr)
{
if (strncmp(ptr, needle, strlen(needle)) == 0)
return (ptr);
ptr++;
}
return (0);
}
