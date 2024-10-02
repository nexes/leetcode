#pragma once

#include <vector>

using std::vector;

namespace Leet::Medium {
    // You are given a list of non-negative integers, a1, a2, ..., an, and a target, S.
    // Now you have 2 symbols + and -. For each integer, you should choose one from
    // + and - as its new symbol. Find out how many ways to assign symbols to make sum
    // of integers equal to target S.

    // Example 1:
    // Input: nums is [1, 1, 1, 1, 1], S is 3.
    // Output: 5

    // Explanation:
    // -1+1+1+1+1 = 3
    // +1-1+1+1+1 = 3
    // +1+1-1+1+1 = 3
    // +1+1+1-1+1 = 3
    // +1+1+1+1-1 = 3

    // There are 5 ways to assign symbols to make the sum of nums be target 3.

    // Constraints:
    // The length of the given array is positive and will not exceed 20.
    // The sum of elements in the given array will not exceed 1000.
    // Your output answer is guaranteed to be fitted in a 32-bit integer.

    struct TargetSum
    {
        // ------------------------ TOP DOWN DP ----------------------
        int findTarget_topdown(vector<int>& nums, vector<vector<int>>& memo, int total,
                               int target, int current, int idx)
        {
            if (idx == nums.size() && current == target)
                return 1;
            if (idx == nums.size())
                return 0;

            if (memo[idx][current + total] != -1)
                return memo[idx][current + total];

            int add = findTarget_topdown(nums, memo, total, target, current + nums[idx],
                                         idx + 1);
            int sub = findTarget_topdown(nums, memo, total, target, current - nums[idx],
                                         idx + 1);

            return memo[idx][current + total] = add + sub;
        }

        int findTargetSumWays_topdown(vector<int>& nums, int target)
        {
            int totalSum = 0;
            for (int num : nums)
                totalSum += num;

            vector<vector<int>> memo(nums.size(), vector<int>(totalSum * 2 + 1, -1));
            return findTarget_topdown(nums, memo, totalSum, target, 0, 0);
        }

        // brute force DFS
        int findTargetSumWays(std::vector<int>& nums, int s)
        {
            int count = 0;
            findSum(nums, 0, 0, s, count);

            return count;
        }

        // O(n^2)
        void findSum(std::vector<int>& nums, int index, int sum, int target, int& count)
        {
            if (index == nums.size()) {
                if (sum == target)
                    count++;
                return;
            }

            findSum(nums, index + 1, sum + nums[index], target, count);
            findSum(nums, index + 1, sum - nums[index], target, count);
        }
    };
}  // namespace Leet::Medium
