#pragma once

#include <string>

namespace Leet::Easy {
    // Given a string, you need to reverse the order of characters in each word within a
    // sentence while still preserving whitespace and initial word order.

    // Example 1:
    // Input: "Let's take LeetCode contest"
    // Output: "s'teL ekat edoCteeL tsetnoc"

    // Note: In the string, each word is separated by single space and there will not be
    // any extra space in the string.
    struct ReverseWords
    {
        void swap_string(std::string& s, int start, int end)
        {
            while (start < end) {
                auto temp = s[start];
                s[start] = s[end];
                s[end] = temp;

                start++;
                end--;
            }
        }

        // constant space sliding window.
        // time: O(n * m) space: O(1)
        std::string reverseWords(std::string s)
        {
            int start = 0;

            for (int end = 0; end < s.length(); end++) {
                while (end < s.length() && s[end] != ' ')
                    end++;

                swap_string(s, start, end - 1);
                start = end + 1;
            }

            return s;
        }
    };
}  // namespace Leet::Easy
