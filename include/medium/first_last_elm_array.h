#pragma once

#include <vector>

namespace Leet::Medium {
    // Given an array of integers nums sorted in non-decreasing order, find the starting
    // and ending position of a given target value.

    // If target is not found in the array, return [-1, -1].
    // You must write an algorithm with O(log n) runtime complexity.

    // Example 1:
    // Input: nums = [5,7,7,8,8,10], target = 8
    // Output: [3,4]

    // Example 2:
    // Input: nums = [5,7,7,8,8,10], target = 6
    // Output: [-1,-1]

    // Example 3:
    // Input: nums = [], target = 0
    // Output: [-1,-1]

    // Constraints:
    // 0 <= nums.length <= 105
    // -109 <= nums[i] <= 109
    // nums is a non-decreasing array.
    // -109 <= target <= 109
    struct FirstLastElem
    {
        int binarySearch(std::vector<int> &nums, int target, bool left)
        {
            int value;
            int low = 0;
            int high = nums.size() - 1;

            if (left) {
                while (low <= high) {
                    int mid = low + (high - low) / 2;

                    if (nums[mid] < target)
                        low = mid + 1;
                    else
                        high = mid - 1;
                }

                value = low;
            }

            if (!left) {
                while (low <= high) {
                    int mid = low + (high - low) / 2;

                    if (nums[mid] > target)
                        high = mid - 1;
                    else
                        low = mid + 1;
                }

                value = high;
            }

            return value;
        }

        std::vector<int> searchRange(std::vector<int> &nums, int target)
        {
            std::vector<int> range{-1, -1};

            int l = binarySearch(nums, target, true);
            int r = binarySearch(nums, target, false);

            if (l <= r)
                range = {l, r};

            return range;
        }
    };
}  // namespace Leet::Medium