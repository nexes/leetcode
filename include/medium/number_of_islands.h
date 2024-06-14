#pragma once

#include <vector>

namespace Leet::Medium {
    // Given an m x n 2d grid map of '1's (land) and '0's (water), return the number
    // of islands. An island is surrounded by water and is formed by connecting adjacent
    // lands horizontally or vertically. You may assume all four edges of the grid are
    // all surrounded by water.

    // Example 1:
    // Input: grid = [
    //   ["1","1","1","1","0"],
    //   ["1","1","0","1","0"],
    //   ["1","1","0","0","0"],
    //   ["0","0","0","0","0"]
    // ]
    // Output: 1

    // Example 2:
    // Input: grid = [
    //   ["1","1","0","0","0"],
    //   ["1","1","0","0","0"],
    //   ["0","0","1","0","0"],
    //   ["0","0","0","1","1"]
    // ]
    // Output: 3

    // Constraints:
    // m == grid.length
    // n == grid[i].length
    // 1 <= m, n <= 300
    // grid[i][j] is '0' or '1'.
    struct Islands
    {
        int numIslands(std::vector<std::vector<char>>& grid)
        {
            int total = 0;
            int row_len = grid.size();
            int col_len = grid[0].size();

            for (int row = 0; row < row_len; row++) {
                for (int col = 0; col < col_len; col++) {
                    if (grid[row][col] == '1') {
                        sinkIsland(grid, row, col);
                        total++;
                    }
                }
            }

            return total;
        }

        // we found an island, turn the island from '1' to '0' to show we visited the
        // island and dont' count it more than once.
        void sinkIsland(std::vector<std::vector<char>>& grid, int row, int col)
        {
            int row_len = grid.size();
            int col_len = grid[0].size();

            if (row < 0 || row >= row_len || col < 0 || col >= col_len ||
                grid[row][col] == '0')
                return;

            grid[row][col] = '0';

            // top
            sinkIsland(grid, row - 1, col);
            // right
            sinkIsland(grid, row, col + 1);
            // bottom
            sinkIsland(grid, row + 1, col);
            // left
            sinkIsland(grid, row, col - 1);
        }
    };
}  // namespace Leet::Medium
