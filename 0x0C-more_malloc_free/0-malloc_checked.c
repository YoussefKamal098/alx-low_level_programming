#include "main.h"

/**
 * malloc_checked - malloc_checked
 * description:decription
 * @b : @b
 * Return:return
*/

void *malloc_checked(unsigned int b)
{
int *m = malloc(b);
if (m == 0)
exit(98);
return (m);
}
