#include "main.h"

/**
 * print_str -  print_str
 * @str: str
 * Return: return
 */

void print_str(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}

/**
 * main - main
 * Return: return
 */

int main(void)
{

	char *Fizz = "Fizz";
	char *Buzz = "Buzz";
	int i;

	for (i = 1; i <= 100; i++)
	{

		if (i % 3 == 0 && i % 5 == 0)
		{
			print_str(Fizz);
			print_str(Buzz);
		}
		else if (i % 3 == 0)
		{
			print_str(Fizz);
		}
		else if (i % 5 == 0)
		{
			print_str(Buzz);
		}
		else
		{
			if (i > 9)
				_putchar((i / 10) + '0');
			_putchar((i % 10) + '0');
		}

		if (i != 100)
			_putchar(' ');
		else
			_putchar('\n');
	}

	return (0);
}
