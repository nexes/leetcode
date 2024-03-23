#pragma once

#include <cmath>

namespace Leet::Easy {
    // Given a positive integer n, find the pivot integer x such that:
    // The sum of all elements between 1 and x inclusively equals the sum of all elements
    // between x and n inclusively. Return the pivot integer x. If no such integer exists,
    // return -1. It is guaranteed that there will be at most one pivot index for the
    // given input.

    // Example 1:
    // Input: n = 8
    // Output: 6
    // Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.

    // Example 2:
    // Input: n = 1
    // Output: 1
    // Explanation: 1 is the pivot integer since: 1 = 1.

    // Example 3:
    // Input: n = 4
    // Output: -1
    // Explanation: It can be proved that no such integer exist.

    // Constraints:
    // 1 <= n <= 1000
    struct PivotInt
    {
        // O(whatever sqrt(n) is)
        int pivotInteger(int n)
        {
            // get the sum from 1 -> n. If the sqrt is a whole number, it's the pivot
            double x = std::sqrt((n * (n + 1)) / 2);
            return x == (int)x ? x : -1;
        }

        // O(n)
        int pivotInteger_loop(int n)
        {
            int sum = (n * (n + 1)) / 2;
            int leftSum = 0;
            int index = 1;

            while (index <= n) {
                leftSum += index;

                if (leftSum == (sum - leftSum) + index)
                    return index;

                index++;
            }

            return -1;
        }
    };
}  // namespace Leet::Easy