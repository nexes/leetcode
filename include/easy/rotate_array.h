#pragma once

#include <vector>

namespace Leet::Easy
{
    // Given an array, rotate the array to the right by k steps, where k is non-negative.

    // Follow up:
    // Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
    // Could you do it in-place with O(1) extra space?

    // Example 1:
    // Input: nums = [1,2,3,4,5,6,7], k = 3
    // Output: [5,6,7,1,2,3,4]

    // Explanation:
    // rotate 1 steps to the right: [7,1,2,3,4,5,6]
    // rotate 2 steps to the right: [6,7,1,2,3,4,5]
    // rotate 3 steps to the right: [5,6,7,1,2,3,4]

    // Example 2:
    // Input: nums = [-1,-100,3,99], k = 2
    // Output: [3,99,-1,-100]

    // Explanation:
    // rotate 1 steps to the right: [99,-1,-100,3]
    // rotate 2 steps to the right: [3,99,-1,-100]
    struct RotateArray
    {
        void reverse(std::vector<int> &nums, int start, int end)
        {
            while (start < end)
                std::swap(nums[start++], nums[end--]);
        }

        // runtime O(n) space O(1)
        void rotate(std::vector<int> &nums, int k)
        {
            int len = nums.size();
            k = k % len;

            reverse(nums, 0, len - 1);
            reverse(nums, 0, k - 1);
            reverse(nums, k, len - 1);
        }

        // runtime O(n) space O(n)
        void rotate_2(std::vector<int> &nums, int k)
        {
            int len = nums.size();
            k = k % len;

            std::vector<int> temp(nums);

            for (int i = 0; i < len; i++)
            {
                nums[(i + k) % len] = temp[i];
            }
        }
    };
} // namespace Leet::Easy
