#pragma once

#include <unordered_set>
#include <vector>

namespace Leet::Easy {
    // Given two integer arrays nums1 and nums2, return an array of their
    // intersection
    // . Each element in the result must be unique and you may return the result in any
    // order.

    // Example 1:
    // Input: nums1 = [1,2,2,1], nums2 = [2,2]
    // Output: [2]

    // Example 2:
    // Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    // Output: [9,4]
    // Explanation: [4,9] is also accepted.

    // Constraints:
    // 1 <= nums1.length, nums2.length <= 1000
    // 0 <= nums1[i], nums2[i] <= 1000
    struct IntersectArray
    {
        // time: O(n + m)
        // space: O(n)
        std::vector<int> intersection(std::vector<int> nums1, std::vector<int> nums2)
        {
            std::unordered_set<int> numset;
            std::vector<int> result;

            for (int num : nums1)
                numset.insert(num);

            for (int i = 0; i < nums2.size(); i++) {
                if (numset.count(nums2[i]) == 1) {
                    result.push_back(nums2[i]);
                    numset.erase(nums2[i]);
                }
            }

            return result;
        }
    };
}  // namespace Leet::Easy
