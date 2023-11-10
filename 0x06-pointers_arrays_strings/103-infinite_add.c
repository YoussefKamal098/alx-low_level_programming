#include "main.h"

/**
 * infinite_add - infinite_add
 * @n1: n1
 * @n2: n2
 * @r: r
 * @size_r: size_r
 * Return: return
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, tallest_number = 0, k, curr_n1_digit, curr_n2_digit, carry = 0;

	while (n1[i])
		i++;
	while (n2[j])
		j++;

	if (i > j)
		tallest_number = i;
	else
		tallest_number = j;

	if (tallest_number + 1 > size_r)
		return (0);

	r[tallest_number] = '\0';

	for (k = tallest_number - 1; k >= 0; k--)
	{
		i--;
		j--;

		if (i >= 0)
			curr_n1_digit = n1[i] - '0';
		else
			curr_n1_digit = 0;

		if (j >= 0)
			curr_n2_digit = n2[j] - '0';
		else
			curr_n2_digit = 0;

		r[k] = (curr_n1_digit + curr_n2_digit + carry) % 10 + '0';

		carry = (curr_n1_digit + curr_n2_digit + carry) / 10;
	}

	if (carry == 1)
	{
		r[tallest_number + 1] = '\0';

		if (tallest_number + 2 > size_r)
			return (0);

		while (tallest_number-- > 0)
		{
			printf("%d\n", tallest_number);
			r[tallest_number + 1] = r[tallest_number];
		}

		r[0] = carry + '0';
	}

	return (r);
}
