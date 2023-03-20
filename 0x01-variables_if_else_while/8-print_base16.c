#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * main - main
 * description: Description
 * Return: Return
 */
int main(void)
{
int i = 0;
while (i < 10)
{
putchar(i + '0');
i++;
}
char ch = 'a';
while (ch <= 'f')
{
putchar(ch);
ch++;
}
putchar('\n');
return (0);
}
