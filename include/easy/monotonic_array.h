#pragma once

#include <vector>

namespace Leet::Easy {
    // An array is monotonic if it is either monotone increasing or monotone decreasing.
    // An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An
    // array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

    // Given an integer array nums, return true if the given array is monotonic, or false
    // otherwise.

    // Example 1:
    // Input: nums = [1,2,2,3]
    // Output: true

    // Example 2:
    // Input: nums = [6,5,4,4]
    // Output: true

    // Example 3:
    // Input: nums = [1,3,2]
    // Output: false

    // Example 4:
    // Input: nums = [1,2,4,5]
    // Output: true

    // Example 5:
    // Input: nums = [1,1,1]
    // Output: true

    // Constraints:
    // 1 <= nums.length <= 105
    // -105 <= nums[i] <= 105
    struct Monotonic
    {
        bool isMonotonic_twopass(std::vector<int>& nums)
        {
            bool is_monotonic = true;

            // check if monotonic increasing
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i - 1] > nums[i]) {
                    is_monotonic = false;
                    break;
                }
            }

            if (is_monotonic)
                return true;

            is_monotonic = true;

            // check if monotonic decreasing
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i - 1] < nums[i]) {
                    is_monotonic = false;
                    break;
                }
            }

            return is_monotonic;
        }

        bool isMonotonic_onepass(std::vector<int>& nums)
        {
            bool is_decreasing = true;
            bool is_increasing = true;

            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] > nums[i - 1])
                    is_decreasing = false;

                if (nums[i] < nums[i - 1])
                    is_increasing = false;
            }

            return is_decreasing || is_increasing;
        }
    };
}  // namespace Leet::Easy
