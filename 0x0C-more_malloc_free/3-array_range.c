#include "main.h"

/**
 * array_range - array_range
 * description:decription
 * @min : @min
 * @max : @max
 * Return:return
*/

int *array_range(int min, int max)
{
int range, i;
int *array;

if (min > max)
return (NULL);

range = max - min + 1;
array = malloc(range *sizeof(int));

if (array == NULL)
return (NULL);

for (i = 0; i < range; ++i)
array[i] = min++;

return (array);
}

