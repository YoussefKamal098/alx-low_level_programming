#include "main.h"

/**
 * _strlen - _strlen
 * Description:decription
 * @s:@s
 * Return:return
*/

int _strlen(char *s)
{
int i;
for (i = 0; *s != '\0'; s++)
{
i++;
}
return (i);
}
