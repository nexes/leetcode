#pragma once

#include <vector>

using std::vector;

namespace Leet::Medium {
    // Given two integer arrays nums1 and nums2, return the maximum length of a subarray
    // that appears in both arrays.

    // Example 1:
    // Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
    // Output: 3
    // Explanation: The repeated subarray with maximum length is [3,2,1].

    // Example 2:
    // Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
    // Output: 5
    // Explanation: The repeated subarray with maximum length is [0,0,0,0,0].

    // Constraints:

    // 1 <= nums1.length, nums2.length <= 1000
    // 0 <= nums1[i], nums2[i] <= 100
    struct MaxSubArray
    {
        // O(n^2)
        int findLength(std::vector<int>& nums1, std::vector<int>& nums2)
        {
            int maxlen = 0;
            vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));

            // classic DP, longest common substring (subarray)
            for (int r = 1; r <= nums1.size(); r++) {
                for (int c = 1; c <= nums2.size(); c++) {
                    if (nums1[r - 1] == nums2[c - 1])
                        dp[r][c] = dp[r - 1][c - 1] + 1;
                    else
                        dp[r][c] = 0;

                    maxlen = std::max(maxlen, dp[r][c]);
                }
            }

            return maxlen;
        }
    };
}  // namespace Leet::Medium
