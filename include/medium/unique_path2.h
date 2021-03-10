#pragma once

#include <vector>

namespace Leet::Medium {
    // A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
    // The robot can only move either down or right at any point in time. The robot is trying to reach
    // the bottom-right corner of the grid (marked 'Finish' in the diagram below).
    // Now consider if some obstacles are added to the grids. How many unique paths would there be?

    // An obstacle and empty space is marked as 1 and 0 respectively in the grid.
    // Note: m and n will be at most 100.

    // Example 1:
    // Input:
    // [
    //   [0,0,0],
    //   [0,1,0],
    //   [0,0,0]
    // ]
    // Output: 2

    // Explanation:
    // There is one obstacle in the middle of the 3x3 grid above.
    // There are two ways to reach the bottom-right corner:
    // 1. Right -> Right -> Down -> Down
    // 2. Down -> Down -> Right -> Right
    struct UniquePath2
    {
        int uniquePathWithObstacles(std::vector<std::vector<int>> &obstacleGrid)
        {
            if (obstacleGrid[0][0] == 1)
                return 0;

            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();

            std::vector<std::vector<int>> grid(m, std::vector<int>(n));
            grid[0][0] = 1;

            for (int i = 1; i < m; i++)
                grid[i][0] = (obstacleGrid[i][0] == 0 && grid[i - 1][0] == 1) ? 1 : 0;

            for (int i = 1; i < n; i++)
                grid[0][i] = (obstacleGrid[0][i] == 0 && grid[0][i - 1] == 1) ? 1 : 0;

            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    if (obstacleGrid[i][j] == 0)
                        grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
                    else
                        grid[i][j] = 0;
                }
            }

            return grid[m - 1][n - 1];
        }
    };
}  // namespace Leet::Medium
