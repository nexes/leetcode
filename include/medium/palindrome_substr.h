#pragma once

#include <string>

namespace Leet::Medium {

    struct PalindromeSubstr
    {
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
                    if (found.length() <= j - i && is_palindrome(s, i, j))
                        found = s.substr(i, j - i + 1);
                }
            }

            return found;
        }

        std::string longestPalindrome_faster(std::string s)
        {
            const int len = s.length();
            std::string found = "";

            // O(n^2)
            // this needs to be looped over twice
            for (int mid = 0; mid < len; mid++) {
                for (int offset = 0; mid - offset >= 0 && mid + offset < len; offset++) {
                    if (s.at(mid - offset) != s.at(mid + offset)) break;

                    int size = offset * 2 + 1;
                    if (found.length() < size) found = s.substr(mid - offset, size);
                }
            }

            for (int mid = 0; mid < len; mid++) {
                for (int offset = 1; mid - offset + 1 >= 0 && mid + offset < len; offset++) {
                    if (s.at(mid - offset + 1) != s.at(mid + offset)) break;

                    int size = offset * 2;
                    if (found.length() < size) found = s.substr(mid - offset + 1, size);
                }
            }

            return found;
        }

        bool is_palindrome(std::string_view v, int start, int end)
        {
            if (start >= end || end > v.length() - 1)
                return false;

            for (; start < end; start++, end--)
                if (v.at(start) != v.at(end)) return false;

            return true;
        }
    };
}  // namespace Leet::Medium
