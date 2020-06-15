#pragma once

namespace Leet::Easy
{

    // Given a 32-bit signed integer, reverse digits of an integer.

    // Example 1:
    // Input: 123
    // Output: 321

    // Example 2:
    // Input: -123
    // Output: -321

    // Example 3:
    // Input: 120
    // Output: 21

    // Note:  Assume we are dealing with an environment which could only store integers within
    // the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume
    // that your function returns 0 when the reversed integer overflows.

    struct Reverse_int
    {
        int reverse(int x)
        {
            long rev = 0;
            int xx = std::abs(x);

            while (xx > 0)
            {
                rev = rev * 10 + xx % 10;
                xx /= 10;
            }

            if (rev > std::numeric_limits<int>::max())
                return 0;

            return x < 0 ? -rev : rev;
        }
    };
} // namespace Leet::Easy
