#pragma once

#include <vector>

namespace Leet::Medium {
    // Given an integer n, return all the numbers in the range [1, n] sorted in
    // lexicographical order.

    // You must write an algorithm that runs in O(n) time and uses O(1) extra space.

    // Example 1:
    // Input: n = 13
    // Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]

    // Example 2:
    // Input: n = 2
    // Output: [1,2]

    // Constraints:
    // 1 <= n <= 5 * 104
    struct LexicographicalNumbers
    {
        void dfs(std::vector<int> &values, int current, int limit)
        {
            if (current > limit)
                return;

            values.push_back(current);

            for (int i = 0; i <= 9; i++) {
                dfs(values, current * 10 + i, limit);
            }
        }

        std::vector<int> lexicalOrder(int n)
        {
            std::vector<int> values;

            for (int i = 1; i < 10; i++)
                dfs(values, i, n);

            return values;
        }

        std::vector<int> lexicalOrder_iterative(int n)
        {
            std::vector<int> values;
            int current = 1;

            while (values.size() < n) {
                values.push_back(current);
                current *= 10;

                if (current > n) {
                    while (current >= n || current % 10 == 9) {
                        current /= 10;
                    }
                    current++;
                }
            }

            return values;
        }
    };
}  // namespace Leet::Medium