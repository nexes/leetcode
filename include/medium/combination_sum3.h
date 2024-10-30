#pragma once

#include <vector>

using std::vector;

namespace Leet::Medium {
    // Find all valid combinations of k numbers that sum up to n such that the following
    // conditions are true:

    // Only numbers 1 through 9 are used.
    // Each number is used at most once.
    // Return a list of all possible valid combinations. The list must not contain the
    // same combination twice, and the combinations may be returned in any order.

    // Example 1:
    // Input: k = 3, n = 7
    // Output: [[1,2,4]]
    // Explanation:
    // 1 + 2 + 4 = 7
    // There are no other valid combinations.

    // Example 2:
    // Input: k = 3, n = 9
    // Output: [[1,2,6],[1,3,5],[2,3,4]]
    // Explanation:
    // 1 + 2 + 6 = 9
    // 1 + 3 + 5 = 9
    // 2 + 3 + 4 = 9
    // There are no other valid combinations.

    // Example 3:
    // Input: k = 4, n = 1
    // Output: []
    // Explanation: There are no valid combinations.
    // Using 4 different numbers in the range [1,9], the smallest sum we can get is
    // 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.

    // Constraints:
    // 2 <= k <= 9
    // 1 <= n <= 60
    struct CombinationSum3
    {
        void generate(vector<vector<int>>& sums, vector<int>& curr, int k, int target,
                      int idx)
        {
            if (target == 0) {
                if (curr.size() == k)
                    sums.push_back(curr);
                return;
            }

            for (int i = idx; i <= 9; i++) {
                if (target - i >= 0) {
                    curr.push_back(i);
                    generate(sums, curr, k, target - i, i + 1);
                    curr.pop_back();
                }
            }
        }

        vector<vector<int>> combinationSum3(int k, int n)
        {
            vector<vector<int>> sums;
            vector<int> curr;

            generate(sums, curr, k, n, 1);
            return sums;
        }
    };
}  // namespace Leet::Medium