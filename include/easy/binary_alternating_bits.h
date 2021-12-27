#pragma once

namespace Leet::Easy {
    // Given a positive integer, check whether it has alternating bits: namely, if two
    // adjacent bits will always have different values.

    // Example 1:
    // Input: n = 5
    // Output: true
    // Explanation: The binary representation of 5 is: 101

    // Example 2:
    // Input: n = 7
    // Output: false
    // Explanation: The binary representation of 7 is: 111.

    // Example 3:
    // Input: n = 11
    // Output: false
    // Explanation: The binary representation of 11 is: 1011.

    // Constraints:
    // 1 <= n <= 231 - 1
    struct BinaryAltBits
    {
        bool hasAlternatingBits(int n)
        {
            int last_bit = (n & 0x01);
            n = n >> 1;

            while (n) {
                if ((n & 0x01) == last_bit)
                    return false;

                last_bit = last_bit ^ 1;
                n = n >> 1;
            }

            return true;
        }
    };

}  // namespace Leet::Easy