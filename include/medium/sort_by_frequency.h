#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

namespace Leet::Medium {
    // Given a string, sort it in decreasing order based on the frequency of characters.

    // Example 1:
    // Input: "tree"
    // Output: "eert"
    // Explanation:
    // 'e' appears twice while 'r' and 't' both appear once.
    // So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

    // Example 2:
    // Input: "cccaaa"
    // Output: "cccaaa"
    // Explanation:
    // Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
    // Note that "cacaca" is incorrect, as the same characters must be together.

    // Example 3:
    // Input: "Aabb"
    // Output: "bbAa"
    // Explanation:
    // "bbaA" is also a valid answer, but "Aabb" is incorrect.
    // Note that 'A' and 'a' are treated as two different characters.
    struct CharFrequency
    {
        // O(nlog(n))
        std::string frequencySort(std::string s)
        {
            std::string out{""};
            auto freq_map = std::unordered_map<char, int>{};
            auto freq_str = std::vector<std::string>{};

            // O(n)
            for (const auto& c : s) {
                if (auto it = freq_map.insert({c, 1}); !it.second) {
                    freq_map[c]++;
                }
            }

            // O(n) roughly
            for (const auto& m : freq_map) {
                std::string temp{""};

                for (int i = 0; i < m.second; i++)
                    temp.push_back(m.first);

                freq_str.emplace_back(temp);
            }

            // O(nlog(n))
            std::sort(
                freq_str.begin(),
                freq_str.end(),
                [](const std::string& a, const std::string& b) {
                    return a.length() > b.length();
                });

            // O(n)
            for (auto& s : freq_str)
                out.append(s);

            return out;
        }
    };
}  // namespace Leet::Medium
