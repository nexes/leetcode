#pragma once

#include <vector>

namespace Leet::Easy {
    // Given an integer array nums, find the contiguous subarray (containing at least one number)
    // which has the largest sum and return its sum.

    // Example:
    // Input: [-2,1,-3,4,-1,2,1,-5,4],
    // Output: 6
    // Explanation: [4,-1,2,1] has the largest sum = 6.

    // Follow up:
    // If you have figured out the O(n) solution, try coding another solution using the
    // divide and conquer approach, which is more subtle.
    struct MaxSubArray
    {
        // linear
        int maxSubArray(std::vector<int> &nums)
        {
            if (nums.empty())
                return 0;

            int sum = nums[0];
            int curr = 0;

            for (auto &val : nums) {
                if (curr < 0)
                    curr = 0;
                curr += val;
                sum = std::max(sum, curr);
            }

            return sum;
        }
    };
}  // namespace Leet::Easy
