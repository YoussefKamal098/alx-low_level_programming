#include "main.h"

/**
 * flip_bits - flip_bits
 * @n : n
 * @m : m
 * Description:description
 * Return:return
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned int xor = n ^ m;
unsigned int count = 0;

while (xor)
{
if (xor & 1ul)
{
count++;
}

xor >>= 1;
}

return (count);
}
