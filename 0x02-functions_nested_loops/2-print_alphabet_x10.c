#include "main.h"

/**
 * print_alphabet_x10 - print_alphabet_x10
 * Description : (Description)
 * Return: (Return)
 */
void print_alphabet_x10(void)
{
	int ch;
	int i;

	for (i = 0; i < 10; i++)
	{
		for (ch = 97; ch < 123; ch++)
			_putchar((char)ch);

		_putchar('\n');
	}
}
