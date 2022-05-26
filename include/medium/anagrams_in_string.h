#pragma once

#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

namespace Leet::Medium {
    // Given a string s and a non-empty string p, find all the start indices of
    // p's anagrams in s. Strings consists of lowercase English letters only and
    // the length of both strings s and p will not be larger than 20,100. The
    // order of output does not matter.

    // Example 1:
    // Input:
    // s: "cbaebabacd" p: "abc"

    // Output:
    // [0, 6]

    // Explanation:
    // The substring with start index = 0 is "cba", which is an anagram of
    // "abc". The substring with start index = 6 is "bac", which is an anagram
    // of "abc".

    // Example 2:
    // Input:
    // s: "abab" p: "ab"

    // Output:
    // [0, 1, 2]

    // Explanation:
    // The substring with start index = 0 is "ab", which is an anagram of "ab".
    // The substring with start index = 1 is "ba", which is an anagram of "ab".
    // The substring with start index = 2 is "ab", which is an anagram of
    // "ab".ct Anagrams
    struct Anagram
    {
        bool is_mutual_anagram(std::string word, std::string anagram)
        {
            if (word.length() != anagram.length())
                return false;

            std::sort(word.begin(), word.end());
            std::sort(anagram.begin(), anagram.end());

            return word == anagram;
        }

        // this is the naive approach O(n^2)
        std::vector<int> findAnagrams(std::string s, std::string p)
        {
            int p_len = p.length();
            int s_len = s.length();
            std::string sub;
            std::vector<int> indices;

            for (int i = 0; i + p_len <= s_len; i++) {
                sub = s.substr(i, p_len);
                if (is_mutual_anagram(sub, p)) {
                    indices.push_back(i);
                }
            }

            return indices;
        }

        // using a sliding window algorithm. O(n)
        std::vector<int> findAnagrams_sliding_window(std::string s,
                                                     std::string p)
        {
            std::vector<int> indices;

            if (s.length() < p.length())
                return indices;

            int win_begin = 0;
            int win_end = 0;
            int p_len = p.length();
            int s_len = s.length();

            std::array<int, 26> s_hash{0};
            std::array<int, 26> p_hash{0};

            for (auto &c : p)
                p_hash[c - 'a']++;

            // extend our window to p.size
            while (win_end - win_begin < p_len)
                s_hash[s.at(win_end++) - 'a']++;

            while (win_end <= s_len) {
                if (p_hash == s_hash)
                    indices.push_back(win_begin);

                s_hash[s.at(win_begin++) - 'a']--;

                if (win_end < s_len)
                    s_hash[s.at(win_end) - 'a']++;

                win_end++;
            }

            return indices;
        }
    };
}  // namespace Leet::Medium
