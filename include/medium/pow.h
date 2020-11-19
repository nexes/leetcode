#pragma once

#include <climits>

namespace Leet::Medium {
    // Implement pow(x, n), which calculates x raised to the power n (i.e. xn).

    // Example 1:
    // Input: x = 2.00000, n = 10
    // Output: 1024.00000

    // Example 2:
    // Input: x = 2.10000, n = 3
    // Output: 9.26100

    // Example 3:
    // Input: x = 2.00000, n = -2
    // Output: 0.25000
    // Explanation: 2-2 = 1/22 = 1/4 = 0.25

    // Constraints:
    // -100.0 < x < 100.0
    // -231 <= n <= 231-1
    // -104 <= xn <= 104
    struct Pow
    {
        double myPow(double base, int exp)
        {
            double carry = 1;
            int exponent = std::abs(exp);
            int sign = base < 0 ? -1 : 1;

            // edge case
            if (exp == 0)
                return 1;

            // edge case
            if (exp == INT_MIN && base > 1.0)
                return 0;

            while (exponent > 1) {
                if (exponent % 2 != 0) {
                    carry *= base;
                }

                exponent /= 2;
                base *= base;
            }

            return (exp > 0) ? base * carry : sign * 1.0 / (base * carry);
        }
    };
}  // namespace Leet::Medium
