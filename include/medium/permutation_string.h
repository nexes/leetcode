#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>

namespace Leet::Medium {
    // Given two strings s1 and s2, return true if s2 contains a permutation of s1, or
    // false otherwise. In other words, return true if one of s1's permutations is the
    // substring of s2.

    // Example 1:
    // Input: s1 = "ab", s2 = "eidbaooo"
    // Output: true
    // Explanation: s2 contains one permutation of s1 ("ba").

    // Example 2:
    // Input: s1 = "ab", s2 = "eidboaoo"
    // Output: false

    // Constraints:
    // 1 <= s1.length, s2.length <= 104
    // s1 and s2 consist of lowercase English letters.
    struct PermutationString
    {
        // time: O(n)
        // space: O(n)
        bool checkInclusion(std::string s1, std::string s2)
        {
            std::unordered_map<char, int> s1freq;
            std::unordered_map<char, int> windowfreq;
            int l = 0;

            for (char c : s1)
                s1freq[c]++;

            for (int r = 0; r < s2.length(); r++) {
                windowfreq[s2[r]]++;

                if (s1freq == windowfreq)
                    return true;

                while (r - l + 1 >= s1.length()) {
                    windowfreq[s2[l]]--;

                    if (windowfreq[s2[l]] <= 0)
                        windowfreq.erase(s2[l]);
                    l++;
                }
            }

            return false;
        }
    };
}  // namespace Leet::Medium
