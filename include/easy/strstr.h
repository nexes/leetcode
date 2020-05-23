#pragma once

#include <string>

namespace Leet::Easy
{
    // Return the index of the first occurrence of needle in haystack, or -1 if needle is not
    // part of haystack.

    // Example 1:
    // Input: haystack = "hello", needle = "ll"
    // Output: 2

    // Example 2:
    // Input: haystack = "aaaaa", needle = "bba"
    // Output: -1

    // Clarification:
    // What should we return when needle is an empty string? This is a great question to ask
    // during an interview. For the purpose of this problem, we will return 0 when needle is
    // an empty string. This is consistent to C's strstr() and Java's indexOf().
    struct Str
    {
        // works, but I'm not nuts about this solution. I should use a sliding window approach.
        // Runtime: 4 ms, faster than 90.67% of C++ online submissions for Implement strStr().
        int strStr(std::string haystack, std::string needle)
        {
            if (needle.empty())
                return 0;

            int stack_len = haystack.length();
            int needle_len = needle.length();

            for (int i = 0; i <= stack_len - needle_len; i++)
            {
                if (haystack.substr(i, needle_len) == needle)
                    return i;
            }

            return -1;
        }
    };
} // namespace Leet::Easy
