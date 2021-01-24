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
            int count = 0;
            int sum = 0;
            std::unordered_map<int, int> sums(nums.size());

            sums.emplace(0, 1);

            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];

                if (auto it = sums.find(sum - k); it != sums.end()) {
                    count += it->second;
                }

                if (auto it = sums.emplace(sum, 1); !it.second) {
                    sums[sum]++;
                }
            }

            return count;
        }
    };
}  // namespace Leet::Medium
