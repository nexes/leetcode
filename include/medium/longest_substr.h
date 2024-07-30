#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace Leet::Medium {
    // Given a string, find the length of the longest substring without repeating
    // characters.

    // Example 1:
    // Input: "abcabcbb"
    // Output: 3
    // Explanation: The answer is "abc", with the length of 3.

    // Example 2:
    // Input: "bbbbb"
    // Output: 1
    // Explanation: The answer is "b", with the length of 1.

    // Example 3:
    // Input: "pwwkew"
    // Output: 3
    // Explanation: The answer is "wke", with the length of 3.
    // Note that the answer must be a substring, "pwke" is a subsequence and not a
    // substring.
    struct LongestSubString
    {
        // using a set to control the sliding window
        int lengthOfLongestSubstring(std::string s)
        {
            int l = 0;
            int r = 0;
            int maxlen = 0;
            std::unordered_set<char> seen;

            while (r < s.length()) {
                while (seen.count(s[r]) == 1)
                    seen.erase(s[l++]);

                seen.insert(s[r]);
                maxlen = std::max(maxlen, r - l + 1);
                r++;
            }

            return maxlen;
        }

        int lengthOfLongestSubstring_using_map(std::string s)
        {
            char c;
            int l = 0;
            int result = 0;
            int len = s.length();
            std::unordered_map<char, int> c_map;

            for (int i = 0; i < len; i++) {
                c = s.at(i);
                if (auto it = c_map.emplace(c, i); !it.second) {
                    result = std::max(i - l, result);

                    if (l <= c_map.at(c))
                        l = c_map.at(c) + 1;

                    c_map.at(c) = i;
                }
            }

            result = std::max(len - l, result);
            return result;
        }
    };
}  // namespace Leet::Medium
