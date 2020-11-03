#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace Leet::Easy {
    // You are given an array of strings words and a string chars.
    // A string is good if it can be formed by characters from chars
    // (each character can only be used once). Return the sum of lengths
    // of all good strings in words.

    // Example 1:
    // Input: words = ["cat","bt","hat","tree"], chars = "atach"
    // Output: 6
    // Explanation:
    // The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.

    // Example 2:
    // Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
    // Output: 10
    // Explanation:
    // The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.

    // Note:
    // 1 <= words.length <= 1000
    // 1 <= words[i].length, chars.length <= 100
    // All strings contain lowercase English letters only.
    struct CountChars
    {
        int countCharacters(std::vector<std::string>& words, std::string chars)
        {
            auto freq = std::unordered_map<char, int>{};
            bool add_len = false;
            int len = 0;

            for (auto& c : chars)
                freq[c]++;

            std::unordered_map<char, int> temp_freq;

            for (int i = 0; i < words.size(); i++) {
                temp_freq = freq;
                add_len = false;

                for (int j = 0; j < words[i].length(); j++) {
                    if (temp_freq.find(words[i][j]) == temp_freq.end())
                        break;

                    temp_freq[words[i][j]]--;

                    if (temp_freq[words[i][j]] < 0)
                        break;

                    if (j == words[i].length() - 1)
                        add_len = true;
                }

                if (add_len)
                    len += words[i].length();
            }

            return len;
        }
    };
}  // namespace Leet::Easy
