#pragma once

#include <vector>
#include <iostream>

namespace Leet::Medium
{
    // Given an array nums of n integers, are there elements a, b, c in nums such
    // that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
    // Note:
    // The solution set must not contain duplicate triplets.

    // Example:
    // Given array nums = [-1, 0, 1, 2, -1, -4],
    // A solution set is:
    // [
    //   [-1, 0, 1],
    //   [-1, -1, 2]
    // ]

    // [-4, -1, -1, 0, 1, 2]
    struct ThreeSum
    {
        std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
        {
            int len = nums.size();
            std::vector<std::vector<int>> result;

            return result;
        }

        int threeSum_test(std::vector<int> &nums)
        {
            int len = nums.size();
            int l = 1;
            int r = len - 1;

            if (len < 3)
                return -1;

            std::sort(nums.begin(), nums.end());

            for (int i = 0; i < len - 1; i++)
            {
                l = i + 1;
                r = len - 1;

                while (l < r)
                {
                    if (nums[i] + nums[l] + nums[r] == 0)
                    {
                        std::cout << "found: " << nums[i] << " + " << nums[l] << " + " << nums[r] << "\n";
                        l++;
                    }
                    else
                    {
                        if (std::abs(nums[i] + nums[l]) <= std::abs(nums[i] + nums[r]))
                            r--;
                        else
                            l++;
                    }
                }
            }

            return 1;
        }
    };
} // namespace Leet::Medium
