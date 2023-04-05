#include "main.h"
/**
 * is_prime_number - is_prime_number
 * description:description
 * @n : @n
 * Return:return
*/

int is_prime_number(int n)
{
if (n <= 1)
return (0);
int i;
for (i = 2; i <= sqrt(n); i++)
{
if (n % i == 0)
return (0);
}
return (1);
}
