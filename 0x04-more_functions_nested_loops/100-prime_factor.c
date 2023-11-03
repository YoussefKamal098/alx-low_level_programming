#include "main.h"

/**
 * _sqrt -  _sqrt
 * @n: n
 * Return: return
 */

double _sqrt(double n)
{
	int start = 0, end = n, mid, i;
	double res, increment = 0.1;

	while (start <= end)
	{
		mid = (start + end) / 2;

		if (mid * mid == n)
		{
			res = mid;
			break;
		}
		if (mid * mid < n)
		{
			res = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	for (i = 0; i < 5; i++)
	{
		while (res * res <= n)
			res += increment;

		res -= increment;
		increment = increment / 10;
	}

	return (res);
}

/**
 * main - main
 * Return: return
 */

int main(void)
{
	long int num = 612852475143;
	int prim, largest;

	while (num % 2 == 0)
		num /= 2;

	for (prim = 3; prim <= _sqrt(num); prim += 2)
	{
		while (num % prim == 0)
		{
			num /= prim;
			largest = prim;
		}
	}

	if (num > 2)
		largest = num;

	printf("%d\n", largest);

	return (0);
}
