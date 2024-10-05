#pragma once

#include <vector>

using std::vector;

namespace Leet::Medium {
    // Given an integer array nums that may contain duplicates, return all possible
    // subsets (the power set).

    // The solution set must not contain duplicate subsets. Return the solution in any
    // order.

    // Example 1:
    // Input: nums = [1,2,2]
    // Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

    // Example 2:
    // Input: nums = [0]
    // Output: [[],[0]]

    // Constraints:
    // 1 <= nums.length <= 10
    // -10 <= nums[i] <= 10
    struct SubSets2
    {
        void findSubset(vector<int>& nums, vector<vector<int>>& allsets,
                        vector<int>& curr, int idx)
        {
            allsets.push_back(curr);

            for (int i = idx; i < nums.size(); i++) {
                // because we sorted, we can make sure this value doesn't equal the last.
                if (i == idx || nums[i] != nums[i - 1]) {
                    curr.push_back(nums[i]);
                    findSubset(nums, allsets, curr, i + 1);
                    curr.pop_back();
                }
            }
        }

        vector<vector<int>> subsetsWithDup(vector<int>& nums)
        {
            vector<vector<int>> powerSet;
            vector<int> temp;

            // because we need to worry about duplicate subsets we can sort it makeing our
            // check easier
            sort(nums.begin(), nums.end());
            findSubset(nums, powerSet, temp, 0);

            return powerSet;
        }
    };
}  // namespace Leet::Medium