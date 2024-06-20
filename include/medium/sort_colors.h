#pragma once

#include <algorithm>
#include <map>
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
        // Dutch flag algorithem
        // time: O(n)
        // space: O(1)
        void sortColors(std::vector<int>& nums)
        {
            int l = 0;
            int m = 0;
            int h = nums.size() - 1;

            while (m <= h) {
                switch (nums[m]) {
                case 0:
                    std::swap(nums[l], nums[m]);
                    l++;
                    m++;
                    break;
                case 1:
                    m++;
                    break;
                case 2:
                    std::swap(nums[m], nums[h]);
                    h--;
                    break;
                }
            }
        }

        // use a map to hold the frequency and then place that many items
        // into the array
        // time: O(nlog(n))
        // space: O(n)
        void sortColors_map(std::vector<int>& nums)
        {
            std::map<int, int> freq;

            for (int num : nums)
                freq[num]++;

            int i = 0;
            for (auto& value : freq) {
                int limit = i + value.second;
                while (i < limit)
                    nums[i++] = value.first;
            }
        }

        // not funny
        void sortColors_lol(std::vector<int>& nums)
        {
            std::sort(nums.begin(), nums.end());
        }
    };
}  // namespace Leet::Medium
