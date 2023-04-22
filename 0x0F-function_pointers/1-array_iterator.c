#include "function_pointers.h"

/**
 * array_iterator -array_iterator
 * description:description
 * @array : @array
 * @size : size
 * @action : action
 * Return:return
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
int *end = array + size - 1;

if (array && size && action)
while (array <= end)
action(*array++);
}
