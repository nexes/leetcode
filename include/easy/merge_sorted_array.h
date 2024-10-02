#pragma once

#include <../treenode.h>

#include <vector>

namespace Leet::Easy {
    // Given two sorted integer arrays nums1 and nums2, merge nums2
    // into nums1 as one sorted array.

    // Note:
    // The number of elements initialized in nums1 and nums2 are m and n respectively.
    // You may assume that nums1 has enough space (size that is equal to m + n) to hold
    // additional elements from nums2.

    // Example:
    // Input:
    // nums1 = [1,2,3,0,0,0], m = 3
    // nums2 = [2,5,6],       n = 3
    // Output: [1,2,2,3,5,6]

    // Constraints:
    // -10^9 <= nums1[i], nums2[i] <= 10^9
    // nums1.length == m + n
    // nums2.length == n
    struct MergeSorted
    {
        void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
        {
            if (nums1.empty() || nums2.empty())
                return;

            int num1_idx = 0;

            // O(m)
            for (; num1_idx < m; num1_idx++) {
                if (nums2[0] < nums1[num1_idx]) {
                    int temp = nums1[num1_idx];

                    nums1[num1_idx] = nums2[0];
                    nums2[0] = temp;

                    // O(n)
                    for (int i = 0; i < n - 1; i++) {
                        if (nums2[i + 1] < nums2[i]) {
                            temp = nums2[i];
                            nums2[i] = nums2[i + 1];
                            nums2[i + 1] = temp;
                        }
                    }
                }
            }

            // O(n)
            for (int i = 0; i < n; i++)
                nums1[num1_idx++] = nums2[i];
        }

        // a better approach to the problem. look at the last element in the two arrays
        // that are not zero and place the larger of the two at the end of nums1.
        void merge_better(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
        {
            int i = m - 1;
            int j = n - 1;
            int idx = nums1.size() - 1;

            while (i >= 0 && j >= 0) {
                if (nums2[j] >= nums1[i])
                    nums1[idx--] = nums2[j--];
                else
                    nums1[idx--] = nums1[i--];
            }

            while (j >= 0)
                nums1[idx--] = nums2[j--];
        }
    };
}  // namespace Leet::Easy
