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
	int i = 0, j = 0, tallest = 0, k, curr_n1_d, curr_n2_d, c = 0;

	while (n1[i])
		i++;
	while (n2[j])
		j++;
	if (i > j)
		tallest = i;
	else
		tallest = j;
	if (tallest + 1 > size_r)
		return (0);
	r[tallest] = '\0';
	for (k = tallest - 1; k >= 0; k--)
	{
		i--;
		j--;
		if (i >= 0)
			curr_n1_d = n1[i] - '0';
		else
			curr_n1_d = 0;
		if (j >= 0)
			curr_n2_d = n2[j] - '0';
		else
			curr_n2_d = 0;
		r[k] = (curr_n1_d + curr_n2_d + c) % 10 + '0';
		c = (curr_n1_d + curr_n2_d + c) / 10;
	}
	if (c == 1)
	{
		r[tallest + 1] = '\0';
		if (tallest + 2 > size_r)
			return (0);
		while (tallest-- > 0)
			r[tallest + 1] = r[tallest];
		r[0] = c + '0';
	}
	return (r);
}

