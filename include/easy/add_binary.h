#pragma once

#include <string>

namespace Leet::Easy {
    // Given two binary strings a and b, return their sum as a binary string.

    // Example 1:
    // Input: a = "11", b = "1"
    // Output: "100"

    // Example 2:
    // Input: a = "1010", b = "1011"
    // Output: "10101"

    // Constraints:
    // 1 <= a.length, b.length <= 104
    // a and b consist only of '0' or '1' characters.
    // Each string does not contain leading zeros except for the zero itself.
    struct AddBinary
    {
        std::string addBinary(std::string a, std::string b)
        {
            std::string sum_binary = "";
            int carry = 0;
            int i = a.size() - 1;
            int j = b.size() - 1;

            while (i >= 0 || j >= 0) {
                int digit_a = i >= 0 ? a[i] - '0' : 0;
                int digit_b = j >= 0 ? b[j] - '0' : 0;
                int sum = digit_a + digit_b + carry;

                // 3/2 = 1, 2/2 = 1, 1/2 = 0, 0/2 = 0, carry
                // 3%2 = 1, 2%2 = 0, 1%2 = 1, 0%2 = 0, add
                sum_binary = std::to_string(sum % 2) + sum_binary;
                carry = sum / 2;

                i--;
                j--;
            }

            if (carry == 1)
                sum_binary = std::to_string(carry) + sum_binary;

            return sum_binary;
        }
    };
}  // namespace Leet::Easy
