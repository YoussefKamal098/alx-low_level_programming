#include "search_algos.h"

/**
 * linear_search - Searches for a value in an array of integers using the
 *		Linear Search algorithm.
 *
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Description: This function iterates through the array sequentially,
 * checking each element to see if it matches the target value.
 * If a match is found, it returns the index of the element in the array.
 * If no match is found, it returns -1. The function also prints each
 * element it checks, for debugging purposes.
 *
 * Return: The first index where value is located. If value is not present in
 *		array or if array is NULL, the function returns -1.
 *
 * Example:
 * @code
 * int arr[] = {1, 2, 3, 4, 5};
 * int index = linear_search(arr, 5, 3);
 * if (index != -1) {
 *     printf("Value found at index %d\n", index);
 * } else {
 *     printf("Value not found\n");
 * }
 * @endcode
 *
 * Complexity:
 * - Time complexity: O(n) - In the worst case, the function needs to
 *		check all n elements.
 * - Space complexity: O(1) - The function uses a constant amount of
 *		extra space.
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL || size == 0)
		return (-1);

	for (i = 0; i < size; ++i)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);

		if (array[i] == value)
			return ((int) i);
	}

	return (-1);
}
