#include "main.h"

/**
 * _strdup - _strdup
 * description:decription
 * @str : @str
 * Return:return
*/

char *_strdup(char *str)
{int i;
char *s;
if (strlen(str) == 0)
return (0);
s = malloc(strlen(str) + 1);
for (i = 0; i < strlen(str); ++i)
{
s[i] = str[i];
}
return (s);
}
