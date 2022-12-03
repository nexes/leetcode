#pragma once

#include <cmath>

namespace Leet::Easy {
    // Given an integer n, return true if it is a power of four. Otherwise,
    // return false.

    // An integer n is a power of four, if there exists an integer x such that n
    // == 4x.

    // Example 1:
    // Input: n = 16
    // Output: true

    // Example 2:
    // Input: n = 5
    // Output: false

    // Example 3:
    // Input: n = 1
    // Output: true

    // Constraints:
    // -231 <= n <= 231 - 1

    // Follow up: Could you solve it without loops/recursion?
    struct PowerFour
    {
        bool isPowerofFour(int n)
        {
            if (n == 0)
                return false;

            while (n % 4 == 0) {
                n /= 4;
            }

            return n == 1;
        }

        bool isPowerofFour_noloop(int n)
        {
            if (n == 1)
                return true;

            if (n < 4)
                return false;

            int x = std::log(n) / std::log(4);
            int w = std::pow(4, x);

            return w == n;
        }
    };
}  // namespace Leet::Easy