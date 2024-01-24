#include "main.h"

/**
 * get_endianness - get_endianness
 * Description:description
 * Return:return
 */

int get_endianness(void)
{
	unsigned long int n = 1;

	return (*(char *)&n);
}
