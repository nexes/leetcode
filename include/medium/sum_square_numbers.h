#pragma once

#include <cmath>

namespace Leet::Medium {
    // Given a non-negative integer c, decide whether there're two integers a and b such
    // that a2 + b2 = c.

    // Example 1:
    // Input: c = 5
    // Output: true
    // Explanation: 1 * 1 + 2 * 2 = 5

    // Example 2:
    // Input: c = 3
    // Output: false

    // Constraints:
    // 0 <= c <= 231 - 1
    struct SumSquareNumbers
    {
        bool judgeSquareSum_bruteforce(int c)
        {
            int limit = (int)std::sqrt(c);

            for (int a = 0; a <= limit; a++)
                for (int b = 0; b <= limit; b++)
                    if (c - (a * a) == (b * b))
                        return true;

            return false;
        }

        bool binarySearchSum(int target, int l, int r)
        {
            // we want to find a number 'a' when squared == the target
            while (l <= r) {
                int a = l + (r - l) / 2;

                if (a * a == target)
                    return true;

                if (a * a < target)
                    l = a + 1;
                else
                    r = a - 1;
            }

            return false;
        }

        bool judgeSquareSum(int c)
        {
            // a^ + b^2 = c
            // if we choose b, we need to find a like this
            // a^2 = c - b^2
            int limit = (int)std::sqrt(c);

            for (int b = 0; b <= limit; b++) {
                int a = c - (b * b);

                if (binarySearchSum(a, b, limit))
                    return true;
            }

            return false;
        }
    };
}  // namespace Leet::Medium