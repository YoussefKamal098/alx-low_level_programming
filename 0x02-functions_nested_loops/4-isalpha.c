#include "main.h"

/**
 * _isalpha - _isalpha
 * @c : c
 * Return: return
 */
int _isalpha(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}
