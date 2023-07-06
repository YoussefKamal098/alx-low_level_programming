#include "main.h"

/**
 * clear_bit - clear_bit
 * @n : n
 * @index : index
 * Description:description
 * Return:return
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
if (index >= sizeof(n) * 8)
{
return (-1);
}

if (*n & (1L << index))
{
*n ^= (1L << index);
}

return (1);
}
