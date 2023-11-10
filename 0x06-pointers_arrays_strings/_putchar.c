#include <unistd.h>

/**
 * _putchar - _putchar
 * @c: c
 * Return: Return
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
