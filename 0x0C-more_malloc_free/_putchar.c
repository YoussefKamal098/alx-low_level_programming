#include <unistd.h>
#include "main.h"
/**
 * _putchar - _putchar
 * @c:c
 * Description: Description
 * Return: Return
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
