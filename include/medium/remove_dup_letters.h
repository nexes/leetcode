#pragma once

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

namespace Leet::Medium {
    // Given a string s, remove duplicate letters so that every letter appears once and
    // only once. You must make sure your result is the smallest in lexicographical order
    // among all possible results.

    // Example 1:
    // Input: s = "bcabc"
    // Output: "abc"

    // Example 2:
    // Input: s = "cbacdcbc"
    // Output: "acdb"

    // Constraints:
    // 1 <= s.length <= 104
    // s consists of lowercase English letters.
    struct RemoveDupLetters
    {
        string removeDuplicateLetters(string s)
        {
            // the string will act as our stack
            string result = "";
            unordered_map<char, int> dups;
            unordered_map<char, bool> seen;

            // check how many of this char there are
            for (char c : s)
                dups[c]++;

            for (char c : s) {
                dups[c]--;

                // if this char is in our string just continue
                if (seen[c])
                    continue;

                // the stack is mono increasing
                while (!result.empty() && c < result.back() && dups[result.back()] > 0) {
                    seen[result.back()] = false;
                    result.pop_back();
                }

                seen[c] = true;
                result.push_back(c);
            }

            return result;
        }
    };
}  // namespace Leet::Medium