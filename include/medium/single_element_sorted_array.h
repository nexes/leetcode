#pragma once

#include <vector>

namespace Leet::Medium {
    // You are given a sorted array consisting of only integers where every
    // element appears exactly twice, except for one element which appears
    // exactly once.

    // Return the single element that appears only once.
    // Your solution must run in O(log n) time and O(1) space.

    // Example 1:
    // Input: nums = [1,1,2,3,3,4,4,8,8]
    // Output: 2

    // Example 2:
    // Input: nums = [3,3,7,7,10,11,11]
    // Output: 10

    // Constraints:
    // 1 <= nums.length <= 105
    // 0 <= nums[i] <= 105
    struct SingleElementArray
    {
        // time: O(n) space: O(1)
        int singleNonDuplicate_linear(std::vector<int> &nums)
        {
            int value;

            if (nums.size() % 2 != 0) {
                value = nums[nums.size() - 1];
            }

            for (int i = 1; i < nums.size(); i += 2) {
                if (nums[i - 1] != nums[i])
                    return nums[i - 1];
            }

            return value;
        }

        // time: O(log(n)) space: O(1)
        int singleNonDuplicate(std::vector<int> &nums)
        {
            return 0;
        }
    };
}  // namespace Leet::Medium