#pragma once

#include <vector>

using std::vector;

namespace Leet::Medium {
    // You are given an m x n binary matrix grid. An island is a group of 1's
    // (representing land) connected 4-directionally (horizontal or vertical.) You may
    // assume all four edges of the grid are surrounded by water. The area of an island is
    // the number of cells with a value 1 in the island.

    // Return the maximum area of an island in grid. If there is no island, return 0.

    // Example 1:
    // Input: grid =
    // [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
    // Output: 6
    // Explanation: The answer is not 11, because the island must be connected
    // 4-directionally.

    // Example 2:
    // Input: grid = [[0,0,0,0,0,0,0,0]]
    // Output: 0

    // Constraints:
    // m == grid.length
    // n == grid[i].length
    // 1 <= m, n <= 50
    // grid[i][j] is either 0 or 1.
    struct AreaIsland
    {
        int getArea(vector<vector<int>>& grid, int row, int col)
        {
            if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
                return 0;
            if (grid[row][col] == 0)
                return 0;

            grid[row][col] = 0;

            int d = getArea(grid, row + 1, col);
            int u = getArea(grid, row - 1, col);
            int r = getArea(grid, row, col + 1);
            int l = getArea(grid, row, col - 1);
            return d + u + r + l + 1;
        }

        int maxAreaOfIsland(vector<vector<int>>& grid)
        {
            int area = 0;

            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[0].size(); j++) {
                    if (grid[i][j] == 1) {
                        area = std::max(area, getArea(grid, i, j));
                    }
                }
            }

            return area;
        }
    };
}  // namespace Leet::Medium