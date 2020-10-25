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

            int mid = (start + end) / 2;

            merge_sort(nums, start, mid);
            merge_sort(nums, mid + 1, end);
            merge(nums, start, mid, end);
        }

        void merge(std::vector<int>& nums, int start, int mid, int end)
        {
            int l = start;
            int r = mid + 1;
            int k = 0;

            auto temp = std::vector<int>(end - start + 1);

            for (int i = start; i <= end; i++) {
                if (l > mid)
                    temp[k++] = nums[r++];

                else if (r > end)
                    temp[k++] = nums[l++];

                else if (nums[l] < nums[r])
                    temp[k++] = nums[l++];

                else
                    temp[k++] = nums[r++];
            }

            for (int i = 0; i < k; i++)
                nums[start++] = temp[i];
        }

        std::vector<int> sortArray_cheating(std::vector<int>& nums)
        {
            std::sort(nums.begin(), nums.end());
            return nums;
        }
    };
}  // namespace Leet::Medium
