#pragma once

#include <algorithm>
#include <vector>

namespace Leet::Medium {
    // Given an m x n binary matrix filled with 0's and 1's, find the largest square
    // containing only 1's and return its area. Given an m x n binary matrix filled with
    // 0's and 1's, find the largest square containing only 1's and return its area.

    // Example 1:
    // Input: matrix =
    // [
    //  ["1","0","1","0","0"],
    //  ["1","0","1","1","1"],
    //  ["1","1","1","1","1"],
    //  ["1","0","0","1","0"]
    // ]
    // Output: 4

    // Example 2:
    // Input: matrix = [["0","1"],["1","0"]]
    // Output: 1

    // Example 3:
    // Input: matrix = [["0"]]
    // Output: 0

    // Constraints:
    // m == matrix.length
    // n == matrix[i].length
    // 1 <= m, n <= 300
    // matrix[i][j] is '0' or '1'.
    struct MaxSquare
    {
        int maximalSquare(std::vector<std::vector<char>>& matrix)
        {
            auto dp = std::vector<std::vector<int>>(
                matrix.size() + 1, std::vector<int>(matrix[0].size() + 1, 0));

            int row_len = matrix.size();
            int col_len = matrix[0].size();
            int max_square = 0;

            for (int row = 1; row <= row_len; row++) {
                for (int col = 1; col <= col_len; col++) {
                    if (matrix[row - 1][col - 1] == '1') {
                        dp[row][col] =
                            1 + std::min(std::min(dp[row - 1][col], dp[row][col - 1]),
                                         dp[row - 1][col - 1]);
                        max_square = std::max(max_square, dp[row][col]);
                    }
                }
            }

            return max_square * max_square;
        }
    };
}  // namespace Leet::Medium
