#pragma once

#include <cmath>
#include <iostream>

namespace Leet::Easy {

    struct PowerOfThree
    {
        // Given an integer, write a function to determine if it is a power of three.

        // Example 1:
        // Input: 27
        // Output: true

        // Example 2:
        // Input: 0
        // Output: false

        // Example 3:
        // Input: 9
        // Output: true

        // Example 4:
        // Input: 45
        // Output: false

        // Follow up:
        // Could you do it without using any loop / recursion?
        bool isPowerOfThree(int n)
        {
            // In particular, n is of type int. In Java for example, this means it is a 4
            // byte, signed integer. The maximum value of this data type is 2147483647.
            // Three ways of calculating this value are −1 since we use 32 bits to
            // represent the number, half of the range is used for negative numbers and 0
            // is part of the positive numbers Knowing the limitation of n, we can now
            // deduce that the maximum value of n that is also a power of three is
            // 1162261467. We calculate this as:

            // 3^{19} = 11622614673 which is the highest power of 3 before we pass the
            // limit of an int because this limit is a power of three, all other power of
            // threes will divide without a remainder
            auto limit = static_cast<int>(std::pow(3.0, 19.0));
            return n > 0 && limit % n == 0;
        }

        bool isPowerOfThree_linear(int n)
        {
            while (n > 1 && n % 3 == 0) {
                n /= 3;
            }

            return n == 1;
        }
    };

}  // namespace Leet::Easy
