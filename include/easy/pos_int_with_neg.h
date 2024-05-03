#pragma once

#include <unordered_map>
#include <vector>

namespace Leet::Easy {
    // Given an integer array nums that does not contain any zeros, find the largest
    // positive integer k such that -k also exists in the array. Return the positive
    // integer k. If there is no such integer, return -1.

    // Example 1:
    // Input: nums = [-1,2,-3,3]
    // Output: 3
    // Explanation: 3 is the only valid k we can find in the array.

    // Example 2:
    // Input: nums = [-1,10,6,7,-7,1]
    // Output: 7
    // Explanation: Both 1 and 7 have their corresponding negative values in the array. 7
    // has a larger value.

    // Example 3:
    // Input: nums = [-10,8,6,7,-2,-3]
    // Output: -1
    // Explanation: There is no a single valid k, we return -1.

    // Constraints:
    // 1 <= nums.length <= 1000
    // -1000 <= nums[i] <= 1000
    // nums[i] != 0
    struct PositiveNumWithNegative
    {
        // with map, time: O(n), space: O(n)
        int findMaxK(std::vector<int> &nums)
        {
            int val = -1;
            std::unordered_map<int, bool> imap{};

            for (int num : nums) {
                if (auto value = imap.find(num * -1); value != imap.end()) {
                    val = std::max(std::abs(num), val);
                } else {
                    imap[num] = true;
                }
            }

            return val;
        }

        // with map, time: O(nlog(n)), space: O(1)
        int findMaxK_loop(std::vector<int> &nums)
        {
            int l = 0;
            int r = nums.size() - 1;

            std::sort(nums.begin(), nums.end());

            while (l < r) {
                if (nums[l] * -1 == nums[r])
                    return nums[r];

                if (std::abs(nums[l]) < nums[r])
                    r--;
                else
                    l++;
            }

            return -1;
        }
    };
}  // namespace Leet::Easy