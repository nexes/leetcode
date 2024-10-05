#pragma once

#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

namespace Leet::Medium {
    // Given a collection of numbers, nums, that might contain duplicates, return all
    // possible unique permutations in any order.

    // Example 1:
    // Input: nums = [1,1,2]
    // Output:
    // [[1,1,2],
    //  [1,2,1],
    //  [2,1,1]]

    // Example 2:
    // Input: nums = [1,2,3]
    // Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

    // Constraints:
    // 1 <= nums.length <= 8
    // -10 <= nums[i] <= 10
    struct Permution2
    {
        void permutations(unordered_map<int, int>& numMap, vector<vector<int>>& perms,
                          vector<int>& curr, int len)
        {
            if (curr.size() == len) {
                perms.push_back(curr);
                return;
            }

            for (auto& [value, count] : numMap) {
                // if we have a value available, we can take it, otherwise move on
                if (count > 0) {
                    count--;
                    curr.push_back(value);
                    permutations(numMap, perms, curr, len);

                    curr.pop_back();
                    count++;
                }
            }
        }

        vector<vector<int>> permuteUnique(vector<int>& nums)
        {
            vector<int> current;
            vector<vector<int>> perms;
            unordered_map<int, int> freqNums;

            // if we don't want to use a hash map we can sort nums, but this is easier to
            // understand.
            for (int num : nums)
                freqNums[num]++;

            permutations(freqNums, perms, current, nums.size());
            return perms;
        }
    };
}  // namespace Leet::Medium