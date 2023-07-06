#include "main.h"

/**
 * set_bit - set_bit
 * @n : n
 * @index : index
 * Description:description
 * Return:return
 */

int set_bit(unsigned long int *n, unsigned int index)
{
if (index >= sizeof(n) * 8)
{
return (-1);
}

return (!!(*n |= (1L << index)));
}
