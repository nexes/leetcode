#pragma once

#include <vector>

namespace Leet::Medium {
    // You are given two positive integers n and k. A factor of an integer n is
    // defined as an integer i where n % i == 0. Consider a list of all factors
    // of n sorted in ascending order, return the kth factor in this list or
    // return -1 if n has less than k factors.

    // Example 1:
    // Input: n = 12, k = 3
    // Output: 3
    // Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.

    // Example 2:
    // Input: n = 7, k = 2
    // Output: 7
    // Explanation: Factors list is [1, 7], the 2nd factor is 7.

    // Example 3:
    // Input: n = 4, k = 4
    // Output: -1
    // Explanation: Factors list is [1, 2, 4], there is only 3 factors. We
    // should return -1.

    // Constraints:
    // 1 <= k <= n <= 1000

    // Follow up:
    // Could you solve this problem in less than O(n) complexity?
    struct KthFactor
    {
        // time: O(n)
        // space: O(n)
        int kthFactor(int n, int k)
        {
            int limit = n / 2;
            std::vector<int> factors;

            for (int i = 0; i <= limit; i++) {
                if (n % i == 0)
                    factors.push_back(i);
            }

            factors.push_back(n);

            return k <= factors.size() ? factors[k - 1] : -1;
        }

        // time: O(n)
        // space: O(1)
        int kthFactor(int n, int k)
        {
            int factor = 0;

            for (int i = 0; i <= n; i++) {
                if (n % i == 0)
                    factor++;

                if (factor == k)
                    return i;
            }

            return -1;
        }
    };
}  // namespace Leet::Medium