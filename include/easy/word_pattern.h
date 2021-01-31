#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace Leet::Easy {
    // Given a pattern and a string s, find if s follows the same pattern.
    // Here follow means a full match, such that there is a bijection between
    // a letter in pattern and a non-empty word in s.

    // Example 1:
    // Input: pattern = "abba", s = "dog cat cat dog"
    // Output: true

    // Example 2:
    // Input: pattern = "abba", s = "dog cat cat fish"
    // Output: false

    // Example 3:
    // Input: pattern = "aaaa", s = "dog cat cat dog"
    // Output: false

    // Example 4:
    // Input: pattern = "abba", s = "dog dog dog dog"
    // Output: false

    // Constraints:
    // 1 <= pattern.length <= 300
    // pattern contains only lower-case English letters.
    // 1 <= s.length <= 3000
    // s contains only lower-case English letters and spaces ' '.
    // s does not contain any leading or trailing spaces.
    // All the words in s are separated by a single space.
    struct WordPattern
    {
        bool wordPattern(std::string pattern, std::string s)
        {
            // <pattern, word>
            auto map = std::unordered_map<std::string, std::string>{};

            // istream_iterator will skip whitespace on its own.
            auto ss = std::istringstream{s};
            auto words = std::vector(std::istream_iterator<std::string>{ss},
                                     std::istream_iterator<std::string>());

            if (pattern.length() != words.size())
                return false;

            for (int i = 0; i < words.size(); i++) {
                auto pattern_str = std::to_string(pattern[i]);

                // insert pattern, word
                if (auto it = map.emplace(pattern_str, words[i]); !it.second) {
                    if (map[pattern_str] != words[i])
                        return false;
                }

                // insert word, pattern
                if (auto it = map.emplace(words[i], pattern_str); !it.second) {
                    if (map[words[i]] != pattern_str)
                        return false;
                }
            }

            return true;
        }
    };
}  // namespace Leet::Easy
