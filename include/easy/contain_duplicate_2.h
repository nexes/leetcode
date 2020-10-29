#pragma once

#include <unordered_map>
#include <vector>

namespace Leet::Easy {

    // Given an array of integers and an integer k, find out whether there are two
    // distinct indices i and j in the array such that nums[i] = nums[j] and the absolute
    // difference between i and j is at most k.

    // Example 1:
    // Input: nums = [1,2,3,1], k = 3
    // Output: true

    // Example 2:
    // Input: nums = [1,0,1,1], k = 1
    // Output: true

    // Example 3:
    // Input: nums = [1,2,3,1,2,3], k = 2
    // Output: false
    struct Duplicate2
    {
        bool containsNearbyDuplicate(std::vector<int> &nums, int k)
        {
            std::unordered_map<int, int> map;

            for (int i = 0; i < nums.size(); i++) {
                if (auto check = map.insert(std::make_pair(nums[i], i)); !check.second) {
                    if (i - check.first->second <= k)
                        return true;

                    // update to the newest index
                    map[nums[i]] = i;
                }
            }

            return false;
        }
    };
}  // namespace Leet::Easy
