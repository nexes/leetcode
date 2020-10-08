#pragma once

#include <unordered_set>
#include <vector>

namespace Leet::Easy {
    // Given two arrays, write a function to compute their intersection.

    // Example 1:
    // Input: nums1 = [1,2,2,1], nums2 = [2,2]
    // Output: [2]

    // Example 2:
    // Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    // Output: [9,4]

    // Note:
    // Each element in the result must be unique.
    // The result can be in any order.
    struct IntersectArray
    {
        std::vector<int> intersection(std::vector<int> nums1, std::vector<int> nums2)
        {
            std::unordered_set<int> p(nums1.begin(), nums1.end());
            std::unordered_set<int> q(nums2.begin(), nums2.end());
            std::vector<int> out;

            // O(n)
            for (auto &i : q)
            {
                // O(1)
                if (p.find(i) != p.end())
                    out.emplace_back(i);
            }

            return out;
        }
    };
}  // namespace Leet::Easy
