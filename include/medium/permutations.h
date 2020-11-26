#pragma once

#include <vector>

namespace Leet::Medium {
    // Given a collection of distinct integers, return all possible permutations.

    // Example:
    // Input: [1,2,3]
    // Output:
    // [
    //   [1,2,3],
    //   [1,3,2],
    //   [2,1,3],
    //   [2,3,1],
    //   [3,1,2],
    //   [3,2,1]
    // ]
    struct Permutation
    {
        std::vector<std::vector<int>> permute(std::vector<int> &nums)
        {
            std::vector<std::vector<int>> output{};
            helper(nums, output, 0);

            return output;
        }

        void helper(std::vector<int> &nums, std::vector<std::vector<int>> &out, int start)
        {
            int len = nums.size();

            if (start == len - 1) {
                out.push_back(nums);
                return;
            }

            for (int i = start; i < len; i++) {
                std::swap(nums[i], nums[start]);
                helper(nums, out, start + 1);
                std::swap(nums[i], nums[start]);
            }
        }
    };
} // namespace Leet::Medium
