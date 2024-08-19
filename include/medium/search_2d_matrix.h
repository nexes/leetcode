#pragma once

#include <vector>

namespace Leet::Medium {
    // You are given an m x n integer matrix matrix with the following two properties:

    // Each row is sorted in non-decreasing order.
    // The first integer of each row is greater than the last integer of the previous row.
    // Given an integer target, return true if target is in matrix or false otherwise.

    // You must write a solution in O(log(m * n)) time complexity.

    // Example 1:
    // Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    // Output: true

    // Example 2:
    // Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
    // Output: false

    // Constraints:
    // m == matrix.length
    // n == matrix[i].length
    // 1 <= m, n <= 100
    // -104 <= matrix[i][j], target <= 104
    struct Search2D
    {
        // O(log(m*n))
        bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
        {
            int m = matrix.size();
            int n = matrix[0].size();
            int row = 0;

            // binary search find the row
            int l = 0;
            int r = m - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;

                if (matrix[mid][0] <= target && matrix[mid][n - 1] >= target) {
                    row = mid;
                    break;
                }
                if (target < matrix[mid][0])
                    r = mid - 1;
                else
                    l = mid + 1;
            }

            // binary search the row
            l = 0;
            r = n - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;

                if (matrix[row][mid] == target)
                    return true;
                if (matrix[row][mid] < target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }

            return false;
        }

        // time: O(n + log(m)), space: O(1)
        bool searchMatrix_linear(std::vector<std::vector<int>>& matrix, int target)
        {
            int rows = matrix.size();

            // O(n)
            for (int i = 0; i < rows; i++) {
                auto row = matrix[i];

                if (target >= row[0] && target <= row[row.size() - 1])
                    return search(row, target);
            }

            return false;
        }

        // O(log(m))
        bool search(std::vector<int>& row, int target)
        {
            int low = 0;
            int high = row.size();
            int mid;

            while (low < high) {
                mid = (low + high) / 2;

                if (row[mid] == target)
                    return true;

                if (row[mid] > target) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }

            return false;
        }
    };
}  // namespace Leet::Medium
