#pragma once

#include <iostream>
#include <vector>

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
            std::vector<std::vector<int>> result;
            int len = nums.size();
            int l = 1;
            int r = len - 1;

            std::sort(nums.begin(), nums.end());

            for (int i = 0; i < len - 1; i++) {
                // skip duplicates from i
                if (i > 0 && nums[i] == nums[i - 1])
                    continue;

                l = i + 1;
                r = len - 1;
                while (l < r) {
                    int check = nums[i] + nums[l] + nums[r];

                    if (check == 0) {
                        result.push_back({nums[i], nums[l], nums[r]});
                        l++;
                        r--;

                        // skip duplicates for l and r
                        while (l < r && nums[l] == nums[l - 1])
                            l++;
                        while (l < r && nums[r] == nums[r + 1])
                            r--;
                    } else if (check < 0) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }

            return result;
        }
    };
}  // namespace Leet::Medium
