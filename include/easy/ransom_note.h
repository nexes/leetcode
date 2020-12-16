#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>

namespace Leet::Easy {
    // Given an arbitrary ransom note string and another string containing letters
    // from all the magazines, write a function that will return true if the ransom
    // note can be constructed from the magazines ; otherwise, it will return false.
    // Each letter in the magazine string can only be used once in your ransom note.

    // Example 1:
    // Input: ransomNote = "a", magazine = "b"
    // Output: false

    // Example 2:
    // Input: ransomNote = "aa", magazine = "ab"
    // Output: false

    // Example 3:
    // Input: ransomNote = "aa", magazine = "aab"
    // Output: true

    // Constraints:
    // You may assume that both strings contain only lowercase letters.
    struct RansomNote
    {
        // time: O(nlog(n)) space: O(1)
        bool canConstruct(std::string ransomNote, std::string magazine)
        {
            if (magazine.length() < ransomNote.length())
                return false;

            std::sort(ransomNote.begin(), ransomNote.end());
            std::sort(magazine.begin(), magazine.end());
            int i = 0;
            int j = 0;

            while (i < ransomNote.length() && j < magazine.length()) {
                if (ransomNote[i] == magazine[j]) {
                    j++;
                    i++;
                } else {
                    j++;
                }
            }

            return i == ransomNote.length();
        }

        // time: O(n+m) space: O(n)
        bool canConstruct_maps(std::string ransomNote, std::string magazine)
        {
            auto freq_map = std::unordered_map<char, int>{};

            for (auto &c : magazine) {
                if (auto it = freq_map.emplace(c, 1); !it.second) {
                    freq_map[c]++;
                }
            }

            for (auto &c : ransomNote) {
                if (auto it = freq_map.find(c); it == freq_map.end() || freq_map[c] <= 0)
                    return false;

                freq_map[c]--;
            }

            return true;
        }
    };
}  // namespace Leet::Easy
