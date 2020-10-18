#pragma once

#include <vector>

namespace Leet::Medium {
    // Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

    // Example 1:
    // Input:
    // A: [1,2,3,2,1]
    // B: [3,2,1,4,7]
    // Output: 3

    // Explanation:
    // The repeated subarray with maximum length is [3, 2, 1].

    // Note:
    // 1 <= len(A), len(B) <= 1000
    // 0 <= A[i], B[i] < 100
    struct MaxSubArray
    {
        int findLength(std::vector<int>& a, std::vector<int>& b)
        {
            auto dp = std::vector<std::vector<int>>(a.size() + 1, std::vector<int>(b.size() + 1));
            int max = 0;

            for (int i = 0; i <= a.size(); i++)
                dp[i][0] = 0;

            for (int i = 0; i <= b.size(); i++)
                dp[0][i] = 0;

            for (int i = 1; i <= a.size(); i++) {
                for (int j = 1; j <= b.size(); j++) {
                    if (a[i - 1] == b[j - 1])
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    else
                        dp[i][j] = 0;

                    max = std::max(max, dp[i][j]);
                }
            }

            return max;
        }
    };
}  // namespace Leet::Medium
