#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid_sum - Print 3x3 grids sum
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */
static void print_grid_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid1[i][j]);
        }

        printf(" %c ", (i == 1 ? '+' : ' '));

        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid2[i][j]);
        }
        printf("\n");
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

/**
 * topple - Topple the grid at position i, j
 * @grid: 3x3 grid
 * @i: row index
 * @j: column index
 */
static void topple(int grid[3][3], int i, int j)
{
    grid[i][j] -= 4;
    if (i - 1 >= 0) grid[i - 1][j]++;
    if (i + 1 < 3) grid[i + 1][j]++;
    if (j - 1 >= 0) grid[i][j - 1]++;
    if (j + 1 < 3) grid[i][j + 1]++;
}

/**
 * is_stable - Check if the grid is stable
 * @grid: 3x3 grid
 * Return: 1 if stable, 0 otherwise
 */
static int is_stable(int grid[3][3])
{
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i][j] > 3) return 0;
        }
    }
    return 1;
}

/**
 * sandpiles_sum - Compute the sum of two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;
    int toppled = 0;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            grid1[i][j] += grid2[i][j];
        }
    }

    while (!is_stable(grid1)) {
        if (toppled)
            printf("=\n");
        print_grid(grid1);
        toppled = 1;

        int tmp_grid[3][3];

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                tmp_grid[i][j] = grid1[i][j];
            }
        }

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (tmp_grid[i][j] > 3)
                    topple(grid1, i, j);
            }
        }
    }

    if (toppled)
        printf("=\n");
    print_grid(grid1);
}
