#pragma once

#include <algorithm>
#include <vector>

namespace Leet::Medium {
    // Given an array nums with n objects colored red, white, or blue, sort
    // them in-place so that objects of the same color are adjacent, with the
    // colors in the order red, white, and blue. We will use the integers
    // 0, 1, and 2 to represent the color red, white, and blue, respectively.

    // Example 1:
    // Input: nums = [2,0,2,1,1,0]
    // Output: [0,0,1,1,2,2]

    // Example 2:
    // Input: nums = [2,0,1]
    // Output: [0,1,2]

    // Example 3:
    // Input: nums = [0]
    // Output: [0]

    // Example 4:
    // Input: nums = [1]
    // Output: [1]

    // Constraints:
    // n == nums.length
    // 1 <= n <= 300
    // nums[i] is 0, 1, or 2.

    // Follow up:
    // Could you solve this problem without using the library's sort function?
    // Could you come up with a one-pass algorithm using only O(1) constant space?
    struct SortColor
    {
        void sortColors(std::vector<int>& nums)
        {
            int zero = 0;
            int one = 0;
            int two = 0;

            // get the frequency
            for (const auto& num : nums) {
                if (num == 0)
                    zero++;
                if (num == 1)
                    one++;
                if (num == 2)
                    two++;
            }

            // while 'i' is less than the value of that numbers frequency
            // add it to the array
            for (int i = 0; i < nums.size(); i++) {
                if (i < zero)
                    nums[i] = 0;
                else if (i < zero + one)
                    nums[i] = 1;
                else if (i < zero + one + two)
                    nums[i] = 2;
            }
        }

        // not funny
        void sortColors_lol(std::vector<int>& nums)
        {
            std::sort(nums.begin(), nums.end());
        }
    };
}  // namespace Leet::Medium
