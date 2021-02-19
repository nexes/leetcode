#pragma once

#include <vector>

namespace Leet::Easy {
    // Given an array nums, write a function to move all 0's to the end of it while
    // maintaining the relative order of the non-zero elements. Given an array nums, write
    // a function to move all 0's to the end of it while maintaining the relative order of
    // the non-zero elements.

    // Example:
    // Input: [0,1,0,3,12]
    // Output: [1,3,12,0,0]

    // Note:
    // You must do this in-place without making a copy of the array.
    // Minimize the total number of operations.
    struct MoveZeroes
    {
        void moveZeroes(std::vector<int>& nums)
        {
            int insert_idx = 0;

            // move the non zeroes to the left
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] != 0)
                    nums[insert_idx++] = nums[i];
            }

            // zero out the rest of the array
            for (int i = insert_idx; i < nums.size(); i++) {
                nums[i] = 0;
            }
        }
    };
}  // namespace Leet::Easy
