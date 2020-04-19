#pragma once

#include <string>

namespace Leet::Medium {

    struct PalindromeSubstr {
        // Given a string s, find the longest palindromic substring in s.
        // You may assume that the maximum length of s is 1000.

        // Example 1:
        // Input: "babad"
        // Output: "bab"
        // Note: "aba" is also a valid answer.

        // Example 2:
        // Input: "cbbd"
        // Output: "bb"
        std::string longestPalindrome(std::string s)
        {
            const int len = s.length();
            std::string found = s.substr(0, 1);

            if (len == 1) return s;

            // O(n^3) brute force
            for (int i = 0; i < len; i++) {
                for (int j = len - 1; j > i; j--) {
                    if (better_is_palindrome(s, i, j)) {
                        if (found.length() <= j - i) {
                            found = s.substr(i, j - i + 1);

                            // ugly hack
                            if (j == len - 1) return found;
                        }
                    }
                }
            }

            return found;
        }

        // doesn't require a string.substr call each time to call
        bool better_is_palindrome(std::string_view v, int start, int end)
        {
            if (start >= end || end > v.length() - 1)
                return false;

            for (; start < end; start++, end--)
                if (v.at(start) != v.at(end)) return false;

            return true;
        }

        bool is_palindrome(std::string_view v)
        {
            const int len = v.length();

            for (int i = 0, j = len - 1; i < len; i++, j--)
                if (v.at(i) != v.at(j)) return false;

            return true;
        }
    };
}  // namespace Leet::Medium
