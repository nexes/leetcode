#pragma once

#include <string>
#include <unordered_map>

namespace Leet::Hard {
    // Given two strings s and t of lengths m and n respectively, return the minimum
    // window substring
    // of s such that every character in t (including duplicates) is included in the
    // window. If there is no such substring, return the empty string "".

    // The testcases will be generated such that the answer is unique.

    // Example 1:
    // Input: s = "ADOBECODEBANC", t = "ABC"
    // Output: "BANC"
    // Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from
    // string t.

    // Example 2:
    // Input: s = "a", t = "a"
    // Output: "a"
    // Explanation: The entire string s is the minimum window.

    // Example 3:
    // Input: s = "a", t = "aa"
    // Output: ""
    // Explanation: Both 'a's from t must be included in the window.
    // Since the largest window of s only has one 'a', return empty string.

    // Constraints:
    // m == s.length
    // n == t.length
    // 1 <= m, n <= 105
    // s and t consist of uppercase and lowercase English letters.

    // Follow up: Could you find an algorithm that runs in O(m + n) time?
    struct MinWinodwSubstring
    {
        std::string minWindow(std::string s, std::string t)
        {
            std::unordered_map<char, int> charfreq;
            std::string result = "";

            if (t.length() > s.length())
                return "";

            for (char c : t)
                charfreq[c]++;

            int start = 0;
            int minstart = 0;
            int count = t.length();
            int mindist = INT_MAX;
            for (int end = 0; end < s.length(); end++) {
                if (charfreq[s[end]]-- > 0)
                    count--;

                while (count == 0) {
                    if (end - start + 1 < mindist) {
                        mindist = end - start + 1;
                        minstart = start;
                    }

                    if (charfreq[s[start++]]++ == 0)
                        count++;
                }
            }

            return mindist == INT_MAX ? "" : s.substr(minstart, mindist);
        }
    };
}  // namespace Leet::Hard