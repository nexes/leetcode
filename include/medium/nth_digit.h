#pragma once

#include <string>

namespace Leet::Medium {
    // Given an integer n, return the nth digit of the infinite integer sequence
    // [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].

    // Example 1:
    // Input: n = 3
    // Output: 3

    // Example 2:
    // Input: n = 11
    // Output: 0
    // Explanation: The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
    // is a 0, which is part of the number 10.

    // Constraints:
    // 1 <= n <= 231 - 1
    struct NthDigit
    {
        int findNthDigit(int n)
        {
            int step = 1;
            int dec = 1;
            int limit = 10;

            while (n > dec) {
                n -= dec;
                step++;

                if (step == limit) {
                    dec++;
                    limit *= 10;
                }
            }

            // std::cout << "n = " << n << "\n";
            // std::cout << "dec = " << dec << "\n";
            // std::cout << "step = " << step << "\n";
            // std::cout << "limit = " << limit << "\n";

            return std::to_string(step)[n - 1] - 48;
        }
    };
}  // namespace Leet::Medium