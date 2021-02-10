#pragma once

#include <set>
#include <vector>

namespace Leet::Medium {
    // Given an m x n matrix. If an element is 0, set its entire row and
    // column to 0. Do it in-place.

    // Follow up:
    // A straight forward solution using O(mn) space is probably a bad idea.
    // A simple improvement uses O(m + n) space, but still not the best solution.
    // Could you devise a constant space solution?

    // Example 1:
    // Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
    // Output: [[1,0,1],[0,0,0],[1,0,1]]

    // Example 2:
    // Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
    // Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

    // Constraints:
    // m == matrix.length
    // n == matrix[0].length
    // 1 <= m, n <= 200
    // -231 <= matrix[i][j] <= 231 - 1
    struct MatrixZero
    {
        // not using constant space.
        void zetZeroes(std::vector<std::vector<int>>& matrix)
        {
            std::set<int> cols{};
            std::set<int> rows{};
            int row_size = matrix.size();
            int col_size = matrix[0].size();

            // find locations of zeros
            for (int row = 0; row < row_size; row++) {
                for (int col = 0; col < col_size; col++) {
                    if (matrix[row][col] == 0) {
                        rows.emplace(row);
                        cols.emplace(col);
                    }
                }
            }

            // clear rows
            for (const auto& row : rows) {
                for (int col = 0; col < col_size; col++) {
                    matrix[row][col] = 0;
                }
            }

            // clear cols
            for (const auto& col : cols) {
                for (int row = 0; row < row_size; row++) {
                    matrix[row][col] = 0;
                }
            }
        }

        // space O(1)
        void zetZeroes_constant_space(std::vector<std::vector<int>>& matrix)
        {
            int row_size = matrix.size();
            int col_size = matrix[0].size();
            bool zero_col = false;
            bool zero_row = false;

            // when we find a zero, mark the first cell in that row and col as
            // zero
            for (int row = 0; row < row_size; row++) {
                for (int col = 0; col < col_size; col++) {
                    if (matrix[row][col] == 0) {
                        if (row == 0) zero_row = true;
                        if (col == 0) zero_col = true;

                        matrix[row][0] = 0;
                        matrix[0][col] = 0;
                    }
                }
            }

            // start at [1,1] and if the starting cell in that row and col is zero
            // set [row, col] to zero
            for (int row = 1; row < row_size; row++) {
                for (int col = 1; col < col_size; col++) {
                    if (matrix[row][0] == 0 || matrix[0][col] == 0)
                        matrix[row][col] = 0;
                }
            }

            // clear first row if needed
            if (zero_row)
                for (int i = 0; i < col_size; i++)
                    matrix[0][i] = 0;

            // clear first column if needed
            if (zero_col)
                for (int i = 0; i < row_size; i++)
                    matrix[i][0] = 0;
        }
    };
}  // namespace Leet::Medium
