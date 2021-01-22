#pragma once

#include <string>
#include <vector>

namespace Leet::Easy {
    // Given two strings s and t , write a function to determine if t is an
    // anagram of s.

    // Example 1:
    // Input: s = "anagram", t = "nagaram"

    // Output: true
    // Example 2:
    // Input: s = "rat", t = "car"
    // Output: false

    // Note:
    // You may assume the string contains only lowercase alphabets.

    // Follow up:
    // What if the inputs contain unicode characters? How would you adapt
    // your solution to such case?
    struct ValidAnagram
    {
        bool isAnagram(std::string s, std::string t)
        {
            std::vector<int> freq(26, 0);

            for (const auto& c : t) {
                freq[c - 'a']++;
            }

            for (const auto& c : s) {
                freq[c - 'a']--;
            }

            for (const auto& c : freq) {
                if (c != 0)
                    return false;
            }

            return true;
        }
    };
}  // namespace Leet::Easy
