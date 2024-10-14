#pragma once

#include <string>
#include <unordered_map>

namespace Leet::Medium {
    // Given a string s, return the length of the longest
    // substring
    // that contains at most two distinct characters.

    // Example 1:
    // Input: s = "eceba"
    // Output: 3
    // Explanation: The substring is "ece" which its length is 3.

    // Example 2:
    // Input: s = "ccaabbb"
    // Output: 5
    // Explanation: The substring is "aabbb" which its length is 5.

    // Constraints:
    // 1 <= s.length <= 105
    // s consists of English letters.
    struct LongestSubStrTwoDistChars
    {
        int lengthOfLongestSubstringTwoDistinct(std::string s)
        {
            int l = 0;
            int len = 0;
            std::unordered_map<char, int> chars;

            for (int r = 0; r < s.length(); r++) {
                chars[s[r]]++;

                while (chars.size() > 2) {
                    chars[s[l]]--;
                    if (chars[s[l]] == 0)
                        chars.erase(s[l]);
                    l++;
                }

                if (chars.size() <= 2)
                    len = std::max(len, r - l + 1);
            }

            return len;
        }

        // same problem as above, but k instead of 2
        int lengthOfLongestSubstringKDistinct(std::string s, int k)
        {
            int l = 0;
            int len = 0;
            std::unordered_map<char, int> chars;

            for (int r = 0; r < s.length(); r++) {
                chars[s[r]]++;

                while (chars.size() > k) {
                    chars[s[l]]--;
                    if (chars[s[l]] == 0)
                        chars.erase(s[l]);
                    l++;
                }

                if (chars.size() <= k)
                    len = std::max(len, r - l + 1);
            }

            return len;
        }
    };
}  // namespace Leet::Medium