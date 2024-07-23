#pragma once

#include <algorithm>
#include <unordered_set>
#include <vector>

namespace Leet::Medium {
    // Given an unsorted array of integers nums, return the length of the longest
    // consecutive elements sequence. You must write an algorithm that runs in O(n) time.

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
            int longest = 0;
            int current = 1;

            if (nums.empty())
                return 0;

            std::sort(nums.begin(), nums.end());

            for (int i = 1; i < nums.size(); i++) {
                // pass duplicates
                if (nums[i - 1] != nums[i]) {
                    if (nums[i - 1] + 1 == nums[i]) {
                        current++;
                    } else {
                        longest = std::max(longest, current);
                        current = 1;
                    }
                }
            }

            return std::max(longest, current);
        }

        // time: O(n) space: O(n)
        int longestConsecutive_linear(std::vector<int>& nums)
        {
            int seq_len = 0;
            std::unordered_set<int> values;

            // O(n)
            for (int num : nums)
                values.insert(num);

            // O(n)
            for (int num : values) {
                // check if we are the beginning of a sequence
                // if we are, count from here
                if (values.count(num - 1) == 0) {
                    int curr_len = 0;
                    while (values.count(num++) == 1)
                        curr_len++;

                    seq_len = std::max(seq_len, curr_len);
                }
            }

            return seq_len;
        }
    };
}  // namespace Leet::Medium
