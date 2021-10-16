#pragma once

#include <vector>

namespace Leet::Medium {
    // Suppose an array sorted in ascending order is rotated at some pivot unknown to you
    // beforehand. (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

    // You are given a target value to search. If found in the array return its index,
    // otherwise return -1. You may assume no duplicate exists in the array. Your
    // algorithm's runtime complexity must be in the order of O(log n).

    // Example 1:
    // Input: nums = [4,5,6,7,0,1,2], target = 0
    // Output: 4

    // Example 2:
    // Input: nums = [4,5,6,7,0,1,2], target = 3
    // Output: -1
    struct RotatedArray
    {
        int search(std::vector<int> &nums, int target)
        {
            int len = nums.size();
            int l = 0;
            int r = len - 1;
            int mid = (r + l) / 2;

            while (l <= r) {
                mid = (r + l) / 2;

                if (nums[mid] == target)
                    return mid;

                // a sorted rotated array, when taken the mid point will have either the
                // right or the left side sorted. Both if the pivot happens to be the mid
                // point. start with the sorted side, that way we can see if our target is
                // on the right or the left
                if (nums[mid] >= nums[l]) {
                    if (target > nums[mid] || target < nums[l])
                        l = mid + 1;
                    else
                        r = mid - 1;
                } else {
                    if (target < nums[mid] || target > nums[r])
                        r = mid - 1;
                    else
                        l = mid + 1;
                }
            }

            return -1;
        }
    };
}  // namespace Leet::Medium
