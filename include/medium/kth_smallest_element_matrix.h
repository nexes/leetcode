#pragma once

#include <algorithm>
#include <vector>

namespace Leet::Medium {
    // Given an n x n matrix where each of the rows and columns are sorted
    // in ascending order, return the kth smallest element in the matrix.
    // Note that it is the kth smallest element in the sorted order, not
    // the kth distinct element.

    // Example 1:
    // Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
    // Output: 13
    // Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15],
    // and the 8th smallest number is 13

    // Example 2:
    // Input: matrix = [[-5]], k = 1
    // Output: -5

    // Constraints:
    // n == matrix.length
    // n == matrix[i].length
    // 1 <= n <= 300
    // -109 <= matrix[i][j] <= 109
    // All the rows and columns of matrix are guaranteed to be sorted in
    // non-decreasing order.
    // 1 <= k <= n2
    struct KthSmallestMatrix
    {
        int kthSmallest_naive(std::vector<std::vector<int>>& matrix, int k)
        {
            std::vector<int> flatten{};
            int rows = matrix.size();
            int cols = matrix[0].size();

            // O(n^2)
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    flatten.emplace_back(matrix[i][j]);
                }
            }

            // O(nlog(n))
            std::sort(flatten.begin(), flatten.end());

            return flatten[k - 1];
        }
    };
}  // namespace Leet::Medium
