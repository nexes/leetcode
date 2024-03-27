#pragma once

#include <vector>

namespace Leet::Medium {
    // Given an array of integers nums and an integer k, return the number of contiguous
    // subarrays where the product of all the elements in the subarray is strictly less
    // than k.

    // Example 1:
    // Input: nums = [10,5,2,6], k = 100
    // Output: 8
    // Explanation: The 8 subarrays that have product less than 100 are:
    // [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
    // Note that [10, 5, 2] is not included as the product of 100 is not strictly less
    // than k.

    // Example 2:
    // Input: nums = [1,2,3], k = 0
    // Output: 0

    // Constraints:
    // 1 <= nums.length <= 3 * 104
    // 1 <= nums[i] <= 1000
    // 0 <= k <= 106
    struct SubarrayProductLessK
    {
        // brute force O(n^2)
        int numSubarrayProductLessThanK_naive(std::vector<int> &nums, int k)
        {
            int prod;
            int count = 0;

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] >= k)
                    continue;
                count++;
                prod = nums[i];

                for (int j = i + 1; j < nums.size(); j++) {
                    prod *= nums[j];
                    if (prod >= k)
                        break;
                    count++;
                }
            }
            return count;
        }

        // sliding window O(n)
        int numSubarrayProductLessThanK(std::vector<int> &nums, int k)
        {
            int l = 0;
            int r = 0;
            int prod = 1;
            int count = 0;

            while (r < nums.size()) {
                prod *= nums[r++];

                while (l < r && prod >= k)
                    prod /= nums[l++];

                // adds the subarrays inside the sliding window
                count += r - l;
            }

            return count;
        }
    };
}  // namespace Leet::Medium