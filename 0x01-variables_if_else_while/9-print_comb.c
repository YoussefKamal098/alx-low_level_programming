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
if (i != 9)
{
putchar(' ');
putchar(',');
}
i++;
}
putchar('\n');
return (0);
}

