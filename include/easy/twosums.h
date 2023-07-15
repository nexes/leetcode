#pragma once

#include <algorithm>
#include <unordered_map>
#include <vector>

namespace Leet::Easy {
    // Given an array of integers, return indices of the two numbers such that
    // they add up to a specific target. You may assume that each input would
    // have exactly one solution, and you may not use the same element twice.

    // Example:
    // Given nums = [2, 7, 11, 15], target = 9,
    // Because nums[0] + nums[1] = 2 + 7 = 9,
    // return [0, 1].
    struct TwoSums
    {
        // time: O(n)
        // space: O(n)
        std::vector<int> twoSum(std::vector<int> &nums, int target)
        {
            std::unordered_map<int, int> loc;
            std::vector<int> pair(2, -1);

            for (int i = 0; i < nums.size(); i++) {
                if (auto it = loc.find(target - nums[i]); it != loc.end()) {
                    pair[0] = it->second;
                    pair[1] = i;
                    break;
                } else {
                    loc[nums[i]] = i;
                }
            }

            return pair;
        }
    };
}  // namespace Leet::Easy
