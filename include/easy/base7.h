#pragma once

#include <string>

namespace Leet::Easy {
    // Given an integer, return its base 7 string representation.

    // Example 1:
    // Input: 100
    // Output: "202"

    // Example 2:
    // Input: -7
    // Output: "-10"

    // Note: The input will be in range of [-1e7, 1e7].
    struct BaseSeven
    {
        std::string convertToBase7(int num)
        {
            std::string base7{""};
            bool negative = num < 0;

            num = std::abs(num);

            if (num == 0)
                return "0";

            while (num > 0) {
                base7 = std::to_string(num % 7) + base7;
                num /= 7;
            }

            return negative ? "-" + base7 : base7;
        }
    };
}  // namespace Leet::Easy
