#include "main.h"

/**
 * isalpha - isalpha
 * @c : c
 * Return : return
 */
int isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}
