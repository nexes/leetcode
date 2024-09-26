#pragma once

#include <vector>

using std::vector;

namespace Leet::Medium {
    // Given an n x n array of integers matrix, return the minimum sum of any falling path
    // through matrix.

    // A falling path starts at any element in the first row and chooses the element in
    // the next row that is either directly below or diagonally left/right. Specifically,
    // the next element from position (row, col) will be (row + 1, col - 1), (row + 1,
    // col), or (row + 1, col + 1).

    // Example 1:
    // Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
    // Output: 13
    // Explanation: There are two falling paths with a minimum sum as shown.

    // Example 2:
    // Input: matrix = [[-19,57],[-40,-5]]
    // Output: -59
    // Explanation: The falling path with a minimum sum is shown.

    // Constraints:
    // n == matrix.length == matrix[i].length
    // 1 <= n <= 100
    // -100 <= matrix[i][j] <= 100
    struct MinFallingPathSum
    {
        // ----------------- RECURSION : TLE ------------------
        int findPath_recursion(vector<vector<int>> &matrix, int r, int c)
        {
            if (c < 0 || c >= matrix[r].size())
                return 1e9;
            if (r == 0)
                return matrix[r][c];

            int goLeft = matrix[r][c] + findPath_recursion(matrix, r - 1, c - 1);
            int middle = matrix[r][c] + findPath_recursion(matrix, r - 1, c);
            int goRight = matrix[r][c] + findPath_recursion(matrix, r - 1, c + 1);

            return std::min({goLeft, middle, goRight});
        }

        int minFallingPathSum_recursion(vector<vector<int>> &matrix)
        {
            int minPath = 1e9;
            vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), 1e9));

            for (int i = 0; i < matrix[0].size(); i++)
                minPath =
                    std::min(minPath, findPath_recursion(matrix, matrix.size() - 1, i));

            return minPath;
        }

        // ----------------- TOP DOWN : DP O(n^2)------------------
        int findPath_topdown(vector<vector<int>> &matrix, vector<vector<int>> &memo,
                             int r, int c)
        {
            if (c < 0 || c >= matrix[r].size())
                return 1e9;
            if (r == 0)
                return matrix[r][c];

            if (memo[r][c] != 1e9)
                return memo[r][c];

            int goLeft = matrix[r][c] + findPath_topdown(matrix, memo, r - 1, c - 1);
            int middle = matrix[r][c] + findPath_topdown(matrix, memo, r - 1, c);
            int goRight = matrix[r][c] + findPath_topdown(matrix, memo, r - 1, c + 1);

            memo[r][c] = std::min({goLeft, middle, goRight});
            return memo[r][c];
        }

        int minFallingPathSum_topdown(vector<vector<int>> &matrix)
        {
            int minPath = 1e9;
            vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), 1e9));

            for (int i = 0; i < matrix[0].size(); i++)
                minPath = std::min(minPath,
                                   findPath_topdown(matrix, memo, matrix.size() - 1, i));

            return minPath;
        }

        // ----------------- BOTTOM UP : DP O(n^2)------------------
        int minFallingPathSum(vector<vector<int>> &matrix)
        {
            int rowLen = matrix.size();
            int colLen = matrix[0].size();

            vector<vector<int>> memo(rowLen, vector<int>(colLen, 1e9));

            // set the first row
            for (int i = 0; i < colLen; i++)
                memo[0][i] = matrix[0][i];

            for (int i = 1; i < rowLen; i++) {
                for (int j = 0; j < colLen; j++) {
                    int left = 1e9;
                    int right = 1e9;
                    int middle = memo[i - 1][j];

                    if (j > 0)
                        left = memo[i - 1][j - 1];
                    if (j < colLen - 1)
                        right = memo[i - 1][j + 1];

                    memo[i][j] = matrix[i][j] + std::min({left, middle, right});
                }
            }

            // since we don't know which col the answer is at, we need to check all of
            // them
            int minSum = INT_MAX;
            for (int i = 0; i < colLen; i++)
                minSum = std::min(minSum, memo[colLen - 1][i]);

            return minSum;
        }
    };
}  // namespace Leet::Medium