#include "main.h"

/**
 * factorial - factorial
 * description:description
 * @n : @n
 * Return:return
*/

int factorial(int n)
{
if (n < 0)
return (-1);
if (n == 1)
return (1);
return (n * factorial(n - 1));
}
