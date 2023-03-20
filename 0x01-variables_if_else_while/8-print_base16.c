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
for (int i = 0; i < 10; ++i)
putchar(i + '0');
char ch = 'a';
while (ch <= 'f')
{
putchar(ch);
ch++;
}
putchar('\n');
return (0);
}

