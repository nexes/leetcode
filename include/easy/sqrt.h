#pragma once

#include <iostream>

namespace Leet::Easy
{
    // Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
    // Since the return type is an integer, the decimal digits are truncated and only the
    // integer part of the result is returned.

    // Example 1:
    // Input: 4
    // Output: 2

    // Example 2:
    // Input: 8
    // Output: 2
    // Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.

    struct Sqrt
    {
        int mySqrt(int x)
        {
            double s = x;

            if (x < 2)
                return x;

            while (true)
            {
                s = (0.5 * (s + (x / s)));

                if (s * s <= (x + 0.001) && x - (s * s) < 0.001)
                    break;
            }

            return s;
        }
    };
} // namespace Leet::Easy
