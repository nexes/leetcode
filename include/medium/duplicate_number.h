#pragma once

#include <algorithm>
#include <vector>

namespace Leet::Medium {
    // Given an array nums containing n + 1 integers where each integer is
    // between 1 and n (inclusive), prove that at least one duplicate number
    // must exist. Assume that there is only one duplicate number, find the
    // duplicate one.

    // Example 1:
    // Input: [1,3,4,2,2]
    // Output: 2

    // Example 2:
    // Input: [3,1,3,4,2]
    // Output: 3

    // Note:
    // You must not modify the array (assume the array is read only).
    // You must use only constant, O(1) extra space.
    // Your runtime complexity should be less than O(n2).
    // There is only one duplicate number in the array, but it could be repeated
    // more than once.
    struct DuplicateNumber
    {
        // time: O(nlog(n)). this sorts the array which violates the rule of not
        // changing the array but it's the easiest to understand
        int findDuplicate_sort(std::vector<int>& nums)
        {
            std::sort(nums.begin(), nums.end());

            for (int i = 1; i < nums.size(); i++)
                if (nums[i - 1] == nums[i])
                    return nums[i];
            return -1;
        }

        // time: O(n) swap one element with the element at index 0 until we have
        // found the duplicate. This works because we will eventually will have
        // the dupicate at index 0 and the other at index 'duplicate'
        int findDuplicate_swap(std::vector<int>& nums)
        {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[0] != nums[nums[0]])
                    std::swap(nums[0], nums[nums[0]]);
                else
                    return nums[0];
            }

            return -1;
        }

        // time: O(n) we have a fast and slow pointer. We loop through the array
        // until the fast and slow pointer equal the same position. than we
        // restart the loop at the same speed until they meet and this is the
        // duplicate
        // https://en.wikipedia.org/wiki/Cycle_detection
        int findDuplicate_fast_pointer(std::vector<int>& nums)
        {
            int slow = nums[nums[0]];
            int fast = nums[slow];

            while (slow != fast) {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }

            slow = nums[0];
            while (slow != fast) {
                slow = nums[slow];
                fast = nums[fast];
            }

            return slow;
        }
    };
}  // namespace Leet::Medium
