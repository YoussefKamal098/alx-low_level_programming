#include "main.h"
/**
 * alloc_grid - alloc_grid
 * @width :width
 * @height :height
 * Return: return
 */

int **alloc_grid(int width, int height)
{
	int i, j;
	int **grid;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = (int **)malloc(sizeof(int *) * height);

	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		int *row = (int *)malloc(sizeof(int) * width);

		if (row == NULL)
			return (NULL);

		for (j = 0; j < width; j++)
			row[j] = 0;

		grid[i] = row;
	}

	return (grid);
}
