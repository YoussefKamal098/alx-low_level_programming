#include "search_algos.h"
#include <math.h>

#define MIN(x, y) ((x <= y) ? (x) : (y))

/**
 * jump_search - Searches for a value in a sorted array using the
 *		Jump Search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The first index where the value is located,
 *         or -1 if the value is not present in the array or
 *         if the array is NULL.
 *
 * Description: The Jump Search algorithm divides the array into blocks of a
 *				fixed size (square root of the array size), then performs a
 *				linear search within the block where the target value might be located.
 *				The function prints the value comparisons at each step of the algorithm.
 *
 * Example:
 *      int array[] = {0, 1, 2, 4, 5, 7, 8, 9, 10, 12, 14, 16, 18, 19, 20};
 *      size_t size = sizeof(array) / sizeof(array[0]);
 *      int value = 10;
 *      int index = jump_search(array, size, value);
 *      printf("Element %d is found at index %d\n", value, index);
 */
int jump_search(int *array, size_t size, int value)
{
	size_t curr_pos, jump, pre_pos;

	if (array == NULL || size == 0)
		return (-1);

	jump = (size_t) sqrt((double) size);
	curr_pos = 0;
	
	while (array[MIN(curr_pos, size - 1)] < value)
	{
		pre_pos = curr_pos;
		curr_pos += jump;
		if (pre_pos >= size - 1)
			break;

		printf("Value checked array[%lu] = [%d]\n", pre_pos, array[pre_pos]);
	}

	printf("Value found between indexes [%lu] and [%lu]\n", pre_pos, curr_pos);

	while (pre_pos != MIN(curr_pos + 1, size) && array[pre_pos] <= value)
	{
		printf("Value checked array[%lu] = [%d]\n", pre_pos, array[pre_pos]);
		if (array[pre_pos] == value)
			return ((int) pre_pos);

		pre_pos++;
	}

	return (-1);
}
