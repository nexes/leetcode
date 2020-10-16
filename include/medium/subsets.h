#pragma once

#include <vector>

namespace Leet::Medium {
    // Given a set of distinct integers, nums, return all possible subsets (the power set).
    // Note: The solution set must not contain duplicate subsets.

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
        std::vector<std::vector<int>> subsets(std::vector<int> &nums)
        {
            // space: 2^n subsets, where n = nums.length
            std::vector<std::vector<int>> out{};
            std::vector<int> temp{};

            backtrack(out, temp, nums, 0);

            return out;
        }

        // not the prettiest function signature but it's simple
        void backtrack(std::vector<std::vector<int>> &out, std::vector<int> &temp, std::vector<int> &nums, int idx)
        {
            if (idx == nums.size())
            {
                out.push_back(temp);
                return;
            }

            temp.push_back(nums[idx]);

            backtrack(out, temp, nums, idx + 1);
            temp.pop_back();
            backtrack(out, temp, nums, idx + 1);
        }
    };
}  // namespace Leet::Medium
