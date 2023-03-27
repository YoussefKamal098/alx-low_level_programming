#include "main.h"

/**
 * print_array - print_array
 * description:decription
 * @a : @a
 * @n : @n
 * return:return
*/
void print_array(int *a, int n)
{
for (i = 0; i < n; i++)
{
if (i != n - 1)
printf("%d, ", a[i]);
else
printf("%d", a[i])
}
