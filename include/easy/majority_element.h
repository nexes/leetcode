#pragma once

#include <algorithm>
#include <unordered_map>
#include <vector>

namespace Leet::Easy {
    // Given an array of size n, find the majority element. The majority element
    // is the element that appears more than ⌊ n/2 ⌋ times. You may assume that
    // the array is non-empty and the majority element always exist in the array.

    // Example 1:
    // Input: [3,2,3]
    // Output: 3

    // Example 2:
    // Input: [2,2,1,1,1,2,2]
    // Output: 2
    struct MajorityElement
    {
        // time: O(n), space: O(n)
        int majorityElement(std::vector<int>& nums)
        {
            auto freq = std::unordered_map<int, int>{};
            int max = 0;

            for (auto value : nums) {
                if (auto it = freq.emplace(value, 1); !it.second) {
                    freq[value]++;
                }
            }

            for (auto value : freq) {
                if (value.second > nums.size() / 2)
                    max = value.first;
            }

            return max;
        }

        // time: O(nlog(n)), space: O(1)
        int majorityElement_clever(std::vector<int>& nums)
        {
            std::sort(nums.begin(), nums.end());
            return nums[nums.size() / 2];
        }
    };
}  // namespace Leet::Easy
