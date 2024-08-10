#pragma once

#include <string>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

namespace Leet::Easy {
    // Given a string s, return the length of the longest substring between two equal
    // characters, excluding the two characters. If there is no such substring return -1.
    // A substring is a contiguous sequence of characters within a string.

    // Example 1:
    // Input: s = "aa"
    // Output: 0
    // Explanation: The optimal substring here is an empty substring between the two 'a's.

    // Example 2:
    // Input: s = "abca"
    // Output: 2
    // Explanation: The optimal substring here is "bc".

    // Example 3:
    // Input: s = "cbzxy"
    // Output: -1
    // Explanation: There are no characters that appear twice in s.

    // Constraints:
    // 1 <= s.length <= 300
    // s contains only lowercase English letters.
    struct LargestSubstringBetweenChars
    {
        int maxLengthBetweenEqualCharacters(std::string s)
        {
            if (s.length() < 3)
                return 0;

            unordered_map<char, vector<int>> charidx;
            int largest = -1;

            for (int i = 0; i < s.length(); i++) {
                charidx[s[i]].push_back(i);
            }

            for (auto &value : charidx) {
                vector<int> indices = value.second;

                if (indices.size() > 1) {
                    largest = std::max(largest, indices.back() - indices[0] - 1);
                }
            }

            return largest;
        }
    };
}  // namespace Leet::Easy