#pragma once

#include <iostream>
#include <vector>

namespace Leet::Medium {
    // Given an array of integers nums, sort the array in ascending order.

    // Example 1:
    // Input: nums = [5,2,3,1]
    // Output: [1,2,3,5]

    // Example 2:
    // Input: nums = [5,1,1,2,0,0]
    // Output: [0,0,1,1,2,5]

    // Constraints:
    // 1 <= nums.length <= 50000
    // -50000 <= nums[i] <= 50000
    struct SortArray
    {
        std::vector<int> sortArray(std::vector<int>& nums)
        {
            merge_sort(nums, 0, nums.size() - 1);
            return nums;
        }

        void merge_sort(std::vector<int>& nums, int start, int end)
        {
            if (start >= end)
                return;

            int mid = start + (end - start) / 2;

            merge_sort(nums, start, mid);
            merge_sort(nums, mid + 1, end);
            merge(nums, start, mid, end);
        }

        void merge(std::vector<int>& nums, int start, int mid, int end)
        {
            std::vector<int> left;
            std::vector<int> right;

            for (int i = start; i <= mid; i++)
                left.push_back(nums[i]);
            for (int i = mid + 1; i <= end; i++)
                right.push_back(nums[i]);

            int li = 0;
            int ri = 0;
            int idx = start;

            while (li < left.size() || ri < right.size()) {
                int lval = li < left.size() ? left[li] : INT_MAX;
                int rval = ri < right.size() ? right[ri] : INT_MAX;

                if (lval <= rval)
                    nums[idx++] = left[li++];
                else
                    nums[idx++] = right[ri++];
            }
        }
    };
}  // namespace Leet::Medium
