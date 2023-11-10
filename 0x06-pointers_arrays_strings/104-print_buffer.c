#include "main.h"

/**
 * is_ascii_char - is_ascii_char
 * @c: c
 * Return: return
 */

int is_ascii_char(int c)
{
	return (c >= 32 && c <= 126);
}

/**
 * print_hex - print_hex
 * @b: b
 * @start: start
 * @end: end
 * Return: return
 */

void print_hex(char *s, int start, int end)
{
	int i = 0;

	while (i < 10)
	{
		if (i < end)
			printf("%02x", *(s + start + i));
		else
			printf("  ");

		if (i % 2)
			printf(" ");

		i++;
	}
}

/**
 *  print_ascii -  print_ascii
 * @b: b
 * @start: start
 * @end: end
 * Return: return
 */
void print_ascii(char *s, int start, int end)
{
	int i = 0, c;

	while (i < end)
	{
		c = *(s + start + i);

		if (!is_ascii_char(c))
			c = '.';

		printf("%c", c);
		i++;
	}
}

/**
 * print_buffer - print_buffer
 * @b: b
 * @size: size
 * Return: return
 */

void print_buffer(char *b, int size)
{
	int start, end;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (start = 0; start < size; start += 10)
	{
		end = (size - start < 10) ? size - start : 10;
		printf("%08x: ", start);
		print_hex(b, start, end);
		print_ascii(b, start, end);
		printf("\n");
	}
}
