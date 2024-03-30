#pragma once

#include <vector>

namespace Leet::Medium {
    // Given a binary array nums and an integer goal, return the number of non-empty
    // subarrays with a sum goal. A subarray is a contiguous part of the array.

    // Example 1:
    // Input: nums = [1,0,1,0,1], goal = 2
    // Output: 4
    // Explanation: The 4 subarrays are bolded and underlined below:
    // [1,0,1,0,1]
    // [1,0,1,0,1]
    // [1,0,1,0,1]
    // [1,0,1,0,1]

    // Example 2:
    // Input: nums = [0,0,0,0,0], goal = 0
    // Output: 15

    // Constraints:
    // 1 <= nums.length <= 3 * 104
    // nums[i] is either 0 or 1.
    // 0 <= goal <= nums.length
    struct BinarySubArraySum
    {
        // time: O(n^2), correct but TLE
        int numSubarraysWithSum_slow(std::vector<int>& nums, int goal)
        {
            int sum = 0;
            int count = 0;

            for (int i = 0; i < nums.size(); i++) {
                sum = 0;

                for (int j = i; j < nums.size(); j++) {
                    sum += nums[j];
                    if (sum == goal)
                        count++;
                }
            }
            return count;
        }

