#pragma once

#include <vector>

namespace Leet::Medium {
    typedef std::vector<std::vector<int>> Matrix;
    // A robot is located at the top-left corner of a m x n grid (marked 'Start' in the
    // diagram below). The robot can only move either down or right at any point in time.
    // The robot is trying to reach the bottom-right corner of the grid (marked 'Finish'
    // in the diagram below). Now consider if some obstacles are added to the grids. How
    // many unique paths would there be?

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
        // --------------- RECURSION O(n^(n + m)) TLE ------------------
        int findPath_recursion(Matrix &grid, int m, int n)
        {
            if (m == 0 && n == 0 && grid[m][n] != 1)
                return 1;
            if (m < 0 || n < 0 || grid[m][n] == 1)
                return 0;

            return findPath_recursion(grid, m - 1, n) +
                   findPath_recursion(grid, m, n - 1);
        }

        int uniquePathsWithObstacles_recursion(Matrix &obstacleGrid)
        {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();

            return findPath_recursion(obstacleGrid, m - 1, n - 1);
        }

        // --------------- TOP DOWN O((n * m)) ------------------
        int findPath_topdown(Matrix &grid, Matrix &memo, int m, int n)
        {
            if (m == 0 && n == 0 && grid[m][n] != 1)
                return 1;
            if (m < 0 || n < 0 || grid[m][n] == 1)
                return 0;

            if (memo[m][n] != -1)
                return memo[m][n];

            memo[m][n] = findPath_topdown(grid, memo, m - 1, n) +
                         findPath_topdown(grid, memo, m, n - 1);

            return memo[m][n];
        }

        int uniquePathsWithObstacles_topdown(Matrix &obstacleGrid)
        {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
            Matrix memo(m, std::vector<int>(n, -1));

            return findPath_topdown(obstacleGrid, memo, m - 1, n - 1);
        }
        // --------------- BOTTOM UP O((n * m)) ------------------
        int uniquePathWithObstacles(std::vector<std::vector<int>> &obstacls)
        {
            int m = obstacls.size();
            int n = obstacls[0].size();
            Matrix memo(m, std::vector<int>(n, 0));

            memo[0][0] = obstacls[0][0] == 1 ? 0 : 1;

            // set default values for row 0, if we have an obstacle,
            // we cant go further down that row
            for (int i = 1; i < n; i++) {
                if (obstacls[0][i] == 1 || memo[0][i - 1] == 0)
                    memo[0][i] = 0;
                else
                    memo[0][i] = 1;
            }

            // set default values for col 0, if we have an obstacle,
            // we cant go further down that col
            for (int i = 1; i < m; i++) {
                if (obstacls[i][0] == 1 || memo[i - 1][0] == 0)
                    memo[i][0] = 0;
                else
                    memo[i][0] = 1;
            }

            // walk through the grid like normal
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    if (obstacls[i][j] == 0)
                        memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
                    else
                        memo[i][j] = 0;
                }
            }

            return memo[m - 1][n - 1];
        }
    };
}  // namespace Leet::Medium
