#!/usr/bin/python3

"""Module that calculate the perimeter of the island described in the grid."""

def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in the grid.

    Parameters:
    - grid (list of list of int): Represents the island with 1s for land and 0s for water.

    Returns:
    - int: Perimeter of the island.

    Example:
    grid = [
        [0, 1, 0, 0],
        [1, 1, 1, 0],
        [0, 1, 0, 0],
        [1, 1, 0, 0]
    ]
    island_perimeter(grid)  # Output: 16
    """

    rows = len(grid)
    cols = len(grid[0])
    perimeter = 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4

                if (i > 0 and grid[i - 1][j] == 1 or
                    j > 0 and grid[i][j - 1] == 1):
                    perimeter -= 2

    return perimeter