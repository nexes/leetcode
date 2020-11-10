#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

namespace Leet::Medium {
    // Given an array A of integers, a ramp is a tuple (i, j) for which i < j and A[i] <= A[j].
    // The width of such a ramp is j - i. Find the maximum width of a ramp in A.
    // If one doesn't exist, return 0.

    // Example 1:
    // Input: [6,0,8,2,1,5]
    // Output: 4
    // Explanation:
    // The maximum width ramp is achieved at (i, j) = (1, 5): A[1] = 0 and A[5] = 5.

    // Example 2:
    // Input: [9,8,1,0,1,9,4,0,4,1]
    // Output: 7
    // Explanation:
    // The maximum width ramp is achieved at (i, j) = (2, 9): A[2] = 1 and A[9] = 1.

    // Note:
    // 2 <= A.length <= 50000
    // 0 <= A[i] <= 50000
    struct MaxWidthRamp
    {
        // a = [6, 0, 8, 2, 1, 5]
        // idx_a = [1,4,3,-1,-1,5,0,-1,2]
        // idx_a is the inverse of a. indx_a[a[i]] = i;
        // the distance (width) from a[i] to a[j] is found by
        // [1, 4, 3, -1, -1, 5, 0, -1, 2]
        //  0, 1, 2,  3,  4, 5, 6, 7,  8
        //
        // distance from 0 -> 1 is indx_a[1] - indx_a[0] etc.
        int maxWidthRamp(std::vector<int>& a)
        {
            auto res = 0;
            auto max = *std::max_element(a.begin(), a.end());
            auto indx_arr = std::vector<int>(max + 1, -1);

            for (int i = 0; i < a.size(); i++)
                indx_arr[a[i]] = i;

            for (int i = indx_arr.size() - 1; i > 0; i--)
                indx_arr[i - 1] = std::max(indx_arr[i - 1], indx_arr[i]);

            for (int i = 0; i < a.size(); i++)
                res = std::max(res, indx_arr[a[i]] - i);

            return res;
        }
    };
}  // namespace Leet::Medium
