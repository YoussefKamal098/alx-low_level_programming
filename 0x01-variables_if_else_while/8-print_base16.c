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
int i = 48;
while (i <= 102)
{
putchar(i + '0');
if(i == 57)
i+=39;
i++;
}
putchar('\n');
return (0);
}
