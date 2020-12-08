#pragma once

#include <algorithm>
#include <string>

namespace Leet::Easy {
    // Given two non-negative integers num1 and num2 represented as string,
    // return the sum of num1 and num2.

    // Note:
    // The length of both num1 and num2 is < 5100.
    // Both num1 and num2 contains only digits 0-9.
    // Both num1 and num2 does not contain any leading zero.
    // You must not use any built-in BigInteger library or convert the inputs to
    // integer directly.
    struct AddString
    {
        std::string addStrings(std::string num1, std::string num2)
        {
            int num1_idx = num1.length() - 1;
            int num2_idx = num2.length() - 1;
            int carry = 0;
            std::string ans{""};

            while (num1_idx >= 0 || num2_idx >= 0) {
                int digit1 = num1_idx >= 0 ? num1[num1_idx--] - '0' : 0;
                int digit2 = num2_idx >= 0 ? num2[num2_idx--] - '0' : 0;

                ans.push_back((digit1 + digit2 + carry) % 10 + '0');
                carry = (digit1 + digit2 + carry) / 10;
            }

            if (carry > 0)
                ans.push_back(carry + '0');

            std::reverse(ans.begin(), ans.end());
            return ans;
        }
    };
}  // namespace Leet::Easy
