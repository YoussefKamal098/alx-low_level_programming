#include "main.h"

/**
 * free_grid -  free_grid
 * @grid : grid
 * @height :height
 * Return: return
 */

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}
