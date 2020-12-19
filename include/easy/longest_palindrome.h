#pragma once

#include <string>
#include <unordered_map>

namespace Leet::Easy {
    // Given a string s which consists of lowercase or uppercase letters,
    // return the length of the longest palindrome that can be built with those letters.
    // Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

    // Example 1:
    // Input: s = "abccccdd"
    // Output: 7
    // Explanation:
    // One longest palindrome that can be built is "dccaccd", whose length is 7.

    // Example 2:
    // Input: s = "a"
    // Output: 1

    // Example 3:
    // Input: s = "bb"
    // Output: 2

    // Constraints:
    // 1 <= s.length <= 2000
    // s consists of lowercase and/or uppercase English letters only.
    struct LongestPalindrome
    {
        int longestPalindrome(std::string s)
        {
            auto counts = std::unordered_map<char, int>{};
            int add_one = 0;
            int length = 0;

            for (const auto &c : s) {
                if (auto it = counts.emplace(c, 1); !it.second) {
                    counts[c]++;
                }
            }

            for (const auto [key, value] : counts) {
                if (value % 2 == 0) {
                    length += value;
                } else if (value > 1) {
                    length += value - 1;
                    add_one = 1;
                } else {
                    add_one = 1;
                }
            }

            return length + add_one;
        }
    };
}  // namespace Leet::Easy
