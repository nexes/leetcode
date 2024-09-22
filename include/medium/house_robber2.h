#pragma once

#include <vector>

using std::vector;

namespace Leet::Medium {
    // You are a professional robber planning to rob houses along a street. Each house has
    // a certain amount of money stashed. All houses at this place are arranged in a
    // circle. That means the first house is the neighbor of the last one. Meanwhile,
    // adjacent houses have a security system connected, and it will automatically contact
    // the police if two adjacent houses were broken into on the same night.

    // Given an integer array nums representing the amount of money of each house, return
    // the maximum amount of money you can rob tonight without alerting the police.

    // Example 1:
    // Input: nums = [2,3,2]
    // Output: 3
    // Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
    // because they are adjacent houses.

    // Example 2:
    // Input: nums = [1,2,3,1]
    // Output: 4
    // Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
    // Total amount you can rob = 1 + 3 = 4.

    // Example 3:
    // Input: nums = [1,2,3]
    // Output: 3

    // Constraints:
    // 1 <= nums.length <= 100
    // 0 <= nums[i] <= 1000
    struct HouseRobber2
    {
        // TOP DOWN
        int robHouse_topdown(vector<int> &nums, vector<int> &robbed, int start, int end)
        {
            if (start < end)
                return 0;
            if (robbed[start] != -1)
                return robbed[start];

            robbed[start] =
                std::max(robHouse_topdown(nums, robbed, start - 1, end),
                         robHouse_topdown(nums, robbed, start - 2, end) + nums[start]);

            return robbed[start];
        }

        int rob_topdown(vector<int> &nums)
        {
            if (nums.size() == 1)
                return nums[0];

            // we are going to use two 'caches' since we have to solve the problem 'twice'
            vector<int> robbed(nums.size(), -1);
            vector<int> robbed1(nums.size(), -1);

            return std::max(robHouse_topdown(nums, robbed, nums.size() - 2, 0),
                            robHouse_topdown(nums, robbed1, nums.size() - 1, 1));
        }
        // TOP DOWN

        // BOTTOM UP
        int robHouse(vector<int> &nums)
        {
            vector<int> robbed(nums.size());
            robbed[0] = nums[0];
            robbed[1] = std::max(nums[0], nums[1]);

            for (int i = 2; i < nums.size(); i++)
                robbed[i] = std::max(robbed[i - 1], robbed[i - 2] + nums[i]);

            return robbed[nums.size() - 1];
        }

        int rob(vector<int> &nums)
        {
            int len = nums.size();
            if (len < 3)
                return len == 1 ? nums[0] : std::max(nums[0], nums[1]);

            // we are going to use two 'caches' since we have to solve the problem 'twice'
            vector<int> set1(nums.begin(), nums.end() - 1);
            vector<int> set2(nums.begin() + 1, nums.end());

            int rob1 = robHouse(set1);
            int rob2 = robHouse(set2);

            return std::max(rob1, rob2);
        }
        // BOTTOM UP
    };
}  // namespace Leet::Medium