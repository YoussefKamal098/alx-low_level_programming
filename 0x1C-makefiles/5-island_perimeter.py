#!/usr/bin/python3

"""Module that calculate the perimeter of the island described in the grid."""


def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in the grid.

    Parameters:
    - grid (list of list of int): Represents the island with 1s for
      land and 0s for water.

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
            if grid[i][j]:
                if i <= 0 or not grid[i - 1][j]:
                    perimeter += 1
                if j <= 0 or not grid[i][j - 1]:
                    perimeter += 1
                if j >= len(grid[i]) - 1 or not grid[i][j + 1]:
                    perimeter += 1
                if i >= len(grid) - 1 or not grid[i + 1][j]:
                    perimeter += 1

    return perimeter
