#include "main.h"

/**
 * _strlen_recursion - _strlen_recursion
 * description:description
 * @s : @s
 * Return:return
*/

int _strlen_recursion(char *s)
{
if (*s == '\0')
return (0);
return (1 + _strlen_recursion(s + 1));
}

