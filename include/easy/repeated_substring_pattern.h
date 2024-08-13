#pragma once

#include <queue>
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
        // time: O(n^2)
        // space: O(n)
        bool repeatedSubstringPattern(std::string s)
        {
            int len = s.length();
            std::queue<char> q1;
            std::queue<char> q2;

            for (char c : s) {
                q1.push(c);
                q2.push(c);
            }

            for (int i = 1; i <= len / 2; i++) {
                q1.push(q1.front());
                q1.pop();

                if (len % i == 0 && q1 == q2)
                    return true;
            }

            return false;
        }
    };
}  // namespace Leet::Easy