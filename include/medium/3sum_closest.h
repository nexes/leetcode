#pragma once

#include <algorithm>
#include <cmath>
#include <vector>

namespace Leet::Medium {
    // Given an integer array nums of length n and an integer target, find three
    // integers in nums such that the sum is closest to target. Return the sum
    // of the three integers. You may assume that each input would have exactly
    // one solution.

    // Example 1:
    // Input: nums = [-1,2,1,-4], target = 1
    // Output: 2
    // Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 =
    // 2).

    // Example 2:
    // Input: nums = [0,0,0], target = 1
    // Output: 0
    // Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

    // Constraints:
    // 3 <= nums.length <= 500
    // -1000 <= nums[i] <= 1000
    // -104 <= target <= 104
    struct ThreeSumClosest
    {
        // O(n^2)
        int threeSumClosest(std::vector<int> &nums, int target)
        {
            // O(nlog(n))
            std::sort(nums.begin(), nums.end());

            int l;
            int r;
            int distance = nums[0] + nums[1] + nums[2];

            // O(n^2)
            for (int i = 0; i <= nums.size() - 3; i++) {
                l = i + 1;
                r = nums.size() - 1;

                while (l < r) {
                    int dist = nums[i] + nums[l] + nums[r];
                    if (std::abs(dist - target) < std::abs(distance - target)) {
                        distance = dist;
                    }

                    if (dist <= target)
                        l++;
                    if (dist > target)
                        r--;
                }
            }

            return distance;
        }
    };
}  // namespace Leet::Medium