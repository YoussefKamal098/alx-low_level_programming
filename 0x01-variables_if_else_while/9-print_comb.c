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
{
putchar(i + '0');
if (i != 9)
{
putchar(' ');
putchar(',');
}
}
putchar('\n');
return (0);
}

