#pragma once

#include <vector>

namespace Leet::Easy {
    // You are given row x col grid representing a map where grid[i][j] = 1 represents
    // land and grid[i][j] = 0 represents water.

    // Grid cells are connected horizontally/vertically (not diagonally). The grid is
    // completely surrounded by water, and there is exactly one island (i.e., one or more
    // connected land cells).

    // The island doesn't have "lakes", meaning the water inside isn't connected to the
    // water around the island. One cell is a square with side length 1. The grid is
    // rectangular, width and height don't exceed 100. Determine the perimeter of the
    // island.

    // Example 1:
    // Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
    // Output: 16
    // Explanation: The perimeter is the 16 yellow stripes in the image above.

    // Example 2:
    // Input: grid = [[1]]
    // Output: 4

    // Example 3:
    // Input: grid = [[1,0]]
    // Output: 4

    // Constraints:
    //   row == grid.length
    //   col == grid[i].length
    //   1 <= row, col <= 100
    //   grid[i][j] is 0 or 1.
    struct IslandPerimeter
    {
        // O(n^2)
        int islandPerimeter(std::vector<std::vector<int>>& grid)
        {
            int perimeter = 0;
            int row = grid.size();
            int col = grid[0].size();

            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (grid[i][j] == 1)
                        perimeter += getPerimeter(grid, i, j);
                }
            }

            return perimeter;
        }

        int getPerimeter(std::vector<std::vector<int>>& grid, int row, int col)
        {
            int width = grid[0].size();
            int height = grid.size();
            int perim = 4;

            // top
            if (row - 1 >= 0 && grid[row - 1][col] == 1)
                perim--;
            // right
            if (col + 1 < width && grid[row][col + 1] == 1)
                perim--;
            // bottom
            if (row + 1 < height && grid[row + 1][col] == 1)
                perim--;
            // left
            if (col - 1 >= 0 && grid[row][col - 1] == 1)
                perim--;

            return perim;
        }
    };
}  // namespace Leet::Easy
