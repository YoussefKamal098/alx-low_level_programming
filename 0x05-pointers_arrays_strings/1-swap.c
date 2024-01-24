#include "main.h"
/**
 * swap_int - swap_int
 * @a:@a
 * @b:@b
 * return:return
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
