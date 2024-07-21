#include "search_algos.h"
#include <stdbool.h>
#include <unistd.h>

static void print_array_portion(int *array, size_t left, size_t right);

static int _advanced_binary(int *array, size_t left, size_t right, int value);

/**
 * advanced_binary - Searches for a value in a sorted array using an
 *                   advanced binary search algorithm that finds the
 *                   first occurrence of the value.
 *
 * Description: This function performs a binary search to locate the target
 * value in the sorted array. It is designed to find the first occurrence
 * of the value, even if there are multiple instances in the array.
 *
 * @array: Pointer to the array of integers (must be sorted).
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index of the first occurrence of the value if found, or
 *         -1 if the value is not present in the array.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (_advanced_binary(array, 0, size - 1, value));
}

/**
 * _advanced_binary - Recursively performs a binary search within a
 *                    specified range to find the first occurrence of
 *                    the target value.
 *
 * Description: This helper function performs the binary search algorithm
 * recursively and ensures that the search is conducted within the specified
 * range. It continues searching in the left half of the range if the middle
 * element is equal to the target value to find the first occurrence.
 *
 * @array: Pointer to the array of integers (must be sorted).
 * @left: The starting index of the range to search within.
 * @right: The ending index of the range to search within.
 * @value: The value to search for.
 *
 * Return: The index of the first occurrence of the value if found, or
 *         -1 if the value is not present in the array.
 */
int _advanced_binary(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (right < left)
		return (-1);

	print_array_portion(array, left, right);

	mid = left + (right - left) / 2;

	if (array[mid] == value && (mid == left || array[mid - 1] != value))
		return ((int) mid);

	if (array[mid] >= value)
		return (_advanced_binary(array, left, mid, value));

	return (_advanced_binary(array, mid + 1, right, value));
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
