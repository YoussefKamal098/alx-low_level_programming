#include "main.h"
/**
 * is_prime_number - is_prime_number
 * description:description
 * @n : @n
 * @d : @d
 * Return:return
 */

int check_prime(int n, int d);

int is_prime_number(int n)
{
	return (check_prime(n, 2));
}

/**
 * check_prime - check_prime
 * description:description
 * @n : @n
 * @d : @d
 * Return:return
 */

int check_prime(int n, int d)
{
	if (d >= n && n > 1)
		return (1);
	else if (n % d == 0 || n <= 1)
		return (0);
	else
		return (check_prime(n, d + 1));
}
