#pragma once

namespace Leet::Easy {
    // Determine whether an integer is a palindrome. An integer is a palindrome
    // when it reads the same backward as forward.

    // Example 1:
    // Input: 121
    // Output: true

    // Example 2:
    // Input: -121
    // Output: false
    // Explanation: From left to right, it reads -121. From right to left, it
    // becomes 121-. Therefore it is not a palindrome.

    // Example 3:
    // Input: 10
    // Output: false
    // Explanation: Reads 01 from right to left. Therefore it is not a
    // palindrome. Follow up:

    // Coud you solve it without converting the integer to a string?

    struct Palindrome
    {
        bool isPalindrome(int x)
        {
            int reverse = 0;
            int value = x;

            if (x == 0)
                return true;

            if (x < 0 || x % 10 == 0)
                return false;

            while (value > 0) {
                reverse = reverse * 10 + (value % 10);
                value /= 10;
            }

            return reverse == x;
        }
    };
}  // namespace Leet::Easy
