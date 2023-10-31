#include <unistd.h>
#include "main.h"

/**
 * _putchar - main
 * @c:c
 * description: Description
 * Return: Return
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
