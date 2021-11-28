#pragma once

#include <algorithm>
#include <vector>

namespace Leet::Medium {
    // Given an integer n, break it into the sum of k positive integers,
    // where k >= 2, and maximize the product of those integers. Return
    // the maximum product you can get.

    // Example 1:
    // Input: n = 2
    // Output: 1
    // Explanation: 2 = 1 + 1, 1 × 1 = 1.

    // Example 2:
    // Input: n = 10
    // Output: 36
    // Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

    // Constraints:
    // 2 <= n <= 58
    struct IntegerBreak
    {
        // correct buy time limit exceeded
        int integerBreak_slow(int n)
        {
            if (n <= 3)
                return n - 1;

            int prod = 1;

            for (int i = n - 1; i > 1; i--) {
                for (int j = 2; j < n; j++) {
                    if (i + j == n) {
                        int p =
                            std::max(i, integerBreak(i)) * std::max(j, integerBreak(j));
                        prod = std::max(prod, p);
                    }
                }
            }

            return prod;
        }

        // time: O(n^2), space: O(n)
        int integerBreak(int n)
        {
            std::vector<int> dp(n + 1, 0);

            dp[1] = 1;
            dp[2] = 1;

            for (int i = 3; i <= n; i++) {
                for (int j = 1; j < i - 1; j++) {
                    dp[i] = std::max(j * dp[i - j], std::max(dp[i], j * (i - j)));
                }
            }

            return dp[n];
        }
    };
}  // namespace Leet::Medium
