#pragma once

#include <algorithm>
#include <queue>
#include <vector>

namespace Leet::Medium {
    // Find the kth largest element in an unsorted array. Note that it is the
    // kth largest element in the sorted order, not the kth distinct element.

    // Example 1:
    // Input: [3,2,1,5,6,4] and k = 2
    // Output: 5

    // Example 2:
    // Input: [3,2,3,1,2,4,5,5,6] and k = 4
    // Output: 4

    // Note:
    // You may assume k is always valid, 1 ≤ k ≤ array's length.
    struct KthLargest
    {
        // cheating???
        int findKthLargest(std::vector<int> &nums, int k)
        {
            std::sort(nums.begin(), nums.end());

            return nums[nums.size() - k];
        }

        // using a priority queue and keeping the smallest number on top
        int findKthLargest_queue(std::vector<int> &nums, int k)
        {
            std::priority_queue<int, std::vector<int>, std::greater<int>> qq;

            for (auto i : nums) {
                qq.emplace(i);
                if (qq.size() > k) qq.pop();
            }

            return qq.top();
        }
    };
}  // namespace Leet::Medium
