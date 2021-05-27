#pragma once

#include <algorithm>
#include <vector>

namespace Leet::Medium {
    using std::vector;

    // Given an array nums of n integers, return an array of all the
    // unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

    // 0 <= a, b, c, d < n
    // a, b, c, and d are distinct.
    // nums[a] + nums[b] + nums[c] + nums[d] == target
    // You may return the answer in any order.

    // Example 1:
    // Input: nums = [1,0,-1,0,-2,2], target = 0
    // Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

    // Example 2:
    // Input: nums = [2,2,2,2,2], target = 8
    // Output: [[2,2,2,2]]

    // Constraints:
    // 1 <= nums.length <= 200
    // -109 <= nums[i] <= 109
    // -109 <= target <= 109
    struct FourSum
    {
        vector<vector<int>> fourSum(vector<int>& nums, int target)
        {
            vector<vector<int>> sums{};

            if (nums.size() < 3)
                return sums;

            std::sort(nums.begin(), nums.end());

            for (int i = 0; i < nums.size() - 3; i++) {
                for (int j = i + 1; j < nums.size() - 2; j++) {
                    int l = j + 1;
                    int r = nums.size() - 1;
                    int sum = 0;

                    while (l < r) {
                        sum = nums[i] + nums[j] + nums[l] + nums[r];

                        if (sum == target) {
                            auto v = std::vector<int>{nums[i], nums[j], nums[l], nums[r]};
                            if (std::find(sums.begin(), sums.end(), v) == sums.end())
                                sums.push_back(v);

                            l++;
                            r--;
                        } else if (sum < target) {
                            l++;
                        } else {
                            r--;
                        }
                    }
                }
            }

            return sums;
        }
    };
}  // namespace Leet::Medium
