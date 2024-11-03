#pragma once

#include <vector>

using std::vector;

namespace Leet::Medium {
    // Given a m * n matrix of ones and zeros, return how many square submatrices have all
    // ones.

    // Example 1:
    // Input: matrix =
    // [
    //   [0,1,1,1],
    //   [1,1,1,1],
    //   [0,1,1,1]
    // ]
    // Output: 15
    // Explanation:
    // There are 10 squares of side 1.
    // There are 4 squares of side 2.
    // There is  1 square of side 3.
    // Total number of squares = 10 + 4 + 1 = 15.

    // Example 2:
    // Input: matrix =
    // [
    //   [1,0,1],
    //   [1,1,0],
    //   [1,1,0]
    // ]
    // Output: 7
    // Explanation:
    // There are 6 squares of side 1.
    // There is 1 square of side 2.
    // Total number of squares = 6 + 1 = 7.

    // Constraints:
    // 1 <= arr.length <= 300
    // 1 <= arr[0].length <= 300
    // 0 <= arr[i][j] <= 1
    struct CountSubMatrices
    {
        // TOP DOWN DP
        int count(vector<vector<int>>& matrix, vector<vector<int>>& memo, int i, int j)
        {
            if (i >= matrix.size() || j >= matrix[0].size())
                return 0;
            if (matrix[i][j] == 0)
                return 0;

            if (memo[i][j] != -1)
                return memo[i][j];

            int c = 1 + std::min({count(matrix, memo, i, j + 1),
                                  count(matrix, memo, i + 1, j),
                                  count(matrix, memo, i + 1, j + 1)});

            return memo[i][j] = c;
        }

        int countSquares(vector<vector<int>>& matrix)
        {
            int maxCount = 0;
            vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), -1));

            for (int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix[0].size(); j++) {
                    if (matrix[i][j] == 1)
                        maxCount += count(matrix, memo, i, j);
                }
            }

            return maxCount;
        }
    };
}  // namespace Leet::Medium