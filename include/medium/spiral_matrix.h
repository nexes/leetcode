#pragma once

#include <vector>

using std::vector;

namespace Leet::Medium {
    // Given an m x n matrix, return all elements of the matrix in spiral order.

    // Example 1:
    // Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    // Output: [1,2,3,6,9,8,7,4,5]
    // Example 2:

    // Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    // Output: [1,2,3,4,8,12,11,10,9,5,6,7]

    // Constraints:
    // m == matrix.length
    // n == matrix[i].length
    // 1 <= m, n <= 10
    // -100 <= matrix[i][j] <= 100
    struct SprialMatrix
    {
        vector<int> spiralOrder(vector<vector<int>> &matrix)
        {
            int left = 0;
            int top = 0;
            int right = matrix[0].size();
            int bottom = matrix.size();
            vector<int> spiral;

            while (left < right && top < bottom) {
                // move right
                for (int i = left; i < right; i++) {
                    spiral.push_back(matrix[top][i]);
                }
                top++;

                // move down
                for (int i = top; i < bottom; i++) {
                    spiral.push_back(matrix[i][right - 1]);
                }
                right--;

                // check our bounds still hold true
                if (left >= right || top >= bottom)
                    break;

                // move left
                for (int i = right - 1; i >= left; i--) {
                    spiral.push_back(matrix[bottom - 1][i]);
                }
                bottom--;

                // move up
                for (int i = bottom - 1; i >= top; i--) {
                    spiral.push_back(matrix[i][left]);
                }
                left++;
            }

            return spiral;
        }
    };
}  // namespace Leet::Medium