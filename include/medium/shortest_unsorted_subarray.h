#pragma once

#include <algorithm>
#include <vector>

namespace Leet::Medium {
    // Given an integer array nums, you need to find one continuous subarray that if you
    // only sort this subarray in ascending order, then the whole array will be sorted in
    // ascending order. Return the shortest such subarray and output its length.

    // Example 1:
    // Input: nums = [2,6,4,8,10,9,15]
    // Output: 5
    // Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole
    // array sorted in ascending order.

    // Example 2:
    // Input: nums = [1,2,3,4]
    // Output: 0

    // Example 3:
    // Input: nums = [1]
    // Output: 0

    // Constraints:
    // 1 <= nums.length <= 104
    // -105 <= nums[i] <= 105
    struct ShortestSubarray
    {
        // time: O(nlog(n)) space: O(n)
        int findUnsortedSubarray(std::vector<int>& nums)
        {
            int left = nums.size() - 1;
            int right = 0;
            auto sorted_nums = nums;

            std::sort(sorted_nums.begin(), sorted_nums.end());

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] != sorted_nums[i]) {
                    left = std::min(left, i);
                    right = std::max(right, i);
                }
            }

            return right == 0 ? 0 : right - left + 1;
        }
    };
}  // namespace Leet::Medium
