#include "search_algos.h"
#include <stdbool.h>

static int _binary_search(int *array, size_t left, size_t right, int value);

static void print_array_portion(int *array, size_t left, size_t right);


/**
 * exponential_search - Searches for a value in a sorted array using
 *                       the exponential search algorithm.
 *
 * This function first finds a range where the target value might be located
 * by repeatedly doubling the search index until the value is found or the
 * end of the array is reached. It then performs a binary search within that
 * range to find the exact position of the target value.
 *
 * @array: Pointer to the array of integers.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index of the value if found, or -1 if the value is not present
 *         in the array.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i, left, right;

	if (array == NULL || size == 0)
		return (-1);

	for (i = 1; i < size && array[i] < value; i = i * 2)
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);

	left = i / 2;
	right = i < size ? i : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", left, right);
	return (_binary_search(array, left, right, value));
}

/**
 * _binary_search - Performs a binary search within a specific range of a
 *                  sorted array.
 *
 * This helper function searches for a value in the specified subarray
 * using the binary search algorithm.
 *
 * @array: Pointer to the array of integers.
 * @left: The starting index of the range to search within.
 * @right: The ending index of the range to search within.
 * @value: The value to search for.
 *
 * Return: The index of the value if found, or -1 if the value is not present
 *         in the array.
 */
int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	while (left <= right)
	{
		print_array_portion(array, left, right);

		mid = left + (right - left) / 2;

		if (array[mid] == value)
			return ((int) mid);
		else if (array[mid] > value)
			right = mid - 1;
		else
			left = mid + 1;
	}

	return (-1);
}

/**
 * print_array_portion - Prints a portion of an array from left to
 * right indices.
 *
 * @array: A pointer to the first element of the array to print.
 * @left: The starting index of the portion to print.
 * @right: The ending index of the portion to print.
 *
 * Description: This function prints the elements of the array from
 * index `left` to index `right` inclusively. It is used for
 * debugging purposes to show the current portion of the array being
 * searched by the binary search algorithm.
 */
void print_array_portion(int *array, size_t left, size_t right)
{
	size_t i;
	bool print_delimiter = false;

	if (left > right)
		return;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		if (print_delimiter)
			printf(", ");

		printf("%d", array[i]);

		print_delimiter = true;
	}

	putchar('\n');
}
