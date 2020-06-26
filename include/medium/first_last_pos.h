#pragma once

#include <algorithm>
#include <iostream>

namespace Leet::Medium
{
    // Given an array of integers nums sorted in ascending order, find the starting and
    // ending position of a given target value. Your algorithm's runtime complexity must
    // be in the order of O(log n). If the target is not found in the array, return [-1, -1].

    // Example 1:
    // Input: nums = [5,7,7,8,8,10], target = 8
    // Output: [3,4]

    // Example 2:
    // Input: nums = [5,7,7,8,8,10], target = 6
    // Output: [-1,-1]
    struct FirstLastPos
    {
        // using STL lower and upper bound
        std::vector<int> searchRange_stl(std::vector<int> &nums, int target)
        {
            std::vector<int> found{-1, -1};
            auto begin_it = nums.begin();

            auto first = std::lower_bound(nums.begin(), nums.end(), target);
            if (first == nums.end() || *first != target)
                return found;

            auto second = std::upper_bound(nums.begin(), nums.end(), target);

            found[0] = first - begin_it;
            found[1] = second - begin_it - 1;

            return found;
        }

        // using no STL functions
        std::vector<int> searchRange(std::vector<int> &nums, int target)
        {
            int len = nums.size();
            int l = 0;
            int r = len;
            int mid;
            std::vector<int> found{-1, -1};

            // left index
            while (l < r)
            {
                mid = (r + l) / 2;

                if (nums[mid] >= target)
                    r = mid;
                else
                    l = mid + 1;
            }

            if (l >= len || nums.at(l) != target)
                return found;

            found[0] = l;

            l = 0;
            r = len;
            // right index
            while (l < r)
            {
                mid = (r + l) / 2;

                if (nums[mid] > target)
                    r = mid;
                else
                    l = mid + 1;
            }

            found[1] = l - 1;
            return found;
        }
    };
} // namespace Leet::Medium
