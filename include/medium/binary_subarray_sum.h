#pragma once

#include <unordered_map>
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
        // naive O(n^2): passes but will exceed the time limit
        int numSubarraysWithSum_slow(std::vector<int> &nums, int goal)
        {
            int sum = 0;
            int count = 0;
            int len = nums.size();

            for (int i = 0; i < len; i++) {
                sum = 0;

                for (int j = i; j < len; j++) {
                    sum += nums[j];
                    if (sum == goal)
                        count++;
                }
            }
            return count;
        }

        int numSubarraysWithSum(std::vector<int> &nums, int goal)
        {
            int count = 0;
            int sum = 0;
            std::unordered_map<int, int> map{};

            map[0] = 1;
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];
                count += map[sum - goal];
                map[sum]++;
            }

            return count;
        }
    };
}  // namespace Leet::Medium