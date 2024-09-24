#pragma once

#include <vector>

namespace Leet::Medium {
    // A robot is located at the top-left corner of a m x n grid (marked 'Start' in the
    // diagram below). The robot can only move either down or right at any point in time.
    // The robot is trying to reach the bottom-right corner of the grid (marked 'Finish'
    // in the diagram below). How many possible unique paths are there?

    // |--S--|-----|-----|-----|-----|-----|-----|
    // |-----|-----|-----|-----|-----|-----|-----|
    // |-----|-----|-----|-----|-----|-----|--F--|
    // Above is a 7 x 3 grid. How many possible unique paths are there?

    // Example 1:

    // Input: m = 3, n = 2
    // Output: 3
    // Explanation:
    // From the top-left corner, there are a total of 3 ways to reach the bottom-right
    // corner:
    // 1. Right -> Right -> Down
    // 2. Right -> Down -> Right
    // 3. Down -> Right -> Right

    // Example 2:
    // Input: m = 7, n = 3
    // Output: 28

    // Constraints:
    // 1 <= m, n <= 100
    // It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9
    struct UniquePath
    {
        // ----------------- RECURSION O(n^(m + 2)) TLE -------------
        int findPath_recursion(int m, int n)
        {
            if (m == 0 && n == 0)
                return 1;
            if (m < 0 || n < 0)
                return 0;

            return findPath_recursion(m - 1, n) + findPath_recursion(m, n - 1);
        }

        int uniquePath_recursion(int m, int n)
        {
            return findPath_recursion(m - 1, n - 1);
        }

        // ----------------- TOP DOWN O(n^2) ---------------
        int findPath_topdown(std::vector<std::vector<int>> &memo, int m, int n)
        {
            if (m == 0 && n == 0)
                return 1;
            if (m < 0 || n < 0)
                return 0;

            if (memo[m][n] != -1)
                return memo[m][n];

            memo[m][n] =
                findPath_topdown(memo, m - 1, n) + findPath_topdown(memo, m, n - 1);
            return memo[m][n];
        }

        int uniquePath_topdown(int m, int n)
        {
            std::vector<std::vector<int>> memo(m, std::vector<int>(n, -1));
            int count = findPath_topdown(memo, m - 1, n - 1);

            return count;
        }

        // ----------------- BOTTOM UP O(n^2) ---------------
        int uniquePath(int m, int n)
        {
            std::vector<std::vector<int>> grid(m, std::vector<int>(n));

            for (int i = 0; i < m; i++)
                grid[i][0] = 1;

            for (int i = 0; i < n; i++)
                grid[0][i] = 1;

            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
                }
            }

            return grid[m - 1][n - 1];
        }
    };
}  // namespace Leet::Medium
