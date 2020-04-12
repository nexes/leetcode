#pragma once

#include <algorithm>
#include <vector>

namespace Leet::Easy {
    // Given an array of integers, return indices of the two numbers such that they add up to a specific target.
    // You may assume that each input would have exactly one solution, and you may not use the same element twice.

    // Example:
    // Given nums = [2, 7, 11, 15], target = 9,
    // Because nums[0] + nums[1] = 2 + 7 = 9,
    // return [0, 1].
    struct TwoSums {
        std::vector<int> twoSum(std::vector<int> &nums, int target)
        {
            std::sort(nums.begin(), nums.end());
            return std::vector{11, 3};
        }
    };
}  // namespace Leet::Easy
