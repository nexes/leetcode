#pragma once

#include <map>
#include <queue>
#include <vector>

namespace Leet::Medium {
    // Given a non-empty array of integers, return the k most frequent elements.

    // Example 1:
    // Input: nums = [1,1,1,2,2,3], k = 2
    // Output: [1,2]

    // Example 2:
    // Input: nums = [1], k = 1
    // Output: [1]

    // Note:
    // You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    // Your algorithm's time complexity must be better than O(n log n), where
    // n is the array's size. It's guaranteed that the answer is unique, in
    // other words the set of the top k frequent elements is unique. You can
    // return the answer in any order.
    struct KFreqElements
    {
        std::vector<int> topKFrequent(std::vector<int>& nums, int k)
        {
            auto largest = std::vector<int>{};
            auto freq_map = std::unordered_map<int, int>{};
            auto heap = std::priority_queue<std::pair<int, int>>{};

            for (const auto& val : nums) {
                if (auto it = freq_map.emplace(val, 1); !it.second) {
                    freq_map[val]++;
                }
            }

            for (const auto& [key, val] : freq_map) {
                auto pair = std::pair{val, key};
                heap.emplace(pair);
            }

            for (int i = 0; i < k; i++) {
                auto top = heap.top();

                largest.emplace_back(top.second);
                heap.pop();
            }

            return largest;
        }
    };
}  // namespace Leet::Medium
