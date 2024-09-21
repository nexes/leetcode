#pragma once

#include <string>

namespace Leet::Medium {

    struct LongestPalindromeSubstr
    {
        // Given a string s, find the longest palindromic substring in s.

        // Example 1:
        // Input: "babad"
        // Output: "bab"
        // Note: "aba" is also a valid answer.

        // Example 2:
        // Input: "cbbd"
        // Output: "bb"

        // Constraints:
        // 1 <= s.length <= 1000
        // s consist of only digits and English letters.
        int palindromLength(std::string s, int l, int r)
        {
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                l--;
                r++;
            }

            return r - l - 1;
        }

        std::string longestPalindrome(std::string s)
        {
            int start = 0;
            int len = 0;

            for (int i = 0; i < s.length(); i++) {
                int odd = palindromLength(s, i, i);
                int even = palindromLength(s, i, i + 1);

                if (odd > len) {
                    len = odd;
                    start = i - (len / 2);
                }

                if (even > len) {
                    len = even;
                    start = i - (len / 2) + 1;
                }
            }

            return s.substr(start, len);
        }
    };
}  // namespace Leet::Medium
