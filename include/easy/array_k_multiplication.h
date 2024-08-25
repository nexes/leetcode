#pragma once

#include <queue>
#include <vector>

using std::pair;
using std::priority_queue;
using std::vector;

namespace Leet::Easy {
    // You are given an integer array nums, an integer k, and an integer multiplier.
    // You need to perform k operations on nums. In each operation:

    // Find the minimum value x in nums. If there are multiple occurrences of the minimum
    // value, select the one that appears first. Replace the selected minimum value x with
    // x * multiplier. Return an integer array denoting the final state of nums after
    // performing all k operations.

    // Example 1:
    // Input: nums = [2,1,3,5,6], k = 5, multiplier = 2
    // Output: [8,4,6,5,6]

    // Explanation:
    // Operation	Result
    // After operation 1	[2, 2, 3, 5, 6]
    // After operation 2	[4, 2, 3, 5, 6]
    // After operation 3	[4, 4, 3, 5, 6]
    // After operation 4	[4, 4, 6, 5, 6]
    // After operation 5	[8, 4, 6, 5, 6]

    // Example 2:
    // Input: nums = [1,2], k = 3, multiplier = 4
    // Output: [16,8]

    // Explanation:
    // Operation	Result
    // After operation 1	[4, 2]
    // After operation 2	[4, 8]
    // After operation 3	[16, 8]

    // Constraints:
    // 1 <= nums.length <= 100
    // 1 <= nums[i] <= 100
    // 1 <= k <= 10
    // 1 <= multiplier <= 5
    struct FinalArrayMultiply
    {
        // time: O(nlog(n) + klog(k))
        vector<int> getFinalState(vector<int>& nums, int k, int multiplier)
        {
            vector<int> mulnums(nums.size());
            priority_queue<pair<int, int>, vector<pair<int, int>>,
                           std::greater<pair<int, int>>>
                q;

            for (int i = 0; i < nums.size(); i++)
                q.push({nums[i], i});

            for (int i = 0; i < k; i++) {
                pair<int, int> value = q.top();
                q.pop();

                value.first *= multiplier;
                q.push(value);
            }

            while (!q.empty()) {
                pair<int, int> value = q.top();
                q.pop();

                mulnums[value.second] = value.first;
            }

            return mulnums;
        }
    };
}  // namespace Leet::Easy