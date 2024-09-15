#pragma once

#include <unordered_map>
#include <vector>

namespace Leet::Medium {
    // Given an array of integers nums and an integer k, return the total number of
    // continuous subarrays whose sum equals to k. Given an array of integers nums and an
    // integer k, return the total number of continuous subarrays whose sum equals to k.

    // Example 1:
    // Input: nums = [1,1,1], k = 2
    // Output: 2

    // Example 2:
    // Input: nums = [1,2,3], k = 3
    // Output: 2

    // Constraints:
    // 1 <= nums.length <= 2 * 104
    // -1000 <= nums[i] <= 1000
    // -107 <= k <= 107
    struct SubarraySum
    {
        // bruteforce, time: O(n^2), space: O(1)
        int subarraySum_bruteforce(std::vector<int>& nums, int k)
        {
            int count = 0;

            for (int i = 0; i < nums.size(); i++) {
                int temp_sum = nums[i];

                if (nums[i] == k) {
                    count++;
                }

                for (int j = i + 1; j < nums.size(); j++) {
                    temp_sum += nums[j];

                    if (temp_sum == k) {
                        count++;
                    }
                }
            }

            return count;
        }

        // time: O(n), space: O(n)
        int subarraySum(std::vector<int>& nums, int k)
        {
            std::unordered_map<int, int> sums;
            int count = 0;
            int sum = 0;

            sums[0] = 1;

            // simular to a prefix sum array, but we use a hashmap so we
            // don't have to worry out indexing out of bounds. If we
            // take the total sum so far and remove the value k from it, if
            // we've seen that value before, we have another subarry == to k.
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];
                count += sums[sum - k];
                sums[sum]++;
            }

            return count;
        }
    };
}  // namespace Leet::Medium
