#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

namespace Leet::Medium {
    // A zero-indexed array A of length N contains all integers from 0 to N-1. Find and
    // return the longest length of set S, where S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }
    // subjected to the rule below.

    // Suppose the first element in S starts with the selection of element A[i] of index =
    // i, the next element in S should be A[A[i]], and then A[A[A[i]]]… By that analogy,
    // we stop adding right before a duplicate element occurs in S.

    // Example 1:
    // Input: A = [5,4,0,3,1,6,2]
    // Output: 4
    // Explanation:
    // A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

    // One of the longest S[K]:
    // S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}

    // Note:
    // N is an integer within the range [1, 20,000].
    // The elements of A are all distinct.
    // Each element of A is an integer within the range [0, N-1].
    struct ArrayNested
    {
        // time: O(n^2) worse case, space: O(1)
        int arrayNesting_naive(std::vector<int>& nums)
        {
            int max = 0;

            for (int i = 0; i < nums.size(); i++) {
                auto start = nums[i];
                auto index = start;
                auto count = 1;

                while (start != nums[index]) {
                    count++;
                    index = nums[index];
                }

                max = std::max(max, count);
            }

            return max;
        }

        // time: O(n), space: O(n)
        int arrayNesting(std::vector<int>& nums)
        {
            std::vector<bool> visited(nums.size(), false);
            int max = 0;

            for (int i = 0; i < nums.size(); i++) {
                auto start = nums[i];
                auto index = start;
                auto count = 1;

                visited[i] = true;

                while (start != nums[index] && !visited[index]) {
                    count++;
                    visited[index] = true;
                    index = nums[index];
                }

                max = std::max(max, count);
            }

            return max;
        }
    };
}  // namespace Leet::Medium
