#include "main.h"

/**
 * get_bit - get_bit
 * @n : n
 * @index : index
 * Description:description
 * Return:return
 */

int get_bit(unsigned long int n, unsigned int index)
{
if (index >= sizeof(n) * 8)
{
return (-1);
}

return ((n >> index) & 1L);
}
