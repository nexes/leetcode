#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace Leet::Easy {
    // Given a string, find the first non-repeating character in it and
    // return its index. If it doesn't exist, return -1.

    // Examples:
    // s = "leetcode"
    // return 0.

    // s = "loveleetcode"
    // return 2.

    // Note: You may assume the string contains only lowercase English letters.
    struct UniqueChar
    {
        // O(n)
        int firstUniqChar_map(std::string s)
        {
            std::unordered_map<char, int> freq{};

            for (auto &c : s)
                if (auto it = freq.insert({c, 1}); !it.second)
                    freq[c]++;

            for (int i = 0; i < s.length(); i++)
                if (freq[s[i]] == 1)
                    return i;

            return -1;
        }

        // O(n) much faster than using a map
        int firstUniqChar(std::string s)
        {
            std::vector<int> freq(26);

            for (auto &c : s)
                freq[c - 'a']++;

            for (int i = 0; i < s.length(); i++)
                if (freq[s[i] - 'a'] == 1)
                    return i;

            return -1;
        }
    };
}  // namespace Leet::Easy
