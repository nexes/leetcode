#pragma once

#include <vector>

using std::vector;

namespace Leet::Medium {
    // Given an array nums of n integers, are there elements a, b, c in nums such
    // that a + b + c = 0? Find all unique triplets in the array which gives the sum of
    // zero. Note: The solution set must not contain duplicate triplets.

    // Example:
    // Given array nums = [-1, 0, 1, 2, -1, -4],
    // A solution set is:
    // [
    //   [-1, 0, 1],
    //   [-1, -1, 2]
    // ]
    struct ThreeSum
    {
        // time: O(n^2)
        // space: O(1)
        std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
        {
            vector<vector<int>> triplets;
            sort(nums.begin(), nums.end());

            for (int i = 0; i < nums.size(); i++) {
                if (i > 0 && nums[i - 1] == nums[i]) {
                    continue;
                }

                int l = i + 1;
                int r = nums.size() - 1;
                while (l < r) {
                    int sum = nums[i] + nums[l] + nums[r];
                    if (sum == 0) {
                        triplets.push_back({nums[i], nums[l], nums[r]});
                        l++;
                        r--;
                        while (l < r && nums[l - 1] == nums[l])
                            l++;
                    } else if (sum < 0) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }

            return triplets;
        }
    };
}  // namespace Leet::Medium
