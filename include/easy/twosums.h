#pragma once

#include <unordered_map>
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
            int len = nums.size();
            std::unordered_map<int, int> result;

            for (int i = 0; i < len; i++) {
                if (auto found = result.find(target - nums.at(i)); found != result.end()) {
                    return std::vector{found->second, i};
                }

                result.emplace(std::make_pair(nums.at(i), i));
            }

            return std::vector{0, 0};
        }
    };
}  // namespace Leet::Easy
