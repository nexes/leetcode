#pragma once

#include <algorithm>
#include <vector>

using std::vector;

namespace Leet::Medium {
    // Given a m x n grid filled with non-negative numbers, find a path from top
    // left to bottom right, which minimizes the sum of all numbers along its
    // path. Note: You can only move either down or right at any point in time.

    // Example 1:
    // Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
    // Output: 7
    // Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

    // Example 2:
    // Input: grid = [[1,2,3],[4,5,6]]
    // Output: 12

    // Constraints:
    // m == grid.length
    // n == grid[i].length
    // 1 <= m, n <= 200
    // 0 <= grid[i][j] <= 100
    struct MinPathSum
    {
        // time: O(n^2), space: O(n)
        int minPathSum(vector<vector<int>> &grid)
        {
            size_t colCount = grid.size();
            size_t rowCount = grid[0].size();

            vector<vector<int>> dp(colCount, vector<int>(rowCount));
            dp[0][0] = grid[0][0];

            // add up the top row
            for (size_t i = 1; i < rowCount; i++)
                dp[0][i] = dp[0][i - 1] + grid[0][i];

            // add up the first col
            for (size_t i = 1; i < colCount; i++)
                dp[i][0] = dp[i - 1][0] + grid[i][0];

            // find the min sum for the inner grid
            for (size_t i = 1; i < grid.size(); i++) {
                for (size_t j = 1; j < grid[i].size(); j++) {
                    dp[i][j] =
                        grid[i][j] + std::min(dp[i - 1][j], +dp[i][j - 1]);
                }
            }

            return dp[colCount - 1][rowCount - 1];
        }
    };
}  // namespace Leet::Medium