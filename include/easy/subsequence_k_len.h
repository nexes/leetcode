#pragma once

#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;

namespace Leet::Easy {
    // You are given an integer array nums and an integer k. You want to find a
    // subsequence of nums of length k that has the largest sum. Return any such
    // subsequence as an integer array of length k. A subsequence is an array that can be
    // derived from another array by deleting some or no elements without changing the
    // order of the remaining elements.

    // Example 1:
    // Input: nums = [2,1,3,3], k = 2
    // Output: [3,3]
    // Explanation:
    // The subsequence has the largest sum of 3 + 3 = 6.

    // Example 2:
    // Input: nums = [-1,-2,3,4], k = 3
    // Output: [-1,3,4]
    // Explanation:
    // The subsequence has the largest sum of -1 + 3 + 4 = 6.

    // Example 3:
    // Input: nums = [3,4,3,3], k = 2
    // Output: [3,4]
    // Explanation:
    // The subsequence has the largest sum of 3 + 4 = 7.
    // Another possible subsequence is [4, 3].

    // Constraints:
    // 1 <= nums.length <= 1000
    // -105 <= nums[i] <= 105
    // 1 <= k <= nums.length
    struct SubsequenceKLength
    {
        vector<int> maxSubsequence(vector<int> &nums, int k)
        {
            vector<int> sum_arr;
            priority_queue<std::pair<int, int>> pq;

            for (int i = 0; i < nums.size(); i++)
                pq.push({nums[i], i});

            vector<std::pair<int, int>> temp;
            while (!pq.empty() && k-- > 0) {
                temp.push_back(pq.top());
                pq.pop();
            }

            std::sort(temp.begin(), temp.end(),
                      [&](const std::pair<int, int> &a, const std::pair<int, int> &b) {
                          return a.second < b.second;
                      });

            for (auto p : temp)
                sum_arr.push_back(p.first);

            return sum_arr;
        }
    };
}  // namespace Leet::Easy