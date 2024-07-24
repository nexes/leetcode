#pragma once

#include <algorithm>
#include <unordered_map>
#include <vector>

namespace Leet::Easy {
    // Given an array of integers nums, sort the array in increasing order based on the
    // frequency of the values. If multiple values have the same frequency, sort them in
    // decreasing order. Return the sorted array.

    // Example 1:
    // Input: nums = [1,1,2,2,2,3]
    // Output: [3,1,1,2,2,2]
    // Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a
    // frequency of 3.

    // Example 2:
    // Input: nums = [2,3,1,3,2]
    // Output: [1,3,3,2,2]
    // Explanation: '2' and '3' both have a frequency of 2, so they are sorted in
    // decreasing order.

    // Example 3:
    // Input: nums = [-1,1,-6,4,5,-6,1,4,1]
    // Output: [5,-1,4,4,-6,-6,1,1,1]

    // Constraints:
    // 1 <= nums.length <= 100
    // -100 <= nums[i] <= 100
    struct SortByFrequency
    {
        // time: O(nlog(n))
        std::vector<int> frequencySort(std::vector<int> &nums)
        {
            std::vector<int> sorted;
            std::vector<std::pair<int, int>> sorted_freq;
            std::unordered_map<int, int> freq;

            // O(n)
            for (int num : nums)
                freq[num]++;

            // O(n)
            for (auto value : freq)
                sorted_freq.push_back(value);

            // O(nlogn)
            std::sort(sorted_freq.begin(), sorted_freq.end(),
                      [&](const std::pair<int, int> &a, const std::pair<int, int> &b) {
                          if (a.second == b.second)
                              return a.first > b.first;
                          return a.second < b.second;
                      });

            // O(n)
            for (auto p : sorted_freq)
                for (int i = 0; i < p.second; i++)
                    sorted.push_back(p.first);

            return sorted;
        }
    };
}  // namespace Leet::Easy