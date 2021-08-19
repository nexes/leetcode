#pragma once

#include <vector>

namespace Leet::Easy {
    using std::vector;

    // Given a 2D integer array matrix, return the transpose of matrix.
    // The transpose of a matrix is the matrix flipped over its main diagonal, switching
    // the matrix's row and column indices.

    // Example 1:
    // Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    // Output: [[1,4,7],[2,5,8],[3,6,9]]

    // Example 2:
    // Input: matrix = [[1,2,3],[4,5,6]]
    // Output: [[1,4],[2,5],[3,6]]

    // Constraints:
    // m == matrix.length
    // n == matrix[i].length
    // 1 <= m, n <= 1000
    // 1 <= m * n <= 105
    // -109 <= matrix[i][j] <= 109
    struct TransposeMatrix
    {
        vector<vector<int>> transpose(vector<vector<int>>& matrix)
        {
            vector<vector<int>> transposed(matrix[0].size(), vector<int>(matrix.size()));

            for (int row = 0; row < matrix.size(); row++) {
                for (int col = 0; col < matrix[0].size(); col++) {
                    transposed[col][row] = matrix[row][col];
                }
            }

            return transposed;
        }
    };
}  // namespace Leet::Easy
