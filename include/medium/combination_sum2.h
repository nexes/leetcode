#pragma once

#include <vector>

using std::vector;

namespace Leet::Medium {
    // Given a collection of candidate numbers (candidates) and a target number (target),
    // find all unique combinations in candidates where the candidate numbers sum to
    // target. Each number in candidates may only be used once in the combination.

    // Note: The solution set must not contain duplicate combinations.

    // Example 1:
    // Input: candidates = [10,1,2,7,6,1,5], target = 8
    // Output:
    // [
    // [1,1,6],
    // [1,2,5],
    // [1,7],
    // [2,6]
    // ]

    // Example 2:
    // Input: candidates = [2,5,2,1,2], target = 5
    // Output:
    // [
    // [1,2,2],
    // [5]
    // ]

    // Constraints:
    // 1 <= candidates.length <= 100
    // 1 <= candidates[i] <= 50
    // 1 <= target <= 30
    struct CombinationSum2
    {
        void findSum(vector<int>& nums, vector<vector<int>>& sums, vector<int>& curr,
                     int idx, int target)
        {
            if (target == 0) {
                sums.push_back(curr);
                return;
            }

            for (int i = idx; i < nums.size(); i++) {
                if (i == idx || (i > 0 && nums[i] != nums[i - 1])) {
                    if (target - nums[i] >= 0) {
                        curr.push_back(nums[i]);
                        findSum(nums, sums, curr, i + 1, target - nums[i]);
                        curr.pop_back();
                    }
                }
            }
        }

        vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
        {
            vector<vector<int>> sums;
            vector<int> curr;
            vector<bool> seen(candidates.size());

            sort(candidates.begin(), candidates.end());

            findSum(candidates, sums, curr, 0, target);
            return sums;
        }
    };
}  // namespace Leet::Medium