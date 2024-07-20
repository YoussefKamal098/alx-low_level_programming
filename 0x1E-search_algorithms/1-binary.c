#include "search_algos.h"
#include <stdbool.h>

static void print_array_portion(int *array, size_t left, size_t right);

/**
 * binary_search - Searches for a value in a sorted array of integers
 *		using the Binary Search algorithm.
 *
 * @array: A pointer to the first element of the sorted array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Description: This function performs a binary search on a sorted array of
 * integers to find the index of a specified value. It iteratively divides the
 * search interval in half and prints the current portion of the
 * array being searched. If the value is found, it returns the index of
 * the value in the array. If the value is not found, it returns -1.
 *
 * Return: The index where value is located. If value is not present in
 *		array or if array is NULL, the function returns -1.
 *
 * Example:
 * @code
 * int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
 * int index = binary_search(arr, 9, 5);
 * if (index != -1) {
 *     printf("Value found at index %d\n", index);
 * } else {
 *     printf("Value not found\n");
 * }
 * @endcode
 *
 * Complexity:
 * - Time complexity: O(log n) - The array is divided in half each iteration.
 * - Space complexity: O(1) - The function uses a constant amount of
 *		extra space.
 */
int binary_search(int *array, size_t size, int value)
{
	size_t left, right, mid;

	if (array == NULL || size == 0)
		return (-1);

	left = 0;
	right = size - 1;

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
 * right indices
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
