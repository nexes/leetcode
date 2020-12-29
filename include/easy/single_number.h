#pragma once

#include <map>
#include <vector>

namespace Leet::Easy {
    // Given a non-empty array of integers nums, every element appears twice
    // except for one. Find that single one. Follow up: Could you implement
    // a solution with a linear runtime complexity and without using extra memory?

    // Example 1:
    // Input: nums = [2,2,1]
    // Output: 1

    // Example 2:
    // Input: nums = [4,1,2,1,2]
    // Output: 4

    // Example 3:
    // Input: nums = [1]
    // Output: 1

    // Constraints:
    // 1 <= nums.length <= 3 * 104
    // -3 * 104 <= nums[i] <= 3 * 104
    // Each element in the array appears twice except for one element which appears only
    struct SingleNumber
    {
        // time: O(n) space: O(n)
        int singleNumber_map(std::vector<int>& nums)
        {
            auto freq = std::unordered_map<int, int>{};

            for (const auto& num : nums) {
                if (auto it = freq.emplace(num, 1); !it.second) {
                    freq[num]++;
                }
            }

            for (const auto& [k, v] : freq) {
                if (v == 1)
                    return k;
            }

            return 0;
        }

        // if we take XOR of zero and some bit, it will return that bit
        //     a⊕0=a
        // If we take XOR of two same bits, it will return 0
        //     a⊕a=0
        //
        // a⊕b⊕a=(a⊕a)⊕b=0⊕b=b
        //
        // time: O(n) space: O(1)
        int singleNumber(std::vector<int>& nums)
        {
            int val = nums[0];

            for (int i = 1; i < nums.size(); i++) {
                val = val ^ nums[i];
            }

            return val;
        }
    };
}  // namespace Leet::Easy
