#pragma once

#include <iostream>

namespace Leet::Easy {
    // Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
    // Since the return type is an integer, the decimal digits are truncated and only the
    // integer part of the result is returned.

    // Example 1:
    // Input: 4
    // Output: 2

    // Example 2:
    // Input: 8
    // Output: 2
    // Explanation: The square root of 8 is 2.82842..., and since the decimal part is
    // truncated, 2 is returned.

    struct Sqrt
    {
        // binary search
        int mySqrt(int x)
        {
            if (x < 2)
                return x;

            int low = 1;
            int high = x;
            double mid = 0;

            while (low < high) {
                mid = low + (high - low) / 2;

                if (mid * mid == x)
                    return mid;

                if (mid * mid > x) {
                    high = mid;
                }
                if (mid * mid < x) {
                    low = mid + 1;
                }
            }

            return low - 1;
        }

        int mySqrt_not_great(int x)
        {
            double s = x;

            if (x < 2)
                return x;

            while (true) {
                s = (0.5 * (s + (x / s)));

                if (s * s <= (x + 0.001) && x - (s * s) < 0.001)
                    break;
            }

            return s;
        }
    };
}  // namespace Leet::Easy
