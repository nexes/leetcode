#pragma once

#include <algorithm>
#include <unordered_map>
#include <vector>

namespace Leet::Medium {
    // Given an unsorted array of integers nums, return the length of the longest
    //consecutive elements sequence. You must write an algorithm that runs in O(n) time.

    // Example 1:
    // Input: nums = [100,4,200,1,3,2]
    // Output: 4
    // Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
    // Therefore its length is 4.

    // Example 2:
    // Input: nums = [0,3,7,2,5,8,4,6,0,1]
    // Output: 9

    // Constraints:
    // 0 <= nums.length <= 105
    // -109 <= nums[i] <= 109
    struct LongestSequence
    {
        // time: O(nlog(n)) space: O(1)
        int longestConsecutive(std::vector<int>& nums)
        {
            if (nums.size() < 1)
                return 0;

            int length = 1;
            int count = 1;
            std::sort(nums.begin(), nums.end());

            for (int i = 1; i < nums.size(); i++) {
                if (nums[i - 1] != nums[i]) {
                    if (nums[i - 1] == nums[i] - 1) {
                        count++;
                    } else {
                        length = std::max(length, count);
                        count = 1;
                    }
                }
            }

            return std::max(length, count);
        }

        // time: O(n) space: O(n)
        int longestConsecutive_linear(std::vector<int>& nums)
        {
            if (nums.size() < 1)
                return 0;

            std::unordered_map<int, int> values{};
            int length = 1;

            for (auto num : nums)
                values[num]++;

            for (auto num : nums) {
                if (values.find(num - 1) != values.end())
                    continue;

                int current = num;
                int current_len = 1;
                while (values.find(current + 1) != values.end()) {
                    current++;
                    current_len++;
                }

                length = std::max(length, current_len);
            }

            return length;
        }
    };
}  // namespace Leet::Medium
