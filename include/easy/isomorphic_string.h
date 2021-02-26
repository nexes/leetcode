#pragma once

#include <string>
#include <unordered_map>

namespace Leet::Easy {
    // Given two strings s and t, determine if they are isomorphic.
    // Two strings s and t are isomorphic if the characters in s can
    // be replaced to get t. All occurrences of a character must be
    // replaced with another character while preserving the order of
    // characters. No two characters may map to the same character,
    // but a character may map to itself.

    // Example 1:
    // Input: s = "egg", t = "add"
    // Output: true

    // Example 2:
    // Input: s = "foo", t = "bar"
    // Output: false

    // Example 3:
    // Input: s = "paper", t = "title"
    // Output: true

    // Constraints:
    // 1 <= s.length <= 5 * 104
    // t.length == s.length
    // s and t consist of any valid ascii character.
    struct IsomorphicStrings
    {
        bool isIsomorphic(std::string s, std::string t)
        {
            std::unordered_map<char, char> map{};

            for (int i = 0; i < s.length(); i++) {
                if (map.find(s[i]) != map.end()) {
                    if (map[s[i]] != t[i])
                        return false;

                } else {
                    // does there exist a key already mapped to this value
                    for (const auto& [key, value] : map)
                        if (value == t[i])
                            return false;

                    map[s[i]] = t[i];
                }
            }

            return true;
        }
    };
}  // namespace Leet::Easy
