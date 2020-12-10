#pragma once

#include <algorithm>
#include <vector>

namespace Leet::Easy {
    // Given an integer array nums, find three numbers whose product is
    // maximum and return the maximum product.

    // Example 1:
    // Input: nums = [1,2,3]
    // Output: 6

    // Example 2:
    // Input: nums = [1,2,3,4]
    // Output: 24

    // Example 3:
    // Input: nums = [-1,-2,-3]
    // Output: -6

    // Constraints:
    // 3 <= nums.length <= 104
    // -1000 <= nums[i] <= 1000
    struct MaxProduct
    {
        int maximumProduct(std::vector<int>& nums)
        {
            std::sort(nums.begin(), nums.end());
            int len = nums.size();
            int check1 = nums[0] * nums[1] * nums[2];
            int check2 = nums[len - 1] * nums[len - 2] * nums[len - 3];
            int check3 = nums[0] * nums[1] * nums[len - 1];

            int prod = std::max(check1, std::max(check2, check3));

            return prod;
        }
    };
}  // namespace Leet::Easy
