#pragma once

#include <vector>

using std::vector;

namespace Leet::Medium {
    // Given a set of distinct integers, nums, return all possible subsets (the power
    // set). Note: The solution set must not contain duplicate subsets.

    // Example:
    // Input: nums = [1,2,3]
    // Output:
    // [
    //   [3],
    //   [1],
    //   [2],
    //   [1,2,3],
    //   [1,3],
    //   [2,3],
    //   [1,2],
    //   []
    // ]
    struct SubSets
    {
        void getSets(vector<int>& nums, vector<vector<int>>& allSets, vector<int>& curr,
                     int idx)
        {
            // we can add all subsets as they come in, the for loop will act as a 'base
            // case' for the recursion
            allSets.push_back(curr);

            for (int i = idx; i < nums.size(); i++) {
                curr.push_back(nums[i]);
                getSets(nums, allSets, curr, i + 1);
                curr.pop_back();
            }
        }

        std::vector<std::vector<int>> subsets(std::vector<int>& nums)
        {
            std::vector<std::vector<int>> out{};
            std::vector<int> temp{};

            getSets(nums, out, temp, 0);

            return out;
        }
    };
}  // namespace Leet::Medium
