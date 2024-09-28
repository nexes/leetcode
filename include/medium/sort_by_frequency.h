#pragma once

#include <queue>
#include <string>
#include <unordered_map>

namespace Leet::Medium {
    // Given a string, sort it in decreasing order based on the frequency of
    // characters.

    // Example 1:
    // Input: "tree"
    // Output: "eert"
    // Explanation:
    // 'e' appears twice while 'r' and 't' both appear once.
    // So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a
    // valid answer.

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
            std::string sortedStr = "";
            std::unordered_map<char, int> freqMap;
            std::priority_queue<std::pair<int, char>> freqQueue;

            // O(n)
            for (char c : s)
                freqMap[c]++;

            // O(nlog(n))
            for (auto [c, count] : freqMap)
                freqQueue.push({count, c});

            // O(nlog(n))
            while (!freqQueue.empty()) {
                auto [count, c] = freqQueue.top();
                freqQueue.pop();
                sortedStr.append(count, c);
            }

            return sortedStr;
        }
    };
}  // namespace Leet::Medium
