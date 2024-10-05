#pragma once

#include <vector>

using std::vector;

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
        void permutations(vector<int>& nums, vector<vector<int>>& perms,
                          vector<int>& curr, vector<bool>& seen)
        {
            // once we have to correct size, we can save it
            if (curr.size() == nums.size()) {
                perms.push_back(curr);
                return;
            }

            for (int i = 0; i < nums.size(); i++) {
                // as long as we havent seen this index, we can add the value located
                // there
                if (!seen[i]) {
                    curr.push_back(nums[i]);
                    seen[i] = true;

                    permutations(nums, perms, curr, seen);

                    curr.pop_back();
                    seen[i] = false;
                }
            }
        }

        vector<vector<int>> permute(vector<int>& nums)
        {
            vector<vector<int>> perms;
            vector<int> curr;
            vector<bool> seen(nums.size());

            permutations(nums, perms, curr, seen);
            return perms;
        }
    };
}  // namespace Leet::Medium
