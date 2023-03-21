#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/**
 * main - main
 * description: Description
 * Return: Return
 */
int main(void)
{char ch = 'a';
while (ch <= 'z')
{
if (ch == 'q' || ch == 'e')
ch++;
putchar(ch);
ch++;
}
putchar('\n');
return (0);
}

