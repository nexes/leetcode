#pragma once

#include <vector>

namespace Leet::Medium {
    // You are given an n x n 2D matrix representing an image, rotate the image by
    // 90 degrees (clockwise). You have to rotate the image in-place, which means
    // you have to modify the input 2D matrix directly.
    // DO NOT allocate another 2D matrix and do the rotation.

    // Example 1:
    // Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    // Output: [[7,4,1],[8,5,2],[9,6,3]]

    // Example 2:
    // Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
    // Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

    // Example 3:
    // Input: matrix = [[1]]
    // Output: [[1]]

    // Example 4:
    // Input: matrix = [[1,2],[3,4]]
    // Output: [[3,1],[4,2]]

    // Constraints:
    // matrix.length == n
    // matrix[i].length == n
    // 1 <= n <= 20
    // -1000 <= matrix[i][j] <= 1000
    struct RotateImage
    {
        // using swaps, time: O(n^2) space: O(1)
        void rotate_with_swaps(std::vector<std::vector<int>>& matrix)
        {
            int size = matrix.size();

            for (int row = 0; row < size / 2; row++) {
                for (int col = row; col < size - row - 1; col++) {
                    auto temp = matrix[row][col];
                    matrix[row][col] = matrix[size - col - 1][row];
                    matrix[size - col - 1][row] = matrix[size - row - 1][size - col - 1];
                    matrix[size - row - 1][size - col - 1] = matrix[col][size - row - 1];
                    matrix[col][size - row - 1] = temp;
                }
            }
        }

        // using transpose, time: O(n^2) space: O(1)
        void rotate(std::vector<std::vector<int>>& matrix)
        {
            int size = matrix.size();

            // transpose our matrix
            for (int i = 0; i < size; i++) {
                for (int j = i; j < size; j++) {
                    auto temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }

            // reverse our matrix
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size / 2; j++) {
                    auto temp = matrix[i][j];
                    matrix[i][j] = matrix[i][size - j - 1];
                    matrix[i][size - j - 1] = temp;
                }
            }
        }
    };
}  // namespace Leet::Medium
