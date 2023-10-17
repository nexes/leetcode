#pragma once

#include <sstream>
#include <string>
#include <vector>

namespace Leet::Easy {
    // Given a string s, check if it can be constructed by taking a substring of
    // it and appending multiple copies of the substring together.

    // Example 1:
    // Input: s = "abab"
    // Output: true
    // Explanation: It is the substring "ab" twice.

    // Example 2:
    // Input: s = "aba"
    // Output: false

    // Example 3:
    // Input: s = "abcabcabcabc"
    // Output: true
    // Explanation: It is the substring "abc" four times or the substring
    // "abcabc" twice.

    // Constraints:
    // 1 <= s.length <= 104
    // s consists of lowercase English letters.
    struct RepeatedSubString
    {
        bool repeatedSubstringPattern(std::string s)
        {
            int len = s.length() / 2;
            std::stringstream substr;

            for (int i = 0; i < len; i++) {
                substr << s[i];

                if (s.length() % substr.str().length() == 0) {
                    std::stringstream check_substr;

                    // see if we can build the string
                    for (int j = 0; j < s.length() / substr.str().length(); j++)
                        check_substr << substr.str();

                    if (check_substr.str() == s)
                        return true;
                }
            }

            return false;
        }
    };
}  // namespace Leet::Easy