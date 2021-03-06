#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace Leet::Medium {
    // Given two strings s1 and s2, write a function to return true if
    // s2 contains the permutation of s1. In other words, one of the first
    // string's permutations is the substring of the second string.

    // Example 1:
    // Input: s1 = "ab" s2 = "eidbaooo"
    // Output: True
    // Explanation: s2 contains one permutation of s1 ("ba").

    // Example 2:
    // Input:s1= "ab" s2 = "eidboaoo"
    // Output: False

    // Constraints:
    // The input strings only contain lower case letters.
    // The length of both given strings is in range [1, 10,000].
    struct PermutationString
    {
        // time: O(nlog(n))
        bool checkPermutation(std::string& s1, std::string& s2)
        {
            std::sort(s1.begin(), s1.end());
            std::sort(s2.begin(), s2.end());

            return s1 == s2;
        }

        // slow, time: O(n^2 log(n)) ish
        bool checkInclusion_slow(std::string s1, std::string s2)
        {
            int s1_len = s1.length();
            int s2_len = s2.length();

            if (s1_len > s2_len)
                return false;

            for (int i = 0; i <= s2_len - s1_len; i++) {
                auto sub_str = s2.substr(i, s1_len);

                if (checkPermutation(s1, sub_str))
                    return true;
            }

            return false;
        }

        // accepted but is still slow
        bool checkInclusion(std::string s1, std::string s2)
        {
            std::vector<int> s1_freq(26, 0);
            std::vector<int> substr_freq(26, 0);

            if (s1.length() > s2.length())
                return false;

            for (const auto& c : s1)
                s1_freq[c - 'a']++;

            // O(n * m)
            for (int i = 0; i <= s2.length() - s1.length(); i++) {
                for (int j = 0; j < s1.length(); j++)
                    substr_freq[s2[i + j] - 'a']++;

                if (s1_freq == substr_freq)
                    return true;

                for (int i = 0; i < 26; i++)
                    substr_freq[i] = 0;
            }

            return false;
        }
    };
}  // namespace Leet::Medium
