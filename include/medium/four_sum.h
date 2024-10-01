#pragma once

#include <vector>

using std::vector;

namespace Leet::Medium {
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
            vector<vector<int>> sums;

            sort(nums.begin(), nums.end());

            // avoid duplicates
            for (int i = 0; i < nums.size(); i++) {
                if (i > 0 && nums[i - 1] == nums[i])
                    continue;

                for (int j = i + 1; j < nums.size(); j++) {
                    if (j > i + 1 && nums[j - 1] == nums[j])
                        continue;

                    int l = j + 1;
                    int r = nums.size() - 1;
                    long long need = target - (long long)nums[i] - (long long)nums[j];

                    while (l < r) {
                        if (nums[l] + nums[r] == need) {
                            sums.push_back({nums[i], nums[j], nums[l], nums[r]});
                            l++;
                            r--;

                            while (l < r && nums[l] == nums[l - 1] &&
                                   nums[r] == nums[r + 1]) {
                                l++;
                                r--;
                            }
                        } else if (nums[l] + nums[r] > need) {
                            r--;
                            while (l < r && nums[r] == nums[r + 1])
                                r--;
                        } else {
                            l++;
                            while (l < r && nums[l] == nums[l - 1])
                                l++;
                        }
                    }
                }
            }

            return sums;
        }
    };
}  // namespace Leet::Medium
