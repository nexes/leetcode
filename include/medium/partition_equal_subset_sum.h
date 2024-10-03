#pragma once

#include <vector>

using std::vector;

namespace Leet::Medium {
    typedef vector<vector<int>> Memo;

    // Given an integer array nums, return true if you can partition the array into two
    // subsets such that the sum of the elements in both subsets is equal or false
    // otherwise.

    // Example 1:
    // Input: nums = [1,5,11,5]
    // Output: true
    // Explanation: The array can be partitioned as [1, 5, 5] and [11].

    // Example 2:
    // Input: nums = [1,2,3,5]
    // Output: false
    // Explanation: The array cannot be partitioned into equal sum subsets.

    // Constraints:
    // 1 <= nums.length <= 200
    // 1 <= nums[i] <= 100
    struct PartitionEqualSubset
    {
        // --------------------- TOP DOWN : DP -----------------------
        bool partition(vector<int>& nums, Memo& memo, int idx, int sum1, int sum2)
        {
            if (sum1 == sum2)
                return true;
            if (idx < 0)
                return false;

            if (memo[idx][sum1] != -1)
                return memo[idx][sum1];

            int value = nums[idx];
            int take = partition(nums, memo, idx - 1, sum1 + value, sum2 - value);
            int notTake = partition(nums, memo, idx - 1, sum1, sum2);

            return memo[idx][sum1] = take || notTake;
        }

        bool canPartition(vector<int>& nums)
        {
            int totalSum = 0;
            for (int num : nums)
                totalSum += num;

            vector<vector<int>> memo(nums.size(), vector<int>(totalSum + 1, -1));

            return partition(nums, memo, nums.size() - 1, 0, totalSum);
        }
    };
}  // namespace Leet::Medium