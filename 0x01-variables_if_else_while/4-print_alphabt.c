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
ch++;
if (ch == 'q' || ch == 'e')
continue;
putchar(ch);
}
putchar('\n');
return (0);
}

