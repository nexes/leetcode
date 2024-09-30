#pragma once

#include <algorithm>
#include <vector>

using std::vector;

namespace Leet::Medium {
    // Given an integer array nums, return the length of the longest strictly
    // increasing subsequence. A subsequence is a sequence that can be derived
    // from an array by deleting some or no elements without changing the order
    // of the remaining elements. For example, [3,6,2,7] is a subsequence of the array
    // [0,3,1,6,2,2,7].

    // Example 1:
    // Input: nums = [10,9,2,5,3,7,101,18]
    // Output: 4
    // Explanation: The longest increasing subsequence is [2,3,7,101], therefore the
    // length is 4.

    // Example 2:
    // Input: nums = [0,1,0,3,2,3]
    // Output: 4

    // Example 3:
    // Input: nums = [7,7,7,7,7,7,7]
    // Output: 1

    // Constraints:
    // 1 <= nums.length <= 2500
    // -104 <= nums[i] <= 104

    // Follow up:
    // Could you improve it to O(n log(n)) time complexity?
    struct IncreasingSubSeq
    {
        // DP TOP DOWN
        int findLongest_topdown(vector<int>& nums, vector<vector<int>>& memo, int idx,
                                int prevIdx)
        {
            if (idx == nums.size())
                return 0;

            if (memo[idx][prevIdx + 1] != -1)
                return memo[idx][prevIdx + 1];

            int take = INT_MIN;
            int dontTake = findLongest_topdown(nums, memo, idx + 1, prevIdx);

            if (prevIdx == -1 || nums[prevIdx] < nums[idx])
                take = findLongest_topdown(nums, memo, idx + 1, idx) + 1;

            return memo[idx][prevIdx + 1] = std::max(take, dontTake);
        }

        int lengthOfLIS_topdown(vector<int>& nums)
        {
            vector<vector<int>> memo(nums.size(), vector<int>(nums.size() + 1, -1));
            return findLongest_topdown(nums, memo, 0, -1);
        }

        // O(n*log(n))
        int lengthOfLIS_binarysearch(std::vector<int>& nums)
        {
            std::vector<int> subseq;
            subseq.push_back(nums[0]);

            // basic binary search, we're looking for the index were the 'target' value
            // should be placed in the array
            auto bsearch = [&subseq](int target) -> int {
                int l = 0;
                int r = subseq.size() - 1;

                while (l <= r) {
                    int mid = l + (r - l) / 2;

                    if (subseq[mid] == target)
                        return mid;

                    if (subseq[mid] < target)
                        l = mid + 1;
                    else
                        r = mid - 1;
                }

                return l;
            };

            // if we found a number greater than the end of our lcs that we append it
            // if not, we binary search for the index where that number should go
            // NOTE: this will not give the correct lcs, just the length of it
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] > subseq.back()) {
                    subseq.push_back(nums[i]);
                } else {
                    int idx = bsearch(nums[i]);
                    subseq[idx] = nums[i];
                }
            }

            return subseq.size();
        }

        // O(n^2)
        int lengthOfLIS(std::vector<int>& nums)
        {
            std::vector<int> dp(nums.size(), 1);
            int max_length = 1;

            // the idea is to loop from 0 to your position i and see if
            // adding the current value to the largest found so far is better
            for (int i = 1; i < nums.size(); i++) {
                for (int j = 0; j < i; j++) {
                    if (nums[i] > nums[j]) {
                        dp[i] = std::max(dp[i], dp[j] + 1);
                    }
                }

                max_length = std::max(max_length, dp[i]);
            }

            return max_length;
        }
    };
}  // namespace Leet::Medium
