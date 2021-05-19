#include "sandpiles.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * sandpiles_sum - function that computes the sum of two sandpiles
 * @grid1: left 3x3 grid
 * @grid2: right 3x3 grid
 **/

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_grids(grid1, grid2);

	while (unstable_grid(grid1) == 1)
	{
		topple_grid(grid1);
	}
}


/**
 * sum_grids - adds grid1 + grid2
 * @grid1: left 3x3 grid
 * @grid2: right 3x3 grid
 **/


void sum_grids(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}

/**
 * unstable_grid - checks whether the grid is stable or not
 * @grid1: 3x3 grid to check
 * Return: returns 1 if unstable and 0 if stable
 **/

int unstable_grid(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				return (1);
		}
	}
	return (0);
}

/**
 * topple_grid - topples the grid
 * @grid1: 3x3 grid to topple
 **/

void topple_grid(int grid1[3][3])
{
	int i, j;
	int added_sands[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	printf("=\n");
	print_grid(grid1);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;
				if (i >= 0 && i < 2)
					added_sands[i + 1][j] += 1;
				if (i > 0 && i <= 2)
					added_sands[i - 1][j] += 1;
				if (j >= 0 && j < 2)
					added_sands[i][j + 1] += 1;
				if (j > 0 && j <= 2)
					added_sands[i][j - 1] += 1;
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += added_sands[i][j];
	}
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */

static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
