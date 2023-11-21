#include "main.h"

/**
 * alloc_grid - alloc_grid
 * @width :width
 * @height :height
 * Return: return
 */

int **alloc_grid(int width, int height)
{
	int **grid, i, j;
	grid = (int **)malloc(sizeof(*grid) * height);

	if (width <= 0 || height <= 0 || grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		grid[i] = (int *)malloc(sizeof(**grid) * width);

		if (grid[i] == NULL)
		{
			while (i--)
				free(grid[i]);

			free(grid);

			return (NULL);
		}

		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}

	return (grid);
}
