#include "main.h"

/**
 * puts_half - puts_half
 * description:decription
 * @str : @str
 * return:return
*/
void puts_half(char *str)
{int i;
for (i = 0; str[i] != '\0'; i++)
;
for (i /= 2; str[i] != '\0'; i++)
{
_putchar(str[i]);
}
_putchar('\n');
}