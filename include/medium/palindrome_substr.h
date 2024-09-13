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
        std::string longestPalindrome(std::string s)
        {
            int len = 0;
            int start = 0;
            std::string palindrome = "";

            auto check = [&](int l, int r) -> int {
                while (l >= 0 && r < s.length() && s[l] == s[r]) {
                    l--;
                    r++;
                }
                return r - l - 1;
            };

            for (int i = 0; i < s.length(); i++) {
                // check for even and odd length strings
                int even = check(i, i);
                int odd = check(i, i + 1);

                if (even > len) {
                    len = even;
                    start = i - (len / 2);
                }

                if (odd > len) {
                    len = odd;
                    start = i - (len / 2) + 1;
                }
            }

            palindrome = s.substr(start, len);
            return palindrome;
        }
    };
}  // namespace Leet::Medium
