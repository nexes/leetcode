#pragma once

namespace Leet::Medium
{
    // Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

    // Example 1:
    // Input: [5,7]
    // Output: 4

    // Example 2:
    // Input: [0,1]
    // Output: 0
    struct BitwiseAnd
    {
        int rangeBitwiseAnd(int m, int n)
        {
            if (m == 0 || n == 0)
                return 0;

            int res = m;

            for (int i = m + 1; i <= n; i++)
                res &= i;

            return res;
        }

        // shift both numbers down until the bits are all 1. then shift left by that
        // number. This removes the zeros.
        int rangeBitwiseAnd_clever(int m, int n)
        {
            if (m == 0 || n == 0)
                return 0;

            int i = 0;

            while (m != n)
            {
                m >>= 1;
                n >>= 1;
                i++;
            }

            return m << i;
        }
    };
} // namespace Leet::Medium
