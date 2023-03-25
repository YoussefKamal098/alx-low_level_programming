#include "main.h"

/**
 * print_most_numbers - print_most_numbers
 * Return: Return
 */
void print_most_numbers(void)
{
int num = 0;
for (num = 0; num <= 9 ; ++num)
{
if (num == 2 || num == 4)
continue;
_putchar(num + 48);
}
_putchar('\n');
}
