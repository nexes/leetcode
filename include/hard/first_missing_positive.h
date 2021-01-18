#pragma once

#include <algorithm>
#include <vector>

namespace Leet::Hard {
    // Given an unsorted integer array nums, find the smallest missing positive integer.
    // Follow up: Could you implement an algorithm that runs in O(n) time and uses
    // constant extra space?

    // Example 1:
    // Input: nums = [1,2,0]
    // Output: 3

    // Example 2:
    // Input: nums = [3,4,-1,1]
    // Output: 2

    // -1, 4, 3, 1
    // -1, 1, 3, 4
    // 1, -1, 3, 4

    // Example 3:
    // Input: nums = [7,8,9,11,12]
    // Output: 1

    // Constraints:
    // 0 <= nums.length <= 300
    // -231 <= nums[i] <= 231 - 1
    struct FirstPositive
    {
        // sorting O(nlog(n)) space: O(1)
        int firstMissingPositive_log(std::vector<int>& nums)
        {
            int missing = 1;

            std::sort(nums.begin(), nums.end());

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > 0) {
                    if (missing == nums[i])
                        missing = nums[i] + 1;
                }
            }

            return missing;
        }
    };
}  // namespace Leet::Hard
