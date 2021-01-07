#pragma once

namespace Leet::Medium {
    // Calculate the sum of two integers a and b, but you are not
    // allowed to use the operator + and -.

    // Example 1:
    // Input: a = 1, b = 2
    // Output: 3

    // Example 2:
    // Input: a = -2, b = 3
    // Output: 1
    struct SumTwo
    {
        int getSum(int a, int b)
        {
            int sum = 0;
            int carry = 0;

            while ((a & b) != 0) {
                sum = a ^ b;
                carry = (a & b) << 1;
                a = sum;
                b = carry;
            }

            return a | b;
        }
    };
}  // namespace Leet::Medium
