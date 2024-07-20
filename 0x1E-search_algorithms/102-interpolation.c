#include "search_algos.h"

static size_t calculate_pos(int *array, size_t left, size_t right, int value);

/**
 * interpolation_search - Searches for a value in a sorted array of integers
 *                        using the Interpolation search algorithm.
 *
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, your function must
 *         return -1. Otherwise, it returns the first index where the value is
 *         located.
 *
 * Description: This function implements the Interpolation search algorithm.
 *              The algorithm assumes that the values in the array are
 *              uniformly distributed.
 *
 *              to estimate the position of the target value. The algorithm
 *              repeatedly checks the estimated position and adjusts the search
 *              range based on the comparison with the target value. It prints
 *              every value checked during the search process.
 *
 * Example:
 *              For the array [10, 20, 30, 40, 50] and value = 30, the function
 *              will print:
 *                  Value checked array[2] = [30]
 *
 *              If the value is found, it will return the index of the value.
 *              Otherwise, it will return -1.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t left, right, pos;

	if (array == NULL || size == 0)
		return (-1);

	left = 0, right = size - 1;

	while (left <= right)
	{
		pos = calculate_pos(array, left, right, value);

		if (pos < left || pos > right)
		{
			printf("Value checked array[%lu] is out of range\n", pos);
			break;
		}

		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

		if (array[pos] == value)
			return ((int) pos);
		else if (array[pos] < value)
			left = pos + 1;
		else
			right = pos - 1;
	}

	return (-1);
}


/**
 * calculate_pos - Calculates the estimated position of a value in a
 *                      sorted array using the interpolation formula.
 *
 * @array: A pointer to the first element of the array.
 * @left: The left boundary index of the search range.
 * @right: The right boundary index of the search range.
 * @value: The value to search for.
 *
 * Return: The estimated position of the value in the array.
 *
 * Description:
 * The interpolation formula is derived from the concept of proportionality
 * in a uniformly distributed array. Given an array with values sorted in
 * ascending order, we can estimate the position of the value using linear
 * interpolation.
 *
 * Concept of Linear Interpolation:
 * Given two points (x1, y1) and (x2, y2), linear interpolation is used
 * to estimate the value of yy at a point xx within the interval [x1, x2].
 * The linear interpolation formula is:
 * y = y1 + ((x − x1) / (x2 − x1)) * (y2 − y1)
 *
 * This formula calculates the position `pos` based on the following idea:
 * - The distance from `left` to `pos` is proportional to the distance from
 *   `array[left]` to `value`.
 * - The proportion is given by the ratio of the overall range of values
 *   (array[right] - array[left]) to the overall range of
 *   indices (right - left).
 *
 * Therefore, the formula adjusts the `left` index by the proportional distance
 * to the `value`.
 *
 * This method is more efficient for uniformly distributed arrays because it
 * narrows down the search range more quickly than binary search.
 */
size_t calculate_pos(int *array, size_t left, size_t right, int value)
{
	/* Calculate the range of the array segment */
	double range = (double) (right - left);

	/* Calculate the value difference */
	double value_diff = (double) (value - array[left]);

	/* Calculate the array value difference */
	double array_diff = (double) (array[right] - array[left]);

	/* Compute the proportion of the value's pos within the segment */
	double proportion = value_diff / array_diff;

	/* Calculate the estimated pos */
	size_t pos = left + (size_t) (proportion * range);

	return (pos);
}
