#include "main.h"

/**
 * reverse_array - reverse_array
 * @a: a
 * @n: n
 * Return: return
 */

void reverse_array(int *a, int n)
{
	int i, j, temp;

	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}
