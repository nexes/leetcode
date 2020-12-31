#pragma once

#include <algorithm>
#include <climits>
#include <stack>
#include <vector>

namespace Leet::Medium {
    // Given an array of n integers nums, a 132 pattern is a subsequence of three
    // integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
    // Return true if there is a 132 pattern in nums, otherwise, return false.
    // Follow up: The O(n^2) is trivial, could you come up with the O(n logn) or the O(n) solution?

    // Example 1:
    // Input: nums = [1,2,3,4]
    // Output: false
    // Explanation: There is no 132 pattern in the sequence.

    // Example 2:
    // Input: nums = [3,1,4,2]
    // Output: true
    // Explanation: There is a 132 pattern in the sequence: [1, 4, 2].

    // Example 3:
    // Input: nums = [-1,3,2,0]
    // Output: true
    // Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].

    // Constraints:
    // n == nums.length
    // 1 <= n <= 104
    // -109 <= nums[i] <= 109

    struct Pattern132
    {
        // O(n^3) brute force
        bool find132pattern_cubic(std::vector<int>& nums)
        {
            int len = nums.size();

            for (int i = 0; i < len - 2; i++) {
                for (int j = i + 1; j < len - 1; j++) {
                    for (int k = j + 1; k < len; k++) {
                        if (nums[i] < nums[k] && nums[k] < nums[j])
                            return true;
                    }
                }
            }
            return false;
        }

        // O(n^2) better brute force
        bool find132pattern_squared(std::vector<int>& nums)
        {
            // integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
            int len = nums.size();
            int i_val = INT_MAX;

            for (int j = 0; j < len - 1; j++) {
                i_val = std::min(i_val, nums[j]);

                for (int k = j + 1; j < len; j++) {
                    if (nums[k] < nums[j] && i_val < nums[k])
                        return true;
                }
            }

            return false;
        }

        // O(n) linear with a stack
        bool find132pattern_linear(std::vector<int>& nums)
        {
            auto stack = std::stack<int>{};
            auto min_val = std::vector<int>(nums.size());

            min_val[0] = nums[0];

            for (int i = 1; i < nums.size(); i++)
                min_val[i] = std::min(min_val[i - 1], nums[i]);

            return false;
        }
    };
}  // namespace Leet::Medium
